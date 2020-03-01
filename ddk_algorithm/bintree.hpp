#pragma once
#include <memory>
#include <iostream>

namespace ddk{
template<typename T>
using traverse_func = void(*)(T& data);

enum traverse_type{
    preorder_traverse = 0,
    inorder_traverse,
    postorder_traverse
};

template<typename T, typename size = int>
class tree_node{
    private:
        size height;
        T value;
        tree_node<T,size>* l_child;
        tree_node<T,size>* r_child;
    public:
        void insert(T& val){
            if(val == value){
                return;
            }

            if(val < value){
                if(l_child){
                    l_child->insert(val);
                }else{
                    l_child = new tree_node<T,size>(val);
                }
            }else{
                if(r_child){
                    r_child->insert(val);
                }else{
                    r_child = new tree_node<T,size>(val);
                }
            }
        }
        void traverse(traverse_func<T> f, traverse_type t){
            if(preorder_traverse == t){
                f(value);
                if(l_child){
                    l_child->traverse(f,t);
                }
                if(r_child){
                    r_child->traverse(f,t);
                }
            }else if(inorder_traverse == t){
                if(l_child){
                    l_child->traverse(f,t);
                }
                f(value);
                if(r_child){
                    r_child->traverse(f,t);
                }
            }else if(postorder_traverse == t){
                if(l_child){
                    l_child->traverse(f,t);
                }
                if(r_child){
                    r_child->traverse(f,t);
                }
                f(value);
            }
        }

    public:
        tree_node(T& val){
            height = 0;
            value = val;
            l_child = nullptr;
            r_child = nullptr;
        }
        ~tree_node(){
            if(l_child){
                delete l_child;
            }

            if(r_child){
                delete r_child;
            }
        }
        tree_node(const tree_node<T,size>& obj) = delete;
        tree_node<T,size>& operator=(const tree_node<T,size>& obj) = delete;

};

template <typename T, typename size = int>
class Bintree{
    private:
        std::shared_ptr<tree_node<T,size>> tree;
    public:
        Bintree(T& val){ tree = std::make_shared<tree_node<T,size>>(val);}
        ~Bintree(){}
        Bintree(const Bintree& obj){
            tree = obj.tree;
        }
        Bintree& operator=(const Bintree& obj){
            if(this == &obj){
                return *this;
            }

            if(tree == obj.tree){
                return *this;
            }

            if(tree){
                delete tree;
            }

            tree = obj.tree;
            return *this;
        }
    public:
        void insert(T& val){
            tree->insert(val);
        }
        void traverse(traverse_func<T> f, traverse_type t){
            tree->traverse(f,t);
        }
}; 
}  