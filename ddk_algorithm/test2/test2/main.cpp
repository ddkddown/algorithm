/*#include "ssl_sock.hpp"
using namespace std;
using namespace ddk;
int main(){
    std::string cert = "./cert.pem";
    std::string privkey = "./privkey.pem";
    
    Ssl_server<> test(cert,privkey,"127.0.0.1",7796);
    test.start_ssl_server();
}*/
#include "ssl_sock.hpp"
using namespace std;
using namespace ddk;
/*
int main(){
    Ssl_client<>test("127.0.0.1",7796);
    test.ssl_connect_to_server();
    std::string buf = "123456";
    test.send(buf);
    test.close_connect();
}
*/
int main(){
    Socket_server<> a("127.0.0.1",7796);
    a.start_server();
    auto t=a.get_client_fd();
    a.recv(3, t);
}
