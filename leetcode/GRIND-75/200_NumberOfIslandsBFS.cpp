class Solution {
public:
    void bfs(vector<vector<char>>&grid, int i, int j, int m, int n, vector<vector<int>>&visited){
        visited[i][j] = 1;
        queue<pair<int, int>> q;
        vector<int> ridx = {-1, 0, 1, 0};
        vector<int> cidx = {0, 1, 0, -1};
        q.push({i, j});
        while(!q.empty()){
            int currI = q.front().first;
            int currJ = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int currX = currI + ridx[i];
                int currY = currJ + cidx[i];
                if(currX>=0 && currX<m && currY>=0 && currY<n && grid[currX][currY] == '1' &&
                !visited[currX][currY]){
                    visited[currX][currY] = 1;
                    q.push({currX, currY});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && visited[i][j] != 1){
                    count++;
                    bfs(grid, i, j, m, n, visited);
                }
            }
        }
        return count;
    }
};