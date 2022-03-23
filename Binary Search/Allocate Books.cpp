https://www.interviewbit.com/problems/allocate-books/

bool isOk(int maxPage, vector<int>pages, int student) {
    int n=pages.size();
    long long pageCount=0;
    int _student=1;
    for(int i=0;i<n;i++) {
        if(pages[i] > maxPage) return false;
        if(pageCount+pages[i] <= maxPage) {
            pageCount += pages[i];
        } else {
            pageCount = pages[i];
            _student++;
        }
    }
    return _student <= student;
}

int Solution::books(vector<int> &A, int B) {
    int n=A.size();
    if(n<B) return -1;

    long long totalPages = 0;
    for(int i=0;i<n;i++) totalPages += A[i];

    long long low=0, high=totalPages;
    long long mid, ans;

    while(low<=high) {
        mid=(low+high)/2;
        if(isOk(mid, A, B)) {
            ans=mid;
            high=mid-1;
        } else low=mid+1;
    }
    return ans;
}
