class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {// TC : O(N)+O(N) = O(N) & SC : O(N)

        //N = s.size();
        
        vector<string>ans;
        unordered_map<string,int>m;// SC : O(N-9)*10 = O(N)

        for(int i=0;i+10<=s.size();i++){
            string DNA = s.substr(i,10);
            m[DNA]++;
        }

        for(auto it : m){// TC : O(N-9) = O(N)
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};