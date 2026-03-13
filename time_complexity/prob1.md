### why its time complexity is  O(mlogn) ,and not O(logmn)?
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int h = matrix.size() - 1;

        while(l <= h){
            int mid = (l+h) / 2;

            if(binary_search(matrix[mid].begin(),matrix[mid].end(),target)) return true;
            else{
                if(target < matrix[mid][0]) h = mid - 1;
                else l = mid + 1;
            }
        }

        return false;
    }
};
```
