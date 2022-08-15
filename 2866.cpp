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
    int N, M; cin >> N >> M;
    string strs[N]; for (auto &a : strs) cin >> a;
    int result = N-1;

    string ss[M]; for (int i = 0; i < M; i++) ss[i] = "";

    for (int i = N-1; i >= 0; i--) {
        set<string> s;
        for (int j = 0; j < M; j++) {
            ss[j] = strs[i][j] + ss[j];
            s.insert(ss[j]);
        }
        if (s.size() != M) result = min(result, i-1);
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
