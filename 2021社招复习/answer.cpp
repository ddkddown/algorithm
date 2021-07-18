#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    inline bool isStepYear(int y) {
        return (y%4==0&&y%100!=0)||(y%400==0);
    }

    int geTheMonth(int stepYear, int m) {
        if(0 == m) {
            return 0;
        }

        if(2 == m) {
            if(stepYear) return geTheMonth(stepYear, m-1) + 29;
            else return geTheMonth(stepYear, m-1) + 28;
        }

        return calendar[m-1] + geTheMonth(stepYear,m-1);
    }
public:
    int geTheDay(int y, int m, int d) {
        return geTheMonth(isStepYear(y), m-1) + d;
    }

private:
    static vector<int> calendar;
};

vector<int> Solution::calendar = {31,0,31,30,31,30,31,31,30,31,30,31};

int main() {
    Solution a;
    cout<<a.geTheDay(2016,1,3)<<endl<<a.geTheDay(2016,2,1)<<endl<<a.geTheDay(2021,7,9)<<endl;
    return 0;
}