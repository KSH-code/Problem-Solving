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
    int arr[N]; for (auto &a : arr) cin >> a;
    int MAX = accumulate(arr,arr+N,0);
    ll memo[MAX+1]; memset(memo, 0, sizeof memo); memo[0] = 1;
    int counts[10001]; memset(counts, 0, sizeof counts); for (int i = 0; i < N; i++) counts[arr[i]]++;
    for (int i = 1; i <= 10000; i++) {
        if (!counts[i]) continue;
        for (int j = MAX; j >= 0; j--) {
            for (int k = 1; k <= counts[i] && j - i * k >= 0; k++) {
                memo[j] += memo[j - i * k];
            }
        }
    }
    ll result = 0;
    for (int i = 2; i <= MAX; i++) {
        if (memo[i]) {
            for (int j = 2; j * j <= i; j++) if (i%j==0) {
                memo[i] = 0;
                break;
            }
        }
        result += memo[i];
    }
    cout << result * (counts[0] + 1);
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
