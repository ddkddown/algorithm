#pragma once
#include <iostream>
namespace ddk{
    template<typename T>
    struct _node{
        using pointer = T*;
        pointer index;

        _node(pointer i = nullptr){
            index = i;
        }

        _node& operator=(const _node& tmp){
            index = tmp.index;
        }

        void incr(){
            index++;
        }
    };

    template<class T, class Ref, class Ptr>
    class _iterator{
        public:
            using const_iterator = _iterator<T, const T&, const T*>;
            using iterator =  _iterator<T, T&, T*>;
            using self = _iterator<T, Ref, Ptr>;

            using value_type = T;
            using pointer = Ptr;
            using reference = Ref;
            using link_type = _node<T>;
            using size_type = long;
        
        private:
            link_type node;

        public:
            _iterator():node(nullptr){}
            _iterator(const link_type x){
                node = x;
            }
            _iterator(const _iterator& tmp){
                node = tmp.node;
            }
            _iterator& operator=(const _iterator& tmp){
                node = tmp.node;
                return *this;
            }

            bool operator== (const self& x)const{return node.index == x.node.index;}
            bool operator!= (const self& x)const{return node.index != x.node.index;}
            self& operator++(){
                node.incr();
                return *this;
            } 
            reference operator*(){return *(node.index);}
            pointer operator->(){return &(operator*());}
    };

    //默认最大堆, 0不存储元素
    template<typename T = int, bool order = true>
    class max_pq{
        public:
            using iterator = _iterator<T,T&,T*>;
        private:
            T* pq;
            long n;
            long pq_size;
            bool pq_order;
        private:
            bool less_or_more(long i, long j){
                return pq_order?pq[i] < pq[j]:pq[i] > pq[j];
            }

            void exch(long i, long j){
                auto tmp = pq[i];
                pq[i] = pq[j];
                pq[j] = tmp;
            }

            void swim(long i){
                while(i > 1 && less_or_more(i/2,i)){
                    exch(i/2, i);
                    i/=2;
                }
            }

            void sink(long i){
                while(2*i <= n){
                    auto j = 2*i;
                    if(j < n && less_or_more(j,j+1)) ++j;
                    if(!less_or_more(i,j)) break;
                    exch(i,j);
                    i = j;
                }
            }

        public:
            max_pq(const max_pq& data){
                pq = new T[data.pq_size];
                for(long i = 1; i < data.n; ++i){
                    pq[i] = data[i];
                }
                n = data.n;
                pq_order = data.pq_order;
                pq_size = data.pq_size;
            }
            max_pq& operator = (const max_pq& data){
                if(this == &data){
                    return *this;
                }

                if(pq){
                    delete[] pq;
                }

                pq = new T[data.pq_size];
                for(long i = 1; i < data.n; ++i){
                    pq[i] = data[i];
                }
                n = data.n;
                pq_order = data.pq_order;
                pq_size = data.pq_size;
                return *this;
            }

            ~max_pq(){
                if(pq){
                    delete[] pq;
                }
            }

            max_pq():pq(nullptr),n(0),pq_size(0),pq_order(order){}
            max_pq(long size = 0){
                pq_order = order;
                n = 0;
                pq = new T[size*2];
                pq_size = size;
            }

            max_pq(T* arr = nullptr, long arr_size = 0){
                pq_order = order;
                n = 0;
                pq = new T[arr_size*2];
                pq_size = arr_size;

                for(auto i = 0; i < arr_size; ++i){
                    insert(arr[i]);
                }
            }

            public:
                bool is_empty(){
                    return 0 == n;
                }

                bool is_full(){
                    return pq_size-1 == n;
                }

                long get_size(){
                    return n;
                }

                iterator begin(){
                    return _node<T>(&(pq[1]));
                }

                iterator end(){
                    auto tmp = &(pq[n]);
                    ++tmp;
                    return _node<T>(tmp);
                }
            
                bool insert(T data){
                    if(is_full()){
                        return false;
                    }
                    pq[++n] = data;
                    swim(n);
                    return true;
                }

                T del_top(){
                    T tmp = pq[1];
                    exch(1,n--);
                    sink(1);
                    return tmp;
                }
    };
}