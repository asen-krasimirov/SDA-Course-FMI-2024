#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
   int n, b;
    cin >> n >> b;

    vector<int> arr(n);
    int ik=-1;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] == b) {
            ik = i;
        }
    }

    int idx, res = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] == b) {idx = i; break;}
    vector<int> left(idx+1), right(n-idx);
    for(int i = 1; i < idx+1; i++){
        left[i] = left[i-1]+(arr[idx-i]>b)-(arr[idx-i]<b);
    }
    for(int i = 1; i < n-idx; i++){
        right[i] = right[i-1]+(arr[idx+i]>b)-(arr[idx+i]<b);
    }
    map<int, int> m;
    for(auto i : left){
        m[i]++;
    }
    for(auto i : right){
        if(m.count(-i)) 
        {
            res += m[-i];
        }
    }
    cout << res;
    return 0;
}
