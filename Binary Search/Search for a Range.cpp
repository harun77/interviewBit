https://www.interviewbit.com/problems/search-for-a-range/

int findIndex(vector<int>ara, int num, bool start=true) {
    int n=ara.size();
    int low=0, high=n-1, mid, index=-1;
    while(low<=high) {
        mid=(low+high)/2;
        if(num<ara[mid]) high=mid-1;
        else if(ara[mid]<num) low=mid+1;
        else {
            index=mid;
            if(start) high=mid-1;
            else low=mid+1;
        } 
    }
    return index;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int start=findIndex(A, B);
    int end=findIndex(A, B, false);
    return {start, end};
}
