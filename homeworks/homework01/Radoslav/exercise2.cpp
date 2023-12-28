#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> a;
    vector<int> b;
    vector<string> names;
    for (int i = 0; i < t; i++) {
        int num1,num2;
        cin >> num1>> num2;
        a.push_back(num1);
        b.push_back(num2);
         string name;
        cin >> name;
        names.push_back(name);
    }
    for (int i = 0; i < t; i++) {
        int arr[26]{0};
        for (int j = 0; j < a[i]; j++) {
            if (isupper(names[i][j])) {
                arr[names[i][j] - 'A']++;
            }
        }
        for (int j = 0; j < 26; j++) {
            if (arr[j] >= b[i]) cout << char(j + 'A');
        }
        cout << endl;
    }
}
