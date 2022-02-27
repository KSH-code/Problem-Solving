#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    bool tmp_arr[13][13];
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            char c; cin >> c;
            tmp_arr[i][j] = c == 'O';
        }
    }

    int result = 1000;
    for (int z = 0; z <= 2047; z++) {
        int tmp = 0;
        bool arr[13][13]; for (int i = 0; i < 13; i++) for (int j = 0; j < 13; j++) arr[i][j] = tmp_arr[i][j];
        for (int i = 1; i <= 10; i++) {
            if (z & (1 << (i - 1))) {
                arr[1][i] = !arr[1][i];
                arr[2][i] = !arr[2][i];
                arr[1][i-1] = !arr[1][i-1];
                arr[1][i+1] = !arr[1][i+1];
                tmp++;
            }
        }

        for (int i = 2; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                if (arr[i - 1][j]) {
                    arr[i][j] = !arr[i][j];
                    arr[i-1][j] = !arr[i-1][j];
                    arr[i+1][j] = !arr[i+1][j];
                    arr[i][j-1] = !arr[i][j-1];
                    arr[i][j+1] = !arr[i][j+1];
                    tmp++;
                }
            }
        }

        bool complete = true;
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                if (arr[i][j]) complete = false;
            }
        }
        if (complete) result = min(result, tmp);
    }

    cout << (result < 1000 ? result : -1);
    return 0;
}
