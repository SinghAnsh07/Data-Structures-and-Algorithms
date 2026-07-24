class Solution {
public:
    vector<int> countBits(int n) {

        // ye solution builtin function use krke hai, builtlin_popcount ->> this function returns the numbers of 1 bit
        // for any number so this is easy

        vector<int> result(n + 1);
        for(int i=0; i<n+1; i++){
            result[i] = __builtin_popcount(i);
        }
        return result;

        // now we do it without using the builtin function


    }
};