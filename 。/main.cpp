#include <iostream>
#include <vector>
using namespace std;
/*
class Solution{
    int getNum(int i, int j, vector<vector<int>>& triangle){
        if(i == (triangle.size() - 1)){
            return triangle[i][j];
        }

        int c = triangle[i][j];
        if(i == 0 && j == 0){
            int t1 = getNum(i+1, j, triangle);
            int t2 = getNum(i+1, j+1, triangle);

            return t1<=t2?c+t1:c+t2;
        }
        if(i == 0){
            if(c < triangle[i][j+1]){
                int t1 = getNum(i+1, j, triangle);
                int t2 = getNum(i+1, j+1, triangle);

                return t1<=t2?c+t1:c+t2;
            }
            else
            {
                return c + getNum(i+1, j, triangle);
            }
            
        }

        if(j == (triangle[i].size() - 1)){
            if(c < triangle[i][j-1]){
                int t1 = getNum(i+1, j, triangle);
                int t2 = getNum(i+1, j+1, triangle);

                return t1<=t2?c+t1:c+t2;
            }
            else
            {
                return c + getNum(i+1, j+1, triangle);
            }
            
        }

        if(c < triangle[i][j-1] && c < triangle[i][j+1]){
            int t1 = getNum(i+1, j, triangle);
            int t2 = getNum(i+1, j+1, triangle);

            return t1<=t2?c+t1:c+t2;
        }

        if(c < triangle[i][j-1]){
            return c + getNum(i+1, j, triangle);
        }

        if(c < triangle[i][j+1]){
            return c + getNum(i+1, j+1, triangle);
        }
        
        return INT32_MAX;

    }
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            if(triangle.empty()){
                return 0;
            }

            if(1 == triangle.size()){
                return triangle[0][0];
            }

            return getNum(0, 0, triangle);
        }
};
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for(int i = triangle.size() - 2; i >= 0; i --)
            for(int j = 0; j <= i; j ++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};