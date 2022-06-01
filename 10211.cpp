#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void solve(){
    int N; cin >> N;
    int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];

    int r = arr[0];
    for (int i = 0; i < N; i++) {
        int t = arr[i];
        r = max(t, r);
        for (int j = i + 1; j < N; j++) {
            t += arr[j];
            r = max(t, r);
        }
    }

    cout << r;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
