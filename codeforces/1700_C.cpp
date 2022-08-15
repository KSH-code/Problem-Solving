#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;

void solve(){
    int N;
    cin >> N;
    ll result = 0;
    ll arr[N]; for (auto &a : arr) cin >> a;
    ll r = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] - arr[i-1] > 0) {
            result += arr[i] - arr[i-1];
        } else {
            result -= arr[i] - arr[i-1];
            r += arr[i] - arr[i-1];
        }
    }
    cout << result + abs(r);
}

int main()
{
    int T; cin >> T;
    while (T--){
        solve();
        cout << '\n';
    }
    return 0;
}
