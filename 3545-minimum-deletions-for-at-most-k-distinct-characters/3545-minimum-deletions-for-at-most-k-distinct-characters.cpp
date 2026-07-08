#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minDeletion(std::string s, int k) {
       
        std::vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
       
        std::vector<int> counts;
        for (int count : freq) {
            if (count > 0) {
                counts.push_back(count);
            }
        }
        
      
        std::sort(counts.begin(), counts.end());
        
        int distinctChars = counts.size();
        int charsToRemove = distinctChars - k;
        

        if (charsToRemove <= 0) {
            return 0;
        }
        
       
        int deletions = 0;
        for (int i = 0; i < charsToRemove; ++i) {
            deletions += counts[i];
        }
        
        return deletions;
    }
};