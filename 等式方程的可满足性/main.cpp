class Solution {
private:
	int table[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	int find(int x){
		if(table[x] == x){
			return x;
		}
        table[x] = find(table[x]);
		return find(table[x]);
	}

	void unite(int x, int y){
		table[find(x)] = find(y);
	}
public:
	bool equationsPossible(vector<string>& equations) {
		for(const string& str : equations){
			int index1 = str[0] - 'a';
			int index2 = str[3] - 'a';

			if('=' == str[1]){
				unite(index1, index2);
			}
        }
        for(const string& str : equations){
            int index1 = str[0] - 'a';
            int index2 = str[3] - 'a';
			if('!' == str[1]){
				if(find(index1) == find(index2)){
					return false;
				}
			}
        }

        return true;
	}
};
