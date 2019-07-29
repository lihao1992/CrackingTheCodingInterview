#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> index(256, -1);
        int finalLen = 0, m = 0;
        
        for(int i = 0; i < s.length(); ++i){
            m = max(index[s[i]] + 1, m);
            index[s[i]] = i;
            finalLen = max(finalLen, i-m+1);
        }
        return finalLen;
    }
};