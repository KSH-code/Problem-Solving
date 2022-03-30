#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
void solve(){
    int N,M; cin>>N>>M;
    ll arr[M]; for (int i = 0; i < M; i++) cin>>arr[i];
    ll result = 0;
    ll l = 0, r = 1e9;
    while (l<=r) {
        ll m = (l+r)/2;
        ll count = 0;
        for (int i = 0; i < M; i++) count += arr[i] / m;
        if (count >= N) {
            result = max(m,result);
            l = m+1;
        } else {
            r = m-1;
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
