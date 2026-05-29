#include <iostream>
using namespace std;

int main() {

    const int INF = 9999;

    int d[4][4] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    int n = 4;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }

    return 0;
}