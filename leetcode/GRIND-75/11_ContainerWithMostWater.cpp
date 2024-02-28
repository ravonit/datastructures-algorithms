class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int vol = 0;
        while(l < r){
            vol = max(vol, (r-l) * min(height[l], height[r]));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return vol;
    }
};