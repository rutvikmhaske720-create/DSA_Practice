#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
       
        int totalApples = 0;
        for (int a : apple) {
            totalApples += a;
        }
        

        std::sort(capacity.begin(), capacity.end(), std::greater<int>());
        
     
        int currentCapacity = 0;
        int boxesUsed = 0;
        
        for (int c : capacity) {
            currentCapacity += c;
            boxesUsed++;
    
            if (currentCapacity >= totalApples) {
                return boxesUsed;
            }
        }
        
        return boxesUsed; 
    }
};