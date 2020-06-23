#include <iostream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ret="";
        int count = 0;
        int i = a.length()-1;
        int j = b.length()-1;
        while(i >=0 && j >= 0){
            count += ((a[i--]-48)+(b[j--]-48));
            if(count >= 2){
                ret.insert(0,1,(count-2)+48);
                count = 1;
            }else{
                ret.insert(0,1,(count+48));
                count = 0;
            }
        }

        while(i>=0){
            count += (a[i--]-48);
            if(count >= 2){
                ret.insert(0,1,(count-2)+48);
                count = 1;
            }else{
                ret.insert(0,1,(count+48));
                count = 0;
            }
        }

        while(j>=0){
            count += (b[j--]-48);
            if(count >= 2){
                ret.insert(0,1,(count-2)+48);
                count = 1;
            }else{
                ret.insert(0,1,(count+48));
                count = 0;
            }
        }

        if(count > 0){
            ret.insert(0,1,'1');
        }

        return ret;
    }
};

int main()
{
    string a = "1111", b = "1111";
    Solution t;
    cout<<t.addBinary(a,b);
}