// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

vector<int> Solution::getRow(int k) {
   vector<vector<int>>triangle;

   triangle.push_back({1});
   triangle.push_back({1, 1});

   for(int i=2; i<=k;i++) 
   {
       vector<int>now;
       int L=triangle[i-1].size();

       for(int j=0;j<L;j++) 
       {
          if(j==0 || j==L-1) now.push_back(triangle[i-1][j]);
          if(j+1<L) now.push_back(triangle[i-1][j] + triangle[i-1][j+1]);
       }
       triangle.push_back(now);
   }
   return triangle[k];
}
