#pragma once

#include <iostream>

extern "C"{
#include <stdint.h>
}

using len_size = long;

namespace ddk {
template<typename T = int>
void exchange(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

/*
 *@brief: 选择排序
 *@param: arr 数组， len 数组长度，order false：降序 true：升序
 *@complex_rate: n^2
 */

template<typename T = int>
void selection_sort(T* arr = nullptr, len_size len = 0, bool order = false){
    if(!arr){
        return;
    }
    
    for (len_size i = 0; i < len; ++i) {
        len_size tmp = i;
        for (len_size j = i + 1; j < len; ++j) {
            if((arr[j] < arr[tmp] && order) ||
               (arr[j] > arr[tmp] && !order)){
                tmp = j;
            }
        }
        exchange(arr[i],arr[tmp]);
    }
}

/*
 *@brief: 插入排序
 *@param: arr 数组，len 数组长度，order false: 降序 true: 升序
 *@complex_rate:O(n^2),Ω(n)
 */
template<typename T = int>
void insertion_sort(T* arr = nullptr, len_size len = 0, bool order = false){
    if(!arr){
        return;
    }
    
    for(len_size i = 1; i < len; ++i){
        for (len_size j = i; j > 0 && ((arr[j-1] > arr[j] && order)||
                                    (arr[j-1] < arr[j] && !order)); --j) {
            exchange(arr[j], arr[j-1]);
        }
    }
}
/*
 *@brief 冒泡排序
 *@param arr 数组, len 数组长度 , order false: 降序 true: 升序
 *@complex_rate:O(N^2)
 */
template<typename T = int>
void bubble_sort(T* arr = nullptr, len_size len = 0, bool order = false){
	if(!arr){
		return;
	}

	for(len_size i = 0; i < len; ++i){
		for(len_size j = 1; j < len-i; ++j){
			if((arr[j] < arr[j-1] && order) ||
			(arr[j] > arr[j-1] && !order)){
				exchange(arr[j], arr[j-1]);
			}
		}

	}

}



/*
 *@brief: 希尔排序
 *@param: arr 数组，len 数组长度, order false: 降序 true: 升序
 *@complex_rate:
 */
template<typename T = int>
void shell_sort(T* arr = nullptr, len_size len = 0, bool order = false){
    if(!arr){
        return;
    }
    
    len_size h = 1;
    while (h < len/3) {
        h = 3*h + 1;
    }
    while (h >= 1) {
        for (len_size i = h; i < len; ++i) {
            for (len_size j = i; j >= h && ((arr[j-h] > arr[j] && order)||
                                    (arr[j-h] < arr[j] && !order)); j -= h) {
                exchange(arr[j-h], arr[j]);
            }
        }
        h /= 3;
    }
}

/*
 *@brief: 自顶向下原地归并排序
 *@param: arr 数组， lo 数组起点，hi 数组终点，order false：降序 true：升序
 *@return: true 排序成功 false 排序失败
 *@complex_rate:O(nlogn)
 */
namespace merge_sort{
    template<typename T = int>
    void merge(T* arr = nullptr, len_size lo = 0, len_size mid = 0,
                      len_size hi = 0, T* arr_tmp = nullptr ,bool order = false){
        len_size i = lo, j = mid+1;
    
    
        for(len_size k = lo; k <= hi; ++k){
            arr_tmp[k] = arr[k];
        }
    
        for(len_size k = lo; k <= hi; ++k){
            if(i > mid){
                arr[k] = arr_tmp[j++];
            }
            else if(j > hi){
                arr[k] = arr_tmp[i++];
            }
            else if((arr_tmp[i] < arr_tmp[j] && order) ||
                    (arr_tmp[i] > arr_tmp[j] && !order)){
                arr[k] = arr_tmp[i++];
            }
            else{
                arr[k] = arr_tmp[j++];
            }
        }
    }

    template<typename T = int>
    void sort(T* arr = nullptr, len_size lo = 0, len_size hi = 0,
                        T* arr_tmp = nullptr,bool order = false){
    
        if(hi <= lo){
            return;
        }
        if((hi - lo) <= 6){
            insertion_sort(arr,hi-lo+1,order);
        }
    
        len_size mid = lo + (hi - lo)/2;
        sort(arr, lo, mid, arr_tmp, order);
        sort(arr, mid+1, hi, arr_tmp, order);
        merge(arr, lo, mid, hi, arr_tmp, order);
        for(len_size i = lo; i<=hi; ++i){
            std::cout<<arr[i];
        }
        std::cout<<std::endl;
    
    }

    template<typename T = int>
    void merge_sort(T* arr = nullptr, len_size len = 0,bool order = false){
        try {
            T* arr_tmp = new T[len];
            sort(arr,0,len-1,arr_tmp,order);
        }catch(std::exception e){
            return;
        }
    }
}
/**
 * @breif 简单快速排序
 */
namespace quick_sort{
    template<typename T = int>
    bool less(T& a, T& b){
        return a<b?true:false;
    }

    template<typename T = int>
    int partition(T* arr = nullptr, int lo = 0, int hi = 0){
        //数组分为[lo...i-1],[i],[i+1...hi]
        int i = lo, j = hi+1;
        auto tmp = arr[lo];
        while(1){
            while(less(arr[++i], tmp)) if(i == hi) break;
            while(less(tmp, arr[--j])) if(j == lo) break;
            if(i >= j){
                break;
            }

            exchange(arr[i],arr[j]);
        }

        exchange(arr[lo],arr[j]);
        return j;
    }

    template<typename T = int>
    void sort(T* arr = nullptr, int lo = 0, int hi = 0){
        if(hi <= lo){
            return;
        }

        int j = partition(arr,lo,hi);
        sort(arr,lo,j-1);
        sort(arr,j+1,hi);
    }

    template<typename T = int>
    void quick_sort(T* arr = nullptr, len_size len = 0){
        sort(arr,0,len-1);
    }
}
}
