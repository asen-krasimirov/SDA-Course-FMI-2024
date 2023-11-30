#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> like;
        unordered_map<int, int> likedBy;

        for (int i = 1; i <= n; ++i) {
            like[i] = 0;
            likedBy[i] = 0;
        }

        for (vector<int> pair : trust) {
            like[pair[0]]++;
            likedBy[pair[1]]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (like[i] == 0 && likedBy[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};
