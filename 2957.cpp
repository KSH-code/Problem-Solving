#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


void solve(){
    int N; cin >> N;
    set<pair<int,int>> s;
    set<pair<int,int>> s2;
    ll result = 0;
    int a; cin >> a;
    s.insert({a, 0});
    set<int> c;
    for (int i = 1; i < N; i++) {
        int a;cin>>a;
        auto it = s.lower_bound({a,0});
        int z = 0;
        if (it == s.end()) {
            it = --s.end();
        }
        z = max(z, (*it).second);

        it = s2.lower_bound({-a, 1e9});
        if (it == s2.end()) {
            it = --s2.end();
        }
        z = max(z, (*it).second);

        auto [b,c] = *it;
        s.insert({a,z+1});
        s2.insert({-a,z+1});
        cout << result << '\n';
        result += z+1;
    }
    cout << result;
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
