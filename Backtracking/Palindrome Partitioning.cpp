https://www.interviewbit.com/problems/palindrome-partitioning/

vector<vector<string>>ans;

bool isPalindrome(string s) {
    int L = s.size();
    for(int i=0;i<L/2;i++) if(s[i] != s[L-1-i]) return false;
    return true;
}

void solve(string str, int s, int e, vector<string>opt) {
    if(s>=e) {
        ans.push_back(opt);
        return;
    }

    string curr;
    for(int i=s;i<e;i++) {
        curr.push_back(str[i]);
        if(isPalindrome(curr)) {
            opt.push_back(curr);
            solve(str, i+1, e, opt);
            opt.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    ans.clear();
    solve(A, 0, A.size(), {});
    return ans;
}
