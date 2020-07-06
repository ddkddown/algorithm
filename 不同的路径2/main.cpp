#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()){
            return 0;
        }

        int i = 0;
        for(; i < obstacleGrid[0].size(); ++i){
            if(1 == obstacleGrid[0][i]){
                obstacleGrid[0][i] = 0;
                break;
            }

            obstacleGrid[0][i] = 1;
        }

        while(i < obstacleGrid[0].size()){
            obstacleGrid[0][i++] = 0;
        }

        i = 1;
        for(; i < obstacleGrid.size(); ++i){
            if(1 == obstacleGrid[i][0]){
                obstacleGrid[i][0] = 0;
                break;
            }

            obstacleGrid[i][0] = 1;
        }

        while(i < obstacleGrid.size()){
            obstacleGrid[i++][0] = 0;
        }

        for(int i = 1; i < obstacleGrid.size(); ++i){
            for(int j = 1; j < obstacleGrid.size(); ++j){
                if(1 == obstacleGrid[i][j]){
                    obstacleGrid[i][j] = 0;
                    continue;
                }

                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }

        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};

int main(){
    vector<vector<int>> map = {{0},{0}};
    Solution a;
    cout<<a.uniquePathsWithObstacles(map);
}