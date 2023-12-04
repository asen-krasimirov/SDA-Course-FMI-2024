#include <unordered_map>
#include <set>

using namespace std;

class FreqStack {
public:
    unordered_map<int, int> map;    // idx, val
    unordered_map<int, int> freq;   // val, freq
    set<pair<int, int>> s;          // freq, idx
    int x = 0;

    FreqStack() {
    }

    void push(int val) {
        map[x] = val;
        freq[val]++;
        s.insert({freq[val], x++});
    }

    int pop() {
        auto toPop = *s.rbegin();
        s.erase(toPop);

        int val = map[toPop.second];
        freq[val]--;;

        return val;
    }

};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
