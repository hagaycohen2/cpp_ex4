#pragma once
#include <vector>




template <typename T>

class node {
    private:
        T data;
        node<T>* parent;
        std::vector<node<T>*> children;
        bool visited ;

    public:
        node(T d){
            this->data = d;
            this->parent = nullptr;
            this->visited = false;
        }
        ~node(){
            for(auto child : this->children){
                delete child;
            }
        }
        T& getData(){
            return this->data;
        }
        const T& getData() const{
            return this->data;
        }
        void setData(T d){
            this->data = d;
        }
        node<T>* getParent(){
            return this->parent;
        }
        void setParent(node<T>* p){
            this->parent = p;
        }
        std::size_t getNumChildren(){
            return this->children.size();
        }
        std::vector<node<T>*> getChildren(){
            return this->children;
        }
        void addChild(node<T>* child){
            this->children.push_back(child);
        }
        bool isvisited(){
            return this->visited;
        }
        void setVisited(bool b = true){
            this->visited = b;
        }
        void removeChildren(){
            this->children.clear();
        }
        
};