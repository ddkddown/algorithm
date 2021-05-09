class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int j = 1;
        for(auto i = digits.end()-1; i >= digits.begin(); --i) {
            *i += j;
            if(*i >= 10) {
                j = 1;
                *i = *i%10;
                if(i == digits.begin()) {
                    digits.insert(digits.begin(), 1);
                }
            } else {
                j = 0;
            }
        }

        return digits;
    }
};