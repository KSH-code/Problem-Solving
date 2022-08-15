#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

int memo[51][10];

void solve(){
    int N; cin >> N;
    int arr[N]; for (auto &a : arr)cin >>a;
    int M; cin >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            if (i - arr[j] >= 0) {
                for (int k = 0; k < N; k++) {
                    memo[i][j] = max(memo[i][j], memo[i - arr[j]][k] + 1);
                }
            }
        }
    }

    int length = 0;
    for (int i = M; i >= 1; i--) for (int j = 1; j < N; j++) {
        if (length < memo[i][j]) {
            M = i;
            length = memo[i][j];
        }
    }
    if (!length) cout << 0;
    while (length) {
        bool found = false;
        for (int i = N-1; i >= 0; i--) {
            if (memo[M][i] == length && !found) {
                if (length-1 == 0) {
                    cout << i;
                    return;
                }
                for (int j = N-1; j>= 0; j--) {
                    if (M-arr[i]>=0 && memo[M-arr[i]][j] == length-1) {
                        found = true;
                        cout << i;
                        length--;
                        M -= arr[i];
                        break;
                    }
                }
            }
        }
    }
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
