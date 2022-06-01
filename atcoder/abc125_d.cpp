#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;

    ll arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 1; i < N; i++) {
        if (arr[i]+arr[i-1] < -arr[i]-arr[i-1]) {
            arr[i]*=-1;
            arr[i-1]*=-1;
        }
    }

    if (-arr[N-2]-arr[N-1]>arr[N-2]+arr[N-1]) {
        arr[N-2]*=-1;
        arr[N-1]*=-1;
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }

    cout << accumulate(arr, arr+N, 0LL);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
