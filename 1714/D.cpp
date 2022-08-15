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
    string str; cin >> str;
    int N; cin >> N;
    string strs[N]; for (auto &a : strs) cin >> a;
    vector<tuple<int,int,int>> v;
    int s = str.size();
    int e = 0;
    for (int i = 0; i < str.size(); i++) {
        for (int k = 0; k < N; k++) {
            string x = strs[k];
            bool yes = true;
            for (int j = 0; j < x.size(); j++) {
                yes &= str[i + j] == x[j];
            }
            if (yes) {
                if (e < i + x.size() && i <= e) {
                    while (v.size() >= 2 && get<2>(v[v.size() - 2]) >= i) v.pop_back();
                    while (v.size() && get<1>(v.back()) == i) v.pop_back();
                    v.push_back({k, i, i+x.size()});
                    s = min(s, i);
                    e = max(e, i + (int) x.size());
                }
            }
        }
    }
    if (s == 0 && e == str.size()) {
        cout << v.size() << '\n';
        for (auto [a,b,e] : v) {
            cout << a+1 << ' ' << b+1 << '\n';
        }
    } else cout << -1 << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    cin >>T;
    while (T--) {
        solve();
    }
    return 0;
}
