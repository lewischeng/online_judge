class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        int m = matrix.size();
        if (m < 1) return result;
        int n = matrix[0].size();
        if (n < 1) return result;
        vector<vector<bool> > canUse(m, vector<bool>(n, true));
        int i = 0, j = 0;
        int dir = 0; // 0: right, 1: down, 2: left, 3: up
        while (true) {
            if (!canUse[i][j])
        		break;
        	canUse[i][j] = false;
        	result.push_back(matrix[i][j]);
        	int lookupCount = 0;
        	bool dirSettled = false;
        	while (!dirSettled && lookupCount < 4) {
        		lookupCount++;
	        	switch (dir) {
	        	case 0:
	        		if (j == n - 1 || !canUse[i][j + 1]) {
	        			dir = 1;
	        			continue;
	        		} else {
	        			++j;
	        			dirSettled = true;
	        		}
	        		break;
	        	case 1:
	        		if (i == m - 1 || !canUse[i + 1][j]) {
	        			dir = 2;
	        			continue;
	        		} else {
	        			++i;
	        			dirSettled = true;
	        		}
	        		break;
	        	case 2:
	        		if (i == 0 || !canUse[i - 1][j]) {
	        			dir = 3;
	        			continue;
	        		} else {
	        			--i;
	        			dirSettled = true;
	        		}
	        		break;
	        	case 3:
	        		if (j == 0 || !canUse[i][j - 1]) {
	        			dir = 0;
	        			continue;
	        		} else {
	        			--j;
	        			dirSettled = true;
	        		}
	        	}
	        	if (lookupCount == 4)
	        		break;
        	}
        }
        return result;
    }
};