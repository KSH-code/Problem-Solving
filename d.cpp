#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    ll arr[N][N];

    ll total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            total += arr[i][j];
        }
    }

    ll result = -1e18;
    for (int i = 0; i < (1<<N); i++) {
        bool checked[N][N]; memset(checked, 0, sizeof(checked));
        for (int r = 0; r < N; r++) {
            if ((1 << r) & i) {
                for (int c = 0; c < N; c++) {
                    checked[r][c] = !checked[r][c];
                }
            }
        }

        ll t = 0;
        for (int c = 0; c < N; c++) {
            ll off = 0;
            ll on = 0;
            for (int r = 0; r < N; r++) {
                if (checked[r][c]) on += arr[r][c];
                else off += arr[r][c];
            }
            t += max(off, on);
        }

        result = max(total-t, result);
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
