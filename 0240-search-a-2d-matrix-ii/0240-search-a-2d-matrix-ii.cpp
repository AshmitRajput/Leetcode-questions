class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row  = matrix.size();
        int col = matrix[0].size();
        int rowind = 0;
        int colind = col-1;

        while(rowind<row && colind>=0){

            int ele = matrix[rowind][colind];

            if(ele == target)
            return 1;

            if(ele<target)
            rowind++;

            else
            colind--;
        }

        return 0;
    }
};