#include <iostream>
using namespace std;

/**
 * @breif kmp算法
 * @input str原字符串， pat目标子串
 * @return 子串第一次出现的下标
 */ 
template<typename size = int>
size kmp(string&& str, string&& pat){
    //寻找最大相同前缀后缀，设置跳转状态
    size pat_len = pat.length(), str_len = str.length();
    int status[pat_len] = {-1,0};

    if(pat_len > str_len){
        return -1;
    }

    for(size i = 2; i < pat_len; ++i){
        string front = "", back = "";
        size x = -1, y = i;
        while((front == back) && --y >= 0 && ++x < i){
            front.push_back(pat[x]);
            back.insert(back.begin(),pat[y]);
        }
        status[i] = x;
    }

    //执行kmp步骤
    for(size i = 0; i < str_len;){
        size j = 0;
        for(; j < pat_len; ++j){
            if(str[i] != pat[j]){
                j = status[j];
                if(-1 == j){
                    ++i;
                    break;
                }
            }
            ++i;
        }

        if(j == pat_len){
            return i - pat_len;
        }
    }

    return -1;
}