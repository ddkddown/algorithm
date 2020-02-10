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
 *@brief: 插入排序
 *@param: arr 数组， len 数组长度，order false：降序 true：升序
 *@complex_rate: n^2
 */

template<typename T = int>
void selection_sort(T* arr = nullptr, len_size len = 0, bool order = false){
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


}
