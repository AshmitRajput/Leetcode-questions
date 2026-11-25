class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;
        for(string s : logs){
            if(s == "../")
                steps = max(0, steps-1);
            else if(s == "./") continue;
            else steps++;
        }
        return steps;
    }
};