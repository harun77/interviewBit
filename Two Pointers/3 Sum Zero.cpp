https://www.interviewbit.com/problems/3-sum-zero/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    set<vector<int>>answer;
    vector<vector<int>>ret;
    int n = A.size();

    for(int i=0;i<n;i++) {
        long long first = A[i];
        int ptr1 = i+1;
        int ptr2 = n-1;
        while(ptr1<ptr2) {
            long long second = A[ptr1];
            long long third = A[ptr2];
            long long sum = first + second + third;
            if(sum == 0) {
                answer.insert({first, second, third});
                ++ptr1;
                --ptr2;
            } else if(sum<0) ++ptr1;
            else --ptr2;
        }
    }
    for(auto &it:answer) ret.push_back(it);
    return ret;
}
