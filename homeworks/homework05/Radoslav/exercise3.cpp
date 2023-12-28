#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int days = 0;
    stack<pair<int, int>> st;

    for (int curr : arr) {
        int daysToDie = 1;

        while (!st.empty() && curr <= st.top().first) {
            int prevDays = st.top().second;
            st.pop();
            daysToDie = max(daysToDie, prevDays + 1);
        }

        if (!st.empty()) {
            days = max(days, daysToDie);
        } else {
            daysToDie = 0;
        }
        pair<int,int> tempPair{curr,daysToDie};
        st.push(tempPair);
    }
    
    cout<<days;
}
