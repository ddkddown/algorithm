class Solution{
    public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> s;

        for(int i = 0; i < n; ++i){
            while(!s.empty() && T[i] > T[s.top()]){
                auto tmp = s.top;
                ans[tmp] = i - tmp;
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }
}; 