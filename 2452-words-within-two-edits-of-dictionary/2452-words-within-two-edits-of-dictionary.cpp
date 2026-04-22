class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int l=queries[0].size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            string s=queries[i];
            for(int j=0;j<dictionary.size();j++){
                string d=dictionary[j];
                int count=0;
                for(int k=0;k<l;k++){
                    if(s[k]!=d[k]) count++;
                }
                if(count<=2){
                    ans.push_back(s);
                    break;
                }

            }

        }
        return ans;
    }
};