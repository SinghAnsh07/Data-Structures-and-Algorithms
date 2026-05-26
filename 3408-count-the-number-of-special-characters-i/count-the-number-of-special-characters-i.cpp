class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> s(word.begin(), word.end());
        int n = word.size();
        int count = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if( s.count(c) && s.count(c - 32)  ){
                count ++;
            }
        }
        return count;
    }
};