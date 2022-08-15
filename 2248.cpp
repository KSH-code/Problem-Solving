#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

ll dp[32][32];

int binary(int n, int m){
	ll &ret = dp[n][m];
	if(ret != -1) return ret;
	if(m==0 || n==0) return ret = 1;

	ret = binary(n-1, m);
	if(m > 0) ret += binary(n-1, m-1);
	return ret;
}

void solve(){
    memset(dp, -1, sizeof(dp));

    ll N,L,I;
    cin >> N >> L >> I;

    I--;
    for (int c = 1; c <= N; c++) {
        if (I >= binary(N-c,L)) {
            I -= binary(N-c,L);
            L--;
            cout << 1;
        } else {
            cout << 0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
