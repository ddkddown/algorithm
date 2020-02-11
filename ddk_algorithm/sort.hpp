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

}
