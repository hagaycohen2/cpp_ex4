#pragma once
#include <vector>



template <typename T>

class node {
    private:
        T data;
        node<T>* parent;
        std::vector<node<T>*> children;

    public:
        node(T data){
            this->data = data;
            this->parent = nullptr;
        }
        T getData(){
            return this->data;
        }
        void setData(T data){
            this->data = data;
        }
        node<T>* getParent(){
            return this->parent;
        }
        void setParent(node<T>* parent){
            this->parent = parent;
        }
        size_t getNumChildren(){
            return this->children.size();
        }
        std::vector<node<T>*> getChildren(){
            return this->children;
        }
        void addChild(node<T>* child){
            this->children.push_back(child);
        }
};