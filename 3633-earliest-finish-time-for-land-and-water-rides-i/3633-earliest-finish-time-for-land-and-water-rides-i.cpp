#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        int earliestTime = 2e9; 
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
               
                int finishLandA = landStartTime[i] + landDuration[i];
                int startWaterA = max(finishLandA, waterStartTime[j]);
                int totalTimeA = startWaterA + waterDuration[j];
                
               
                int finishWaterB = waterStartTime[j] + waterDuration[j];
                int startLandB = max(finishWaterB, landStartTime[i]);
                int totalTimeB = startLandB + landDuration[i];
              
                earliestTime = min({earliestTime, totalTimeA, totalTimeB});
            }
        }
        
        return earliestTime;
    }
};