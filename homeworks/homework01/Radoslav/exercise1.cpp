#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char word[100], symbol;
    int n,count=0;
    cin >> word;
    cin >> n;
    cin >> symbol;
    int length = strlen(word), a = n / length, b = n % length;
    for (int i = 0; i < length; i++) {
        if (word[i] == symbol) {
            count++;
        }
    }
    count*=a;
    for (int i = 0; i < b; i++) {
        if (word[i] == symbol) {
            count++;
        }
    }
    cout << count;
    return 0;
}
