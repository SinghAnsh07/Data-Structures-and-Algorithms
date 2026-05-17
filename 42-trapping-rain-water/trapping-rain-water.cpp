class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxleft(n), maxright(n);

        maxleft[0] = height[0];
        for(int i=1; i<n; i++){
            maxleft[i] = max(maxleft[i-1], height[i]);
        }

        maxright[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            maxright[i] = max(maxright[i + 1] , height[i]);
        }

        int water = 0;
        for(int i=0; i<n; i++){
            water += min(maxleft[i], maxright[i]) - height[i];
        }
        
        return water;
    }
};