#include <iostream>
#include <vector>
using namespace std;
struct node{
    int x;
    int y;
};

class Solution{
public:
    static int orangeRotting(vector<vector<int>>& grid){
        int time = 0, count = 0;;
        vector<node> rotting;
        for(int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[i].size(); ++j) {
                if(1 == grid[i][j]){
                    ++count;
                    continue;
                }
                if(2 == grid[i][j]){
                    rotting.push_back({i,j});
                    continue;
                }
            }
        }
        
        while(!rotting.empty() && count){
            vector<node> new_rotting;
            new_rotting.empty();
            ++time;
            
            for(auto i = rotting.begin(); i != rotting.end(); ++i){
                if( i->x+1 < grid.size() && (1 == grid[i->x+1][i->y])){
                    grid[i->x+1][i->y] = 2;
                    --count;
                    new_rotting.push_back({i->x+1,i->y});
                }
                if(i->x-1 >= 0 && (1 == grid[i->x-1][i->y])){
                    grid[i->x-1][i->y] = 2;
                    --count;
                    new_rotting.push_back({i->x-1,i->y});
                }
                if(i->y+1 < grid[0].size() && (1 == grid[i->x][i->y+1])){
                    grid[i->x][i->y+1] = 2;
                    --count;
                    new_rotting.push_back({i->x,i->y+1});
                }
                if( i->y-1 >= 0 && (1 == grid[i->x][i->y-1])){
                    grid[i->x][i->y-1] = 2;
                    --count;
                    new_rotting.push_back({i->x,i->y-1});
                }
            }
            
            if(count && new_rotting.empty()){
                return -1;
            }
            rotting = new_rotting;
        }
        
        return time;
    }
};

int main(){
    vector<vector<int>> test = {{0,2}};
    cout<<Solution::orangeRotting(test);
}
