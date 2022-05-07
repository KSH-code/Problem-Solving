#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e4;

void solve(){
    int N, K; cin >> N >> K;
    ll arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
    ll l = 0, r = *max_element(arr, arr+N) + 1;

    ll result = 0;
    while (l + 1 < r) {
        ll m = (l + r) / 2;

        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += arr[i] / m;
        }

        if (cnt >= K) {
            result = max(result, m);
            l = m;
        } else r = m;
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
