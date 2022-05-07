#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int a,b,c;
};

void solve(){
    int N;cin >>N;

    Node arr[N]; for (int i = 0; i < N; i++) cin >> arr[i].a >> arr[i].b >> arr[i].c;

    int points[1001][1001]; // STR, INT
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            points[i][j] = -1;
        }
    }

    bool cleared[1001][1001]; memset(cleared, 0, sizeof(cleared));

    cleared[1][0] = cleared[0][1] = points[1][0] = points[0][1] = 1;

    int result = 0;
    for (int STR = 1; STR <= 1000; STR++) {
        for (int INT = 1; INT <= 1000; INT++) {
            points[STR][INT] = 2-(STR+INT);

            int clear = 0;

            for (int i = 0; i < N; i++) {
                auto [a,b,c] = arr[i];
                if (a <= STR || b <= INT) {
                    points[STR][INT] += c;
                    clear++;
                }
            }

            if (
                (cleared[STR - 1][INT] && points[STR - 1][INT] > 0) ||
                (cleared[STR][INT - 1] && points[STR][INT - 1] > 0)
            ) {
                cleared[STR][INT] = true;
                result = max(result, clear);
            }
        }
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
