//
//  main.cpp
//  test
//
//  Created by 董大宽 on 2020/2/10.
//  Copyright © 2020 董大宽. All rights reserved.
//

#include <iostream>
#include "sort.hpp"

int main(int argc, const char * argv[]) {
    int a[] = {3,1,2,9,0,8,7,6,6,4,4};
    ddk::selection_sort(a,11,true);
    for(auto tmp : a){
        std::cout<<tmp;
    }
}
