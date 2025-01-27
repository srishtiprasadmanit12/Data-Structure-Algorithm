#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1), parent(n, -1);
    int maxLength = 0, maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            maxIndex = i;
        }
    }

    vector<int> lis;
    for (int i = maxIndex; i >= 0; i = parent[i]) {
        lis.push_back(arr[i]);
        if (parent[i] == -1) break;
    }

    reverse(lis.begin(), lis.end());

    cout << "Longest Increasing Subsequence: ";
    for (int i : lis) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    printLIS(arr);
    return 0;
}