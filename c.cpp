#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs

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

    ll rows[N]; memset(rows, 0, sizeof(rows));
    ll columns[N]; memset(columns, 0, sizeof(columns));
    for (int i = 0; i <N; i++) {
        for (int j = 0; j < N; j++) {
            rows[i] += arr[i][j];
            columns[i] += arr[j][i];
        }
    }

    ll result = -1e18;
    ll rz = 0;

    for (int i = (1<<N)-1; i >= 0; i--) {
        ll rt = 0;
        for (int r = 0; r < N; r++) {
            if (i & (1<<r)) {
                rt += rows[r];
            }
        }
        if (rt >= result && total - rt >= rt) {
            result = max(rt, result);
        }
    }
    cout << rz;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
