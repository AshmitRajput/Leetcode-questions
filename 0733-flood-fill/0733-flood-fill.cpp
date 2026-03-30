class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int old ,int color){
        image[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        if(sr-1>=0 && image[sr-1][sc]==old && image[sr-1][sc]!=color){
            dfs(image,sr-1,sc,old,color);
        }
        if(sr+1<n && image[sr+1][sc]==old && image[sr+1][sc]!=color){
            dfs(image,sr+1,sc,old,color);
        }
        if(sc-1>=0 && image[sr][sc-1]==old && image[sr][sc-1]!=color){
            dfs(image,sr,sc-1,old,color);
        }
        if(sc+1<m && image[sr][sc+1]==old && image[sr][sc+1]!=color){
            dfs(image,sr,sc+1,old,color);
        }


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        dfs(image,sr,sc,old,color);
        return image;
    }
};