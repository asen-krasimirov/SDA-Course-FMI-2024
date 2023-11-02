#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
//#include <list>

using namespace std;

class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        queue<int, deque<int>> sQueue = queue<int>(deque<int>(students.begin(), students.end()));
        deque<int> sStack = deque<int>(sandwiches.begin(), sandwiches.end());

        int unableToEat = 0;
        while (!sQueue.empty() && unableToEat < sQueue.size()) {
            int curStudent = sQueue.front();
            sQueue.pop();

            if (curStudent == sStack.front()) {
                sStack.pop_front();
                unableToEat = 0;
            } else {
                sQueue.push(curStudent);
                unableToEat++;
            }
        }

        return sQueue.size();
    }
};

int main() {
    Solution s;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};

    cout << s.countStudents(students, sandwiches);
}
