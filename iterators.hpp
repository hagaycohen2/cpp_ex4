#pragma once
#include <queue>
#include <stack>
#include <vector>

#include "node.hpp"

using std::queue;
using std::stack;
using std::vector;
using std::size_t;

template <typename T, size_t k = 2>

class index_iterator {
   private:
    stack<node<T>*> s;
    size_t index;

    void push_children() {
        node<T>* current = s.top();
        s.pop();
        int i;
        for (i = current->getNumChildren() - 1; i >= 0 && i >= index; i--) {
            s.push(current->getChildren()[i]);
        }
        s.push(current);
        for (; i >= 0; i--) {
            s.push(current->getChildren()[i]);
        }
        if (s.top()->isvisited() == false) {
            s.top()->setVisited(true);
            push_children();
        }
    }

   public:
    index_iterator(node<T>* root, size_t index) : index(index) {
        if (index > k) {
            throw std::out_of_range("Index out of range");
        }
        s.push(root);
        root->setVisited(true);
        push_children();
    }
    T& operator*() {
        return s.top()->first->getData();
    }
    node<T>* operator->() {
        return s.top()->first;
    }
    index_iterator& operator++() {
        if (s.top() == nullptr) {
            return *this;
        }
        s.pop();
        if (s.top() != nullptr && s.top()->isvisited() == false) {
            s.top()->setVisited(true);
            push_children();
        }
        if(s.empty()){
            s.push(nullptr);
        }
        return *this;
    }
    bool operator==(const index_iterator& other) {
        return s.top() == other.s.top();
    }
    bool operator!=(const index_iterator& other) {
        return !(*this == other);
    }
};

template <typename T>

class bfs_iterator {
   private:
    queue<node<T>*> q;

   public:
    bfs_iterator(node<T>* root) {
        q.push(root);
    }
    T& operator*() {
        if (q.front() == nullptr) {
            throw std::out_of_range("End of queue");
        }
        return q.front()->getData();
    }
    node<T>* operator->() {
        return q.front();
    }
    bfs_iterator& operator++() {
        if (q.front() == nullptr) {
            return *this;
        }
        node<T>* current = q.front();
        q.pop();
        for (auto& child : current->getChildren()) {
            q.push(child);
        }
        if (q.empty()) {
            q.push(nullptr);
        }
        return *this;
    }
    bool operator==(const bfs_iterator& other) {
        return q.front() == other.q.front();
    }
    bool operator!=(const bfs_iterator& other) {
        return !(*this == other);
    }
};

template <typename T>

class dfs_iterator {
   private:
    stack<node<T>*> s;

   public:
    dfs_iterator(node<T>* root) {
        s.push(root);
    }
    T& operator*() {
        if (s.top() == nullptr) {
            throw std::out_of_range("End of stack");
        }
        return s.top()->getData();
    }
    node<T>* operator->() {
        return s.top();
    }
    dfs_iterator& operator++() {
        if (s.top() == nullptr) {
            return *this;
        }
        node<T>* current = s.top();
        s.pop();
        for (int i = current->getNumChildren() - 1; i >= 0; i--) {
            s.push(current->getChildren()[i]);
        }
        if (s.empty()) {
            s.push(nullptr);
        }
        return *this;
    }
    bool operator==(const dfs_iterator& other) {
        return s.top() == other.s.top();
    }
    bool operator!=(const dfs_iterator& other) {
        return !(*this == other);
    }
};

template <typename T>
class min_heap_iterator {
   private:
    vector<node<T>*> heap;
    public:
    min_heap_iterator(node<T>* root) {
        if(root == nullptr){
            heap.push_back(nullptr);
            return;
        }
        for(auto dfs = dfs_iterator<T>(root); *dfs != nullptr; ++dfs){
            heap.push_back(*dfs);
        }
        std::make_heap(heap.begin(), heap.end(), [](node<T>* a, node<T>* b) { return a->getData() > b->getData(); });
    }
    T& operator*() {
        if (heap[0] == nullptr) {
            throw std::out_of_range("End of heap");
        }
        return heap[0]->getData();
    }
    node<T>* operator->() {
        return heap[0];
    }
    min_heap_iterator& operator++() {
        if (heap[0] == nullptr) {
            return *this;
        }
        std::pop_heap(heap.begin(), heap.end(), [](node<T>* a, node<T>* b) { return a->getData() > b->getData(); });
        if(heap.empty()){
            heap.push_back(nullptr);
        }
        return *this;
    }
    bool operator==(const min_heap_iterator& other) {
        return heap[0] == other.heap[0];
    }
    bool operator!=(const min_heap_iterator& other) {
        return !(*this == other);
    }
};
    

        