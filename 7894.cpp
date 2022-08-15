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
    double result = 0;
    for (int i = 1; i <= N; i++) result += log10(i);

    cout << ll(result) + 1;
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
