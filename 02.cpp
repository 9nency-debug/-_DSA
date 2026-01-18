#include<iostream>
#include<unordered_map>
using namespace std;
class solution {
    public:
    int findPairs(int arr[], int n, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        for (auto it : freq) {
            int num = it.first;
            if (k > 0) {
                if (freq.find(num + k) != freq.end()) {
                    cout << "(" << num << "," << num + k << ")" << endl;
                    count++;
                }
            }
        }
        return count;
    }
};
int main() {
    solution sol;
    int arr[] = {3, 1, 4, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int result = sol.findPairs(arr, n, k);
    cout << "Number of unique k-diff pairs: " << result << endl;
    return 0;
}