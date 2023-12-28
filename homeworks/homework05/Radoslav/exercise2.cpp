#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    stack <int> st;
    int res = 0;
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
            int height = arr[st.top()];
            st.pop();
            int width;
            if (st.empty()){
                width = i;
            }
            else{
                width = i - st.top() - 1;
            }
            res = max(res, width * height);
        }
        st.push(i);
    }
    cout << res;
}
