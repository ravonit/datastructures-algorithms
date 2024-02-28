class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int p = newInterval[0];
        int q = newInterval[1];
        int n = intervals.size();
        vector<vector<int>> result;
        for(int i=0; i<n; i++){
            int temp0 = intervals[i][0];
            int temp1 = intervals[i][1];
            if(p > temp1)
                result.push_back({temp0, temp1});
            else if(q < temp0){
                result.push_back({p, q});
                p = temp0;
                q = temp1;  
            }
            else{
                p = min(p, temp0);
                q = max(q, temp1);
            }
        }
        result.push_back({p, q});
        return result;
    }
};