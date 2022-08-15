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
    int arr[N]; for (auto &a : arr) cin >> a;
    int result = 0;
    sort(arr, arr+N);
    for (auto &a : arr) {
        if (a % 10) continue;

        while (a > 10 && M) {
            a -= 10;
            M--;
            result++;
        }
        if (a == 10) result++;
        a = 0;
    }
    for (auto a : arr) {
        int f = min(M, a / 10);
        result += f;
        M -= f;
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
