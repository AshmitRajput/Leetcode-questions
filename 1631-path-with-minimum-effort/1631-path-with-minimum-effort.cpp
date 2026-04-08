class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});

        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1) return d;
            for(int i=0;i<4;i++){
                int nr=row+drow[i];
                int nc=col+dcol[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m){
                    int neweffort=max(abs(heights[row][col]-heights[nr][nc]),d);
                    if(neweffort<dist[nr][nc]){
                        dist[nr][nc]=neweffort;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }

        }
        return 0;

    }
};