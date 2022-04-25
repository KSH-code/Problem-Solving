#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e5+1;

void solve(){
    int N; cin >> N;
    ll arr[MAX]; memset(arr, 0, sizeof(arr));
    for(int i = 0; i < N; i++){
        int c; cin >> c;
        arr[c]++;
    }

    ll count = 0;

    for (ll i = 1; i < MAX; i++) {
        for (ll j = 1; (i*j) < MAX; j++) {
            count += arr[i] * arr[j] * arr[i*j];
        }
    }

    cout << count;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
