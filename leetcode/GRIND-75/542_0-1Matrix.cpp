class Solution {
public:
    void bfs(queue<pair<int, int>> &q, vector<vector<int>> &result, int a, int b, int m, int n, int count){
        if(a < 0 || b < 0 || a >= m || b >= n || result[a][b] != -1){
            return;
        }
        q.push(make_pair(a, b));
        result[a][b] = count + 1;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int> (n, -1));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push(make_pair(i, j));
                    result[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            pair<int, int> temp = q.front();
            int a = temp.first;
            int b = temp.second;
            int count = result[a][b];
            q.pop();
            bfs(q, result, a-1, b, m, n, count);
            bfs(q, result, a+1, b, m, n, count);
            bfs(q, result, a, b-1, m, n, count);
            bfs(q, result, a, b+1, m, n, count);
        }
        return result;
    }   
};