#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

bool visited[5001];
void solve(){
    int N; cin >> N;

    for (int i = N/2; i >= 1; i--) {
        cout << i << ' ' << i+N/2 << ' ';
    }

    if (N & 1) cout << N;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
