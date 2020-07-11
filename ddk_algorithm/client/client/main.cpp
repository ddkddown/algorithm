//
//  main.cpp
//  client
//
//  Created by 董大宽 on 2020/3/5.
//  Copyright © 2020 董大宽. All rights reserved.
//

#include <iostream>
#include "sock.hpp"
int main(int argc, const char * argv[]) {
    std::string ip = "127.0.0.1";
    ddk::Socket_client<> a(ip,7796);
    a.connect_to_server();
    std::string mess = "abc";
    a.send(mess);
}
