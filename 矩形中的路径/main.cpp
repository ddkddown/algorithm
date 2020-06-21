class Solution {
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(vector<vector<char>>& board, vector<vector<int>>&vis, int i, int j, string& word, int idx){
        vis[i][j] = 1;
        if(idx == word.size()) return true;
        idx ++;
        for(auto xy : dir){
            int x = i + xy[0], y = j + xy[1];
            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || vis[x][y] || board[x][y] != word[idx - 1]) continue;
            else{
                if(dfs(board, vis, x, y, word, idx)) return true;
            }
        }
        vis[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(board[i][j] == word[0]){
                    if(dfs(board, vis, i, j, word, 1)) return true;
                }
            }
        }
        return false;
    }
};