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
    int a[] = {3,9,6,5,1,8,7,2,4,0,10,15,14,16,12,11,25};
    ddk::merge_sort(a,17,false);
        for(auto tmp : a){
            std::cout<<tmp;
        }
}
