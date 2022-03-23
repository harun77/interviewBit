https://www.interviewbit.com/problems/water-flow/

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

vector<vector<int>>grid;
int r, c;

bool isValid(int x, int y) {
    return x>=0 && y>=0 && x<r && y<c;
}

void visit(vector<vector<bool>>&visited, int x, int y) {
    visited[x][y] = 1;

    for(int i=0;i<4;i++) {
        int _x = x + dx[i];
        int _y = y + dy[i];

        if(isValid(_x, _y) && !visited[_x][_y]) {
            if(grid[_x][_y] >= grid[x][y]) visit(visited, _x, _y);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    grid = A;
    r = A.size();
    c = A[0].size();

    vector<vector<bool>>blue(r, vector<bool>(c, 0));
    vector<vector<bool>>red(r, vector<bool>(c, 0));

    for(int i=0;i<r;i++) visit(blue, i, 0);
    for(int i=0;i<c;i++) visit(blue, 0, i);

    for(int i=0;i<r;i++) visit(red, i, c-1);
    for(int i=0;i<c;i++) visit(red, r-1, i);

    int count = 0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(blue[i][j] && red[i][j]) {
                ++count;
            }
        }
    }
    return count;
}
