#pragma once
#include <iostream>

namespace ddk{

template <typename T = int>
class s_list{
    using list_node = struct s_list_node{ T val; s_list_node* next;};
    using p_node = list_node*;

private:
    p_node head = std::nullptr, tail = std::nullptr;
    int size;

private:
    void clear(){
        auto i = head->next;
        while(i != tail && i){
            auto tmp = i -> next;
            if(i) delete i;
            i = tmp;
        }

        size = 0;
    }

public:
    s_list(){
        try{
            head = new list_node(0, std::nullptr);
        }catch(const std::bad_alloc& e){
            std::cerr << e.what() << '\n';
            exit(-1);
        }

        try{
            tail = new list_node(0, std::nullptr);
        }catch(const std::bad_alloc& e){
            if(head) delete head;
            std::cerr << e.what() << '\n';
            exit(-1);
        }

            head->next = tail;
            size = 0;
            
    }

    ~s_list(){
        clear();
        delete head;
        delete tail;
    }

    s_list(const s_list& val){
        clear();
        auto v_begin = val->head->next, v_end = val->tail;
        auto front = head, tmp = head->next;

        while(v_begin != v_end){
            try{
                tmp = new list_node(v_begin->val,std::nullptr);
            }catch(const std::bad_alloc& e){
                clear();
                std::cerr << e.what() << '\n';
                exit(-1);
            }

            front->next = tmp;
            tmp = tmp->next;
            front = front->next;
            v_begin = v_begin->next;
        }

        front->next = tail;
        size = val->size;
    }

    int get_size(){return size;}

    void insert_front(T& val){
        p_node tmp = std::nullptr;
        try{
            tmp = new list_node(val, std::nullptr);
        }catch(const std::bad_alloc& e){
            std::cerr << e.what() << '\n';
            return;
        }

        auto next = head->next;
        head->next= tmp;
        tmp->next = next;

        ++size;
    }

    void push_back(T& val){
        p_node tmp = std::nullptr;
        try{
            tmp = new list_node(val, std::nullptr);
        }catch(const std::bad_alloc& e){
            std::cerr << e.what() << '\n';
            return;
        }

        auto next = head;
        while(next->next != tail){
            next = next->next;
        }

        next->next = tmp;
        tmp->next = tail;

        ++size;
    }

    void erase(T& del){
        auto tmp = head->next;
        auto front = head;
        while(tmp != tail){
            if(tmp->val != del){
                tmp = tmp->next;
                front = front->next;
                continue;
            }

            front->next = front->next->next;
            delete tmp;
            --size;
            return;
        }
    }

    p_node get_front(){
        if(size <= 0){
            return std::nullptr;
        }

        return head->next;
    }

    void pop_front(){
        if(size <= 0){
            return;
        }

        auto tmp = head->next;
        head->next = tmp->next;
        delete tmp;
        --size;
    }

    p_node get_back(){
        if(size <= 0){
            return std::nullptr;
        }

        auto tmp = head->next;
        while(tmp->next != tail){
            tmp = tmp->next;
        }

        return tmp;
    }

    void pop_back(){
        if(size <= 0){
            return;
        }

        auto front = head, tmp = head->next;
        while(tmp->next != tail){
            tmp = tmp->next;
            front = front->next;
        }

        front->next = tail;
        delete tmp;
        --size;
    }
};

template <typename T = int>
class d_list{
    using list_node = struct d_list_node{T val; d_list_node* prev, next;};
    using p_node = list_node*;

private:
    p_node head = std::nullptr, tail = std::nullptr;
    int size;

private:
    void clear(){
        auto i = head->next;
        while(i != tail && i){
            auto tmp = i -> next;
            if(i) delete i;
            i = tmp;
        }

        size = 0;
    }

public:
    d_list(){
        try{
            head = new list_node(0, std::nullptr, std::nullptr);
        }catch(const std::bad_alloc& e){
            std::cerr << e.what() << '\n';
            exit(-1);
        }

        try{
            head = new list_node(0, std::nullptr, std::nullptr);
        }catch(const std::bad_alloc& e){
            if(head) delete head;
            std::cerr << e.what() << '\n';
            exit(-1);
        }

        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    ~d_list(){
        clear();
        delete head;
        delete tail;
    }

    d_list(const d_list& val){
        clear();
        auto v_begin = val->head->next, v_end = val->tail;
        auto front = head, tmp = head->next;

        while(v_begin != v_end){
            try{
                tmp = new list_node(v_begin->val, front, std::nullptr);
            }catch(const std::bad_alloc& e){
                clear();
                std::cerr << e.what() << '\n';
                exit(-1);
            }

            front->next = tmp;
            tmp = tmp->next;
            front = front->next;
            v_begin = v_begin->next;
        }

        front->next = tail;
        tail->prev = front;
        size = val->size;
    }

    int get_size(){return size;}

    void insert_front(T& val){
        p_node tmp = std::nullptr;
        try{
            tmp = new list_node(val, head, head->next);
        }catch(const std::bad_alloc& e){
            std::cerr << e.what() << '\n';
            return;
        }

        head->next->prev = tmp;
        head->next = tmp;

        ++size;
    }

    void push_back(T& val){
        p_node tmp = std::nullptr;
        try{
            tmp = new list_node(val, tail->prev, tail);
        }catch(const std::bad_alloc& e){
            std::cerr << e.what() << '\n';
            return;
        }

        tail->prev->next = tmp;
        tail->prev = tmp;

        ++size;
    }

    void erase(T& del){
        auto tmp = head->next;
        while(tmp != tail){
            if(tmp->val != del){
                tmp = tmp->next;
                continue;
            }

            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;

            --size;

            return;
        }
    }

    p_node get_front(){
        if(size <= 0){
            return std::nullptr;
        }

        return head->next;
    }

    void pop_front(){
        if(size <= 0){
            return;
        }

        auto tmp = head->next;
        head->next = tmp->next;
        tmp->next->prev = head;
        delete tmp;

        --size;
    }

    p_node get_back(){
        if(size <= 0){
            return std::nullptr;
        }

        return tail->prev;
    }

    
    void pop_back(){
        if(size <= 0){
            return;
        }

        auto tmp = tail->prev;
        tail->prev = tmp->prev;
        tmp->prev->next = tail;
        delete tmp;

        --size;
    }

};

}
