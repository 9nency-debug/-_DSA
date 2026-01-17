#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // Base case

        int currentSum = 0;
        int result = 0;

        for (int num : nums) {
            currentSum += num;

            if (prefixCount.find(currentSum - k) != prefixCount.end()) {
                result += prefixCount[currentSum - k];
            }

            prefixCount[currentSum]++;
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << "Number of subarrays: "
         << solution.subarraySum(nums, k) << endl;

    return 0;
}