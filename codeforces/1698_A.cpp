#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    int arr[N]; for (auto &a : arr) cin >> a;
    for (int i = 0; i < N; i++) {
        int x = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            x ^= arr[j];
        }
        if (x == arr[i]) {
            cout << x;
            return;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
