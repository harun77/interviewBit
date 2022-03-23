https://www.interviewbit.com/problems/word-ladder-i/

int Solution::solve(string A, string B, vector<string> &C) {
    set<string>dict;
    for(auto s:C) dict.insert(s);
    dict.insert(B);

    queue<pair<string, int>>Q;
    Q.push({ A, 1});

    while(!Q.empty()) {
        pair<string, int>curr = Q.front(); Q.pop();
        if(curr.first == B) return curr.second;

        for(char c='a'; c<='z'; c++) {
            for(int i=0; i<curr.first.size(); i++) {
                string next = curr.first;
                next[i]=c;
                if(dict.find(next) != dict.end()) {
                    Q.push({ next, curr.second+1 });
                    dict.erase(next);
                }
            }
        }
    }
    return 0;
}
