#pragma once
#include <memory>
#include <functional>
#include <iostream>

namespace ddk{
template<typename T>
using traverse_func = std::function<void(T& data)>;

enum traverse_type{
    preorder_traverse = 0,
    inorder_traverse,
    postorder_traverse
};

template<typename T, typename size = int>
class tree_node{
    private:
        using node = tree_node<T,size>;
        using p_node = tree_node<T,size>*;
        using ref_node = tree_node<T,size>&;
    private:
        size height;
        T value;
        p_node l_child;
        p_node r_child;
    private:
        T find_max_in_l_child(){
            if(nullptr == l_child){
                return value;
            }

            if((nullptr == l_child->r_child)||
                (nullptr == l_child->r_child &&
                 nullptr == l_child->l_child)){
                return l_child->value;
            }

            return l_child->r_child->find_max_in_l_child();
        }
    public:
        size get_height(){
            return height;
        }
        p_node find(T& obj){
            if(value == obj){
                return this;
            }else if(l_child && obj < value){
                return l_child->find(obj);
            }else if(r_child && obj > value){
                return r_child->find(obj);
            }
            return nullptr;
        }
        p_node delete_node(T& obj){
            if(obj < value){
                l_child = l_child->delete_node(obj);
                if(nullptr == l_child){
                    if(nullptr == r_child){
                        height = 0;
                    }else{
                        height = r_child->height+1;
                    }
                }else{
                    if(r_child){
                        height = (l_child->height>r_child->height?
                                    l_child->height:r_child->height)+1;
                    }else{
                        height = l_child->height+1;
                    }
                }
                return this;
            }

            if(obj > value){
                r_child = r_child->delete_node(obj);
                if(nullptr == r_child){
                    if(nullptr == l_child){
                        height = 0;
                    }else{
                        height = l_child->height+1;
                    }
                }else{
                    if(l_child){
                        height = (l_child->height>r_child->height?
                                    l_child->height:r_child->height)+1;
                    }else{
                        height = r_child->height+1;
                    }
                }
                return this;
            }

            if(nullptr == l_child && nullptr == r_child){
                delete this;
                return nullptr;
            }

            if(nullptr == r_child && l_child){
                auto tmp = l_child;
                l_child = nullptr;
                delete this;
                return tmp;
            }

            if(nullptr == l_child && r_child){
                auto tmp = r_child;
                r_child = nullptr;
                delete this;
                return tmp;
            }

            auto val = find_max_in_l_child();
            value = val;
            l_child = l_child->delete_node(val);
            if(nullptr == l_child){
                if(nullptr == r_child){
                    height = 0;
                }
                height = r_child->height;
            }else{
                if(nullptr == r_child){
                    height = l_child->height+1;
                }else{
                    height = (l_child->height>r_child->height?
                                l_child->height:r_child->height)+1;
                }
            }

            return this;
        }
        bool insert(T& val){
            if(val == value){
                return false;
            }

            if(val < value){
                if(l_child){
                    if(l_child->insert(val)){
                        if(r_child){
                            height = (l_child->height>r_child->height?
                                        l_child->height:r_child->height)+1;
                        }else{
                            height = l_child->height+1;
                        }
                        return true;
                    }
                }else{
                    l_child = new node(val);
                    ++(l_child->height);
                    height = l_child->height+1;
                    return true;
                }
            }else{
                if(r_child){
                    if(r_child->insert(val)){
                        if(l_child){
                            height = (l_child->height>r_child->height?
                                        l_child->height:r_child->height)+1;
                        }else{
                            height = r_child->height+1;
                        }
                        return true;
                    }
                }else{
                    r_child = new node(val);
                    ++(r_child->height);
                    height = r_child->height+1;
                    return true;
                }
            }
            return false;
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
        tree_node(const ref_node obj) = delete;
        ref_node operator=(const ref_node obj) = delete;

};

template <typename T, typename size = int>
class Bintree{
    private:
        using node = tree_node<T,size>;
        using p_node = tree_node<T,size>*;
        using ref_node = tree_node<T,size>&;
        using root_type = std::shared_ptr<node>;
    private:
        root_type tree;
    public:
        Bintree(T& val){ tree = std::make_shared<node>(val);}
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
        size get_height(){
            return tree->get_height();
        }
        p_node find(T& t){
            return tree->find(t);
        }
        void delete_node(T& t){
            tree->delete_node(t);
        }
        
        root_type get_root(){
            return tree;
        }
}; 
}  
