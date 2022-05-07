#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, K; cin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    priority_queue<ll> q;
    set<ll> s;
    for (int i = 0; i < N; i++) {
        q.push(-arr[i]);
    }


    ll b = *max_element(arr, arr+N);
    while (1) {
        ll t = q.top(); q.pop();
        t*=-1;
        K--;
        if (K==0) {
            cout << t;
            return;
        }
        for (int i = 0; i < N; i++) {
            ll f = t * arr[i];
            if (t > INT32_MAX) break;
            if (s.count(f)) continue;
            if (q.size()>= K && b < f) continue;
            b = max(f, b);
            s.insert(f);
            q.push(f * -1);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
