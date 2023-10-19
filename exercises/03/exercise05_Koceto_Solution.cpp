#include <bits/stdc++.h>
using namespace std;

vector<int> printers;
long long lists;

bool isEnoughTimeToPrintAllLists(long long time) {
    long long sum = 0, size = printers.size();

    for (int i = 0; i < size; i++) {
        sum += time / printers[i];
        if (sum >= lists) return true;
    }

    return false;
}

void binarySearch(long long& maxTimeForPrintingAllLists)
{
    long long  l = 0, r = maxTimeForPrintingAllLists;
    while (l <= r) {
        long long m = l + (r - l) / 2;

        if (isEnoughTimeToPrintAllLists(m)) {
            maxTimeForPrintingAllLists = m;
            r = m - 1;
        }
        else l = m + 1;
    }

}
int main() {
    long long numberOfPrinters;
    cin >> lists >> numberOfPrinters;
    for (int i = 0; i < numberOfPrinters; i++) {
        int curPrinter;
        cin >> curPrinter;
        printers.push_back(curPrinter);
    }

    sort(printers.begin(), printers.end());
    long long maxTimeForPrintingAllLists = lists * printers[numberOfPrinters - 1];

    binarySearch(maxTimeForPrintingAllLists);
    cout << maxTimeForPrintingAllLists;
    return 0;
}
