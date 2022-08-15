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

void solve(double _N, double _M){
    int N = _N, M = _M * 100 + 0.1;
    pii arr[N];

    int memo[M+1]; memset(memo, 0, sizeof memo);
    for (int i = 0; i < N; i++) {
        int a; double b; cin >> a >> b;
        arr[i] = {a,b * 100 + 0.1};
        for (int j = 1; j <= M; j++) {
            auto [a,b] = arr[i];
            if (j - b < 0) continue;
            memo[j] = max(memo[j], memo[j-b]+a);
        }
    }
    cout << memo[M];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    while (1) {
        double a,b; cin >> a >> b;
        if (!(a+b)) break;
        solve(a,b);
        cout << '\n';
    }
    return 0;
}
