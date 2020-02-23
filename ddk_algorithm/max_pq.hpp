#pragma once
#include <iostream>
namespace ddk{
    //默认最大堆, 0不存储元素
    template<typename T = int, bool order = true>
    class max_pq{
        private:
            T* pq;
            long n;
            long size;
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
                pq = new T[data.size];
                for(long i = 1; i < data.n; ++i){
                    pq[i] = data[i];
                }
                n = data.n;
                pq_order = data.pq_order;
                size = data.size;
            }
            max_pq& operator = (const max_pq& data){
                if(this == &data){
                    return *this;
                }

                if(pq){
                    delete[] pq;
                }

                pq = new T[data.size];
                for(long i = 1; i < data.n; ++i){
                    pq[i] = data[i];
                }
                n = data.n;
                pq_order = data.pq_order;
                size = data.size;
                return *this;
            }

            ~max_pq(){
                if(pq){
                    delete[] pq;
                }
            }

            max_pq():pq(nullptr),n(0),size(0),pq_order(order){}
            max_pq(long pq_size){
                max_pq();
                pq = new T[pq_size];
                size = pq_size;
            }

            public:
                bool is_empty(){
                    return 0 == n;
                }
                bool is_full(){
                    return size-1 == n;
                }
                long pq_size(){
                    return size;
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