#include <iostream>

using namespace std;

struct Coord {
    int x, y;
};

string a[25];
Coord c[625];
int ySize, xSize, i, j, k, n, x4, y4, ans;

void FillCoord() {
    int y, x;

    for (y = 0; y < ySize; y++) {
        for (x = 0; x < xSize; x++) {
            if (a[y][x] == 'x') {
                c[n].y = y;
                c[n].x = x;
                n++;
            }
        }
    }
}

int main() {
    cin >> ySize >> xSize;

    for (i = 0; i < ySize; i++) {
        cin >> a[i];
    }

    FillCoord();

    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                x4 = c[i].x + c[k].x - c[j].x;
                y4 = c[i].y + c[k].y - c[j].y;
                if (x4 >= 0 && x4 < xSize && y4 >= 0 && y4 < ySize) {
                    if (a[y4][x4] == 'x' &&
                        ((c[i].x - c[j].x) * (c[k].y - c[j].y) - (c[k].x - c[j].x) * (c[i].y - c[j].y)) != 0) {
                        ans++;
                    }
                }

            }
        }

    }

    cout << ans / 2 << endl;

    return 0;
}
