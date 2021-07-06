//
//  main.cpp
//  test4
//
//  Created by 董大宽 on 2020/3/9.
//  Copyright © 2020 董大宽. All rights reserved.
//
#include "ssl_sock.hpp"
using namespace std;
using namespace ddk;
int main(){
    std::string cert = "./cert.pem";
    std::string privkey = "./privkey.pem";
    
    Ssl_server<> test(cert,privkey,"127.0.0.1",7799);
    test.start_ssl_server();
    auto t =test.get_ssl_client();
    cout<<test.recv(6, t.ssl);
    test.close_ssl_client(t);
}
