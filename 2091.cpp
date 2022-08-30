#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

struct Node {
    int a,b,c,d;
};

void solve(){
    int N; cin >> N;
    int a,b,c,d;cin>>a>>b>>c>>d;
    vector<pair<int,int>> v;
    v.push_back({1,a});
    v.push_back({5,b});
    v.push_back({10,c});
    v.push_back({25,d});
    Node memo[N+1]; for (int i = 0; i <= N; i++) memo[i] = {0,0,0,0};
    for (int i = 1; i <= N; i++) {
        for (auto [a,b] : v) {
            int t = i - a;
            if (t < 0) continue;
            auto [z,x,c,v] = memo[t];
            if (z||x||c||v||!t) {
                if (a==1) {
                    z += 1;
                    if (z > b) continue;
                }
                if (a==5) {
                    x += 1;
                    if (x > b) continue;
                }
                if (a==10) {
                    c += 1;
                    if (c > b) continue;
                }
                if (a==25) {
                    v += 1;
                    if (v > b) continue;
                }
                auto [q,w,e,r] = memo[i];
                if (q+w+e+r < z+x+c+v) memo[i] = {z,x,c,v};
            }
        }
    }
    auto [aa,bb,cc,dd] = memo[N]; cout << aa << ' ' << bb <<' ' << cc << ' ' << dd;
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
