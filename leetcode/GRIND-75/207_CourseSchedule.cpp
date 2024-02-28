class Solution {
    public:
    bool checkCycle(int course, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> & adj){
        vis[course] = 1;
        pathVis[course] = 1;
        for(auto it: adj[course]){
            if(!vis[it]){
                if(checkCycle(it, vis, pathVis, adj))
                    return true;
            }
            else if(pathVis[it] == 1)
                return true;
        }
        pathVis[course] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(vector<int> &temp: prerequisites){
            adj[temp[0]].push_back(temp[1]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(checkCycle(i, vis, pathVis, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};