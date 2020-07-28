class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto rows = grid.size();
        auto cols = grid[0].size();
        vector<int> dp(cols, grid[0][0]);
        for (int i = 1; i < cols; ++i)
            dp[i] = grid[0][i] + dp[i - 1];
        for (int i = 1; i < rows; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < cols; ++j) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
        return *dp.rbegin(); 
    }
};

作者：nullptrh
链接：https://leetcode-cn.com/problems/minimum-path-sum/solution/dong-tai-gui-hua-shi-jian-fu-za-du-omnkong-jian--2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。