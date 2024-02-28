class Solution {
public:

    void dfs(vector<vector<int>>& image, vector<vector<bool>> visited, int sr, int sc,int color, int oldColor, int m, int n){
        if(sr < 0 || sr >= m)
            return;
        if(sc < 0 || sc >= n)
            return;
        if(visited[sr][sc] == true)
            return;
        if(image[sr][sc] != oldColor)
            return;
        visited[sr][sc] = true;
        image[sr][sc] = color;
        dfs(image, visited, sr+1, sc, color, oldColor, m, n);
        dfs(image, visited, sr-1, sc, color, oldColor, m, n);
        dfs(image, visited, sr, sc+1, color, oldColor, m, n);
        dfs(image, visited, sr, sc-1, color, oldColor, m, n);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int oldColor = image[sr][sc];
        dfs(image, visited, sr, sc, color, oldColor, m, n);

        return image;
        
    }
};