https://www.interviewbit.com/problems/word-break-ii/

vector<string>ans;

void solve(string str, int s, int e, set<string>dict, string option) {
    if(s>=e) {
        ans.push_back(option);
        return;
    }
    string curr;
    for(int i=s;i<e;i++) {
        curr.push_back(str[i]);
        if(dict.find(curr) != dict.end()) {
            if(option.size()) solve(str, i+1, e, dict, option+" "+curr);
            else solve(str, i+1, e, dict, curr);
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    set<string>dict;
    for(auto s:B) dict.insert(s);
    ans.clear();
    solve(A, 0, A.size(), dict, "");
    return ans;
}
