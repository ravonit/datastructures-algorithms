bool compare_dist(pair<vector<int>, int>p1, pair<vector<int>, int>p2){
        return p1.second < p2.second;
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int m = points.size();
        vector<vector<int>> result;
        vector<pair<vector<int>, int>> mp;
        for(vector<int>temp: points){
            int dist = temp[0]*temp[0] + temp[1]*temp[1];
            mp.push_back(make_pair(temp, dist));
        }
        sort(mp.begin(), mp.end(), compare_dist);
        for(int i=0; i<k;  i++){
            result.push_back(mp[i].first);
        } 
        return result;
    }
};