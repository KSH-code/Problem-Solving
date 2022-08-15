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
    ll arr[N]; for (auto &a : arr) cin >> a;
    vector<tuple<int,int,int>> v;
    for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) v.push_back({arr[i]+arr[j],i,j});
    sort(v.begin(), v.end());

    ll result = 1e18;
    for (int i = 0; i < v.size(); i++) {
        auto [a,x,y] = v[i];
        for (int j = i + 1; j < v.size(); j++) {
            auto [b,xx,yy] = v[j];
            if (x == xx || x == yy || y == xx || y == yy) continue;
            if (abs(a - b) < result) result = abs(a - b);
            else break;
        }
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
