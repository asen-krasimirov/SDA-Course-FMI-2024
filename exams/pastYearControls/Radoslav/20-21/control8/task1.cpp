#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& weights, int target, int end) {
    int left = 0;
    int right = end - 1;

    while (left < right) {
        int current_sum = weights[left] + weights[right];
        if (current_sum == target) {
            return true;
        }
        else if (current_sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    for (int i = n - 1; i >= 2; i--) {
        if (check(weights, weights[i], i)) {
            cout << "true";
            return 0;
        }
    }

    cout << "false";
    return 0;
}

