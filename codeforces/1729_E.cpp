#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    int X[N];
    for (auto &a : X) cin >> a;
    int Y[N];
    for (auto &a : Y) cin >> a;
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = Y[i] - X[i];
    }
    sort(arr,arr+N);

    int l = 0;
    int result = 0;
    for (int i = N-1; i > l; i--) {
        l = lower_bound(arr+l,arr+N,-arr[i])-arr;
        if (l >= i) break;
        l++;
        result++;
    }
    cout << result;
}

int main()
{
    // cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
