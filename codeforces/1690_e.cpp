#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; ll K;cin>>N>>K;
    vector<pair<ll,ll>> arr;
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        arr.push_back({a%K, a});
    }
    sort(arr.begin(), arr.end());
    ll result = 0;

    int l = 0, r = N-1;
    while (l < r) {
        auto [a,b] = arr[l];
        auto [c,d] = arr[r];
        if (a+c<K) {
            d = arr[l+1].second;
            l++;
            r++;
        }
        result += (b+d)/K;
        l++,r--;
    }
    cout << result;
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
