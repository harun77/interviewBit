https://www.interviewbit.com/problems/word-ladder-ii/

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    set<string>st;
    for(auto s:dict) st.insert(s);
    st.insert(end);

    queue<vector<string>>Q;
    Q.push({ start });
    vector<vector<string>>ans;
    bool found = false;

    while(!Q.empty()) {
        int L = Q.size();
        vector<string>remove;
        while(L--) {
            vector<string>curr = Q.front(); Q.pop();
            string top = curr[curr.size()-1];

            if(top==end) {
                ans.push_back(curr);
                found = true;
            }
            int n = top.size(); 
            for(char c='a'; c<='z'; c++) {
                for(int i=0;i<n;i++) {
                    string next = top;
                    next[i] = c;
                    if(st.find(next) != st.end()) {
                        curr.push_back(next);
                        Q.push(curr);
                        curr.pop_back();
                        remove.push_back(next);
                    }
                }
            }
        }
        for(auto x: remove) st.erase(x);
        if(found) break;
    }
    return ans; 
}
