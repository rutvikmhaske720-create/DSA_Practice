#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
       
        unordered_map<string, int> priorityMap = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        
        vector<pair<int, string>> validCoupons;
        
        for (int i = 0; i < code.size(); ++i) {
            if (!isActive[i]) continue;
            
            if (priorityMap.find(businessLine[i]) == priorityMap.end()) continue;
            
            if (code[i].empty()) continue;
            
           
            bool isValidCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    isValidCode = false;
                    break;
                }
            }
            
          
            if (isValidCode) {
                validCoupons.push_back({priorityMap[businessLine[i]], code[i]});
            }
        }
        
       
        sort(validCoupons.begin(), validCoupons.end());
        
       
        vector<string> result;
        for (const auto& coupon : validCoupons) {
            result.push_back(coupon.second);
        }
        
        return result;
    }
};