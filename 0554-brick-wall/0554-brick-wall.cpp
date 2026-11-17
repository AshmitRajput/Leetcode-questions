class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> mp;
        for(auto &row : wall){
            long long sum = 0;
            for(int i=0; i<row.size()-1; i++){
                sum = sum + row[i];
                mp[sum]++;
            }
        }
        int maxEdges = 0;
        for (auto &p : mp) {
            maxEdges = max(maxEdges, p.second);
        }
        return wall.size()-maxEdges;
    }
};