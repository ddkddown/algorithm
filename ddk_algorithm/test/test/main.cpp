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
    double a[] = {3.5,1.0,2.3,9.7,0.3,8.6,7.2,6.1,6.2,4.7,4.4};
    ddk::shell_sort(a,11,true);
    for(auto tmp : a){
        std::cout<<tmp;
    }
}
