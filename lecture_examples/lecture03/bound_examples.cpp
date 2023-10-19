#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vect = {1, 4, 4, 4, 5, 5, 5, 5}; // списък с няколко елемента

    // upper_bound връща итератор към първия елемент по-голям от елемента
    auto upper1 = upper_bound(vect.begin(), vect.end(), 6);     // vect.end()
    auto upper2 = upper_bound(vect.begin(), vect.end(), 3);     // first 4
    auto upper3 = upper_bound(vect.begin(), vect.end(), 4);     // firsts 5

    // откриваме индекса в масива на горната граница
    int indexUpper1 = (upper1 - vect.begin());                  // (=8) ако няма по-голям елемент връща vector.end()
    int indexUpper2 = (upper2 - vect.begin());                  // (=1)
    int indexUpper3 = (upper3 - vect.begin());                  // (=4)

    // lower_bound връща итератор към първия елемент по-голям или равен на елемента
    auto low1 = lower_bound(vect.begin(), vect.end(), 6);
    auto low2 = lower_bound(vect.begin(), vect.end(), 3);
    auto low3 = lower_bound(vect.begin(), vect.end(), 4);

    // откриваме индекса в масива на долната граница
    int indexLower1 = low1 - vect.begin();                      // (=8) ако няма по-голям или равен елемент връща vector.end()
    int indexLower2 = low2 - vect.begin();                      // (=1)
    int indexLower3 = low3 - vect.begin();                      // (=1)

    return 0;
}
