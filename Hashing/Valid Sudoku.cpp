https://www.interviewbit.com/problems/valid-sudoku/

int Solution::isValidSudoku(const vector<string> &A) {
    set<char>rowValue[9], colValue[9], boxValue[3][3];
    int rowCount[9] = {0}, colCount[9] = {0}, boxCount[3][3] = {0};
    int r=A.size();
    int c=A[0].size();

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            char c=A[i][j];
            if(c=='.') continue;
            rowValue[i].insert(c);
            colValue[j].insert(c);
            boxValue[i/3][j/3].insert(c);

            ++rowCount[i];
            ++colCount[j];
            ++boxCount[i/3][j/3];
        }
    }
    int isValid = 1;
    for(int i=0;i<r;i++) if(rowCount[i] != rowValue[i].size()) isValid = 0;
    for(int i=0;i<c;i++) if(colCount[i] != colValue[i].size()) isValid = 0;
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(boxCount[i][j] != boxValue[i][j].size()) isValid = 0;

    return isValid;
}
