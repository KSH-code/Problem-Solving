#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

int N;
string str[25];
int bits[25];

int dfs(int x, int m, int c) {
    int result = m+1 == (1<<26);
    for (int i = x; i < N; i++) {
        result += dfs(i+1, bits[i] | m, c+1);
    }
    return result;
}

void solve(){
    cin >> N;
    memset(bits, 0, sizeof bits);
    for (int i = 0; i < N; i++) {
        cin >> str[i];
        for (auto a : str[i]) bits[i] |= 1<<(a-'a');
    }

    cout << dfs(0, 0, 0);
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
