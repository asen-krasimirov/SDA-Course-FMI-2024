#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> sortedSquares(vector<int> &nums) {
    vector<int> sortedSquares;

    for (int i = 0; i < sortedSquares.size(); ++i) {
        sortedSquares[i] = pow(nums[i], 2);
    }

    sort(sortedSquares.begin(), sortedSquares.end());


    return sortedSquares;
}

int main() {


    return 0;
}