#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

using pii = pair<int,int>;

void solve(){
    int N; cin >> N;
    pii arr[N]; for (auto &[a,b] : arr)cin >> a >> b; sort(arr, arr+N);
    int t = 1;
    set<int> s;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    map<int,int> counts;
    for (int i = 0; i < N; i++) {
        auto [a,b] = arr[i];
        while (q.size() && q.top().first <= a) {
            auto [c,d] = q.top(); q.pop();
            s.insert(d);
        }
        if (s.empty()) s.insert(t++);

        auto c = *s.begin();
        s.erase(s.begin());
        q.push({b,c});
        counts[c]++;
    }
    cout << counts.size() << '\n';
    for (auto [a,b] : counts) cout << b << ' ';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
