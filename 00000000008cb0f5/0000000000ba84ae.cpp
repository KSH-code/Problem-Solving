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
    int arr[N]; for (auto &a: arr) cin >> a;
    int arr2[N]; for (int i = 0; i < N; i++) arr2[i] = arr[i];
    sort(arr2,arr2+N);
    for (int i = 0; i < N; i++) {
        int j = upper_bound(arr2,arr2+N, arr[i]*2) - arr2 - 1;
        if (arr2[j]==arr[i]) j--;
        if (j>=0&&arr2[j] <= arr[i] * 2) cout << arr2[j];
        else cout << -1;
        cout << ' ';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    cin >>T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}
