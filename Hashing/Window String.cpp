https://www.interviewbit.com/problems/window-string/

string Solution::minWindow(string A, string B) {
  map<char, int>need, have;
  for(auto c:B) need[c]++;

  int n = A.size(), m = B.size();
  int matchCount = 0;
  int i=-1, j=-1;
  int s = -1, e;

  while(i<n && j<n) {
      while(j<n && matchCount < m) {
          ++j;
          if(have[A[j]] < need[A[j]]) ++matchCount;
          have[A[j]]++;
      }

      while(i<n && matchCount >= m) {
          ++i;
          if(have[A[i]] <= need[A[i]]) --matchCount;
          have[A[i]]--;
          if(s == -1 || e-s>j-i) s=i, e=j;
      }
  }
  return s == -1 ? "" : A.substr(s, e-s+1);
}
