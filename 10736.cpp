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
    set<int> s;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int t = i ^ j;
            if (!s.count(i) && !s.count(j) && t <= N) s.insert(t);
        }
    }
    cout << N - s.size() << '\n';
    for (int i = 1; i <= N; i++) {
        if (!s.count(i)) cout << i << ' ';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
