// LeetCode 525: Contiguous Array
// Approach: Prefix Sum + HashMap
// Time Complexity: O(n)
// Space Complexity: O(n)



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;

        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Convert 0 to -1 so equal 0s and 1s give sum = 0

            sum += (nums[i] == 0 ? -1 : 1);

            if (firstIndex.find(sum) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[sum]);
            } else {
                firstIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
