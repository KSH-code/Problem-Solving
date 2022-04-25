#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll arr[40];

void solve(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }


    if(N == 1){
        cout << arr[0] << '/' << 1;
        return;
    }

    ll n = 1;
    ll d = arr[N-1];
    for (int i = N-2; i >= 1; i--) {
        ll n1 = d;
        ll d1 = arr[i]*d+n;
        n = n1;
        d = d1;
    }
    cout << n+arr[0]*d<<'/'<<d;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
