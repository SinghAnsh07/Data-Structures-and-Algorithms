class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;

        int left =0;
        int ans =0;

        int n = fruits.size();
        
        for(int i=0; i<n; i++){
            freq[fruits[i]]++;
            while(freq.size() > 2){
                freq[fruits[left]]--;

                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }

                left++;
            }

            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};