class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list banayenge
        // adj[u] -> kaun kaun se course depend karte hain u par
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            // v pehle karna padega tab u kar sakte hain
            adj[v].push_back(u);
        }
        // indegree array -> kitne prerequisites hain har course ke
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){

            for(auto it : adj[i]){

                indegree[it]++;
            }
        }
        // queue for Kahn's Algorithm (BFS Topological Sort)
        queue<int> q;
        // jinka indegree 0 hai wo pehle kiye ja sakte hain
        for(int i = 0; i < numCourses; i++){

            if(indegree[i] == 0){

                q.push(i);
            }
        }
        int count = 0; // kitne course complete hue
        // Kahn's Algorithm start
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            // neighbours ka indegree kam karo
            for(auto it : adj[node]){

                indegree[it]--;

                if(indegree[it] == 0){

                    q.push(it);
                }
            }
        }
        // agar saare course complete ho gaye
        // to cycle nahi hai
        if(count == numCourses){
            return true;
        }
        // warna cycle hai
        return false;
    }    
};