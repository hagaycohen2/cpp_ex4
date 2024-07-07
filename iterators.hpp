/**
 * Author: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

#pragma once
#include <queue>
#include <stack>
#include <vector>

#include "node.hpp"

using std::queue;
using std::size_t;
using std::stack;
using std::vector;
using std::cout;
using std::endl;

template <typename T, size_t k = 2>

class index_iterator {
   private:
    stack<node<T>*> s;
    size_t index;

    void push_children() {
        node<T>* current = s.top();
        vector<node<T>*> children = current->getChildren();
        s.pop();
        int i;
        for (i = current->getNumChildren() - 1; i >= 0 && i >= index; i--) {
            children[i]->setVisited(false);
            s.push(children[i]);
        }
        s.push(current);
        for (; i >= 0; i--) {
            children[i]->setVisited(false);
            s.push(children[i]);
        }
        if (s.top()->isvisited() == false && s.top()->getNumChildren() > 0){
            s.top()->setVisited();
            push_children();
        }
    }

   public:
    index_iterator(node<T>* root, size_t index) : index(index) {
        if(root == nullptr){
            s.push(nullptr);
            return;
        }
        if (index > k) {
            throw std::out_of_range("Index out of range");
        }
        s.push(nullptr);
        s.push(root);
        root->setVisited();
        push_children();
    }
    T& operator*() {
        return s.top()->getData();
    }
    node<T>* operator->() {
        return s.top()->getData();
    }
    index_iterator& operator++() {
        if (s.top() == nullptr) {
            return *this;
        }
        s.pop();
        if(s.top() == nullptr){
            return *this;
        }
        if (s.top()->isvisited() == false) {
            s.top()->setVisited();
            push_children();
        }
        if (s.empty()) {
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
    int index;

   public:
    min_heap_iterator(node<T>* root) {
        if (root == nullptr) {
            heap.push_back(nullptr);
            return;
        }
        for (auto bfs = bfs_iterator<T>(root); bfs != bfs_iterator<T>(nullptr); ++bfs) {
            heap.push_back(bfs.operator->());
        }
        std::make_heap(heap.begin(), heap.end(), [](node<T>* a, node<T>* b) { return a->getData() > b->getData(); });
        index = 0;
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
        if(index == heap.size() - 1){
            heap[0] = nullptr;
            return *this;
        }
        std::pop_heap(heap.begin(), heap.end()-index, [](node<T>* a, node<T>* b) { return a->getData() > b->getData(); });
        if (heap.empty()) {
            heap.push_back(nullptr);
        }
        index++;
        return *this;
    }
    bool operator==(const min_heap_iterator& other) {
        return heap[0] == other.heap[0];
    }
    bool operator!=(const min_heap_iterator& other) {
        return !(*this == other);
    }
};
