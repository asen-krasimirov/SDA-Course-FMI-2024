#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> um;
        vector<string> ans;

        string cur;

        for (int i = 0; i < s.size(); ++i) {
            cur.push_back(s[i]);
            if (cur.size() == 10) {
                um[cur]++;

                if (um[cur] == 2) {
                    ans.push_back(cur);
                }

                cur.erase(0, 1);
            }
        }

        return ans;
    }
};
