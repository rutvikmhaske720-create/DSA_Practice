class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        
        auto getReflection = [](int n) {
            int reflection = 0;
            while (n > 0) {
               
                reflection = (reflection << 1) | (n & 1);
                
                n >>= 1;
            }
            return reflection;
        };
        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int refA = getReflection(a);
            int refB = getReflection(b);
            
           
            if (refA == refB) {
                return a < b;
            }
            return refA < refB;
        });
        
        return nums;
    }
};