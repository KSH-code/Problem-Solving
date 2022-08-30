#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};
const int MAX = 2e5;
int arr[MAX+1];

int dfs(int l, int r) {
    if (l == r) return arr[l];

    int mid = (r-l+1)/2;
    int lgcd = arr[l]; for (int i = 0; i < mid; i++) lgcd = gcd(lgcd, arr[l+i]);
    int rgcd = arr[l+mid]; for (int i = 1; l+mid+i <= r; i++) rgcd = gcd(rgcd, arr[l+mid+i]);

    return max(
        lgcd + dfs(l+mid, r),
        rgcd + dfs(l, l+mid-1)
    );
}

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cout << dfs(1, N);
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
