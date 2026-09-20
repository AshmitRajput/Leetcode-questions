
void backtracking(int& ans,unordered_map<int,int>& left,unordered_map<int,int>& lowerDiagonal,unordered_map<int,int>& upperDiagonal,int& n,int col){
    if( col == n){
        ans++;
        return;
    }

    for(int row = 0; row < n; row++){
        if(left[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[row-col] == 0){
            // mark the maps 
            left[row]++; lowerDiagonal[row+col]++ ; upperDiagonal[row-col]++;
            // move to next column
            backtracking(ans,left,lowerDiagonal,upperDiagonal,n,col+1);
            // unmark the maps 
            left[row] -- ; lowerDiagonal[row+col] -- ; upperDiagonal[row-col] -- ;
        }
    }
}

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        unordered_map<int,int> left;
        unordered_map<int,int> lowerDiagonal; 
        unordered_map<int,int> upperDiagonal;
        backtracking(ans,left,lowerDiagonal,upperDiagonal,n,0);
        return ans;
    }
};