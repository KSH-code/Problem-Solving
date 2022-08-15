#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

int dp[101][101];
int arr[] = {6,2,5,5,4,5,6,3,7,6};

int dfs(int n, int k) {
    if (!n && !k) return true;

    auto &ret = dp[n][k];
    if (ret != -1) return ret;
    if (!n) return 0;

    ret = 0;
    for (int i = 0; i <= 9; i++) {
        if (dfs(n-1, k-arr[i])) ret = 1;
    }

    return ret;
}

void solve2(int c) {
    memset(dp, -1, sizeof dp);

    if (c <= 7) for (int i = 1; i <= 9; i++) if (arr[i] == c) {
        cout << i;
        return;
    }

    int length = 1;
    bool f = true;
    while (f) {
        length++;
        for (int i = 1; i <= 9; i++) {
            if (dfs(length-1, c-arr[i])) {
                f = false;
                break;
            }
        }
    }

    for (int i = 1; i <= 9; i++) if (dfs(length-1, c-arr[i])) {
        cout << i;
        c -= arr[i];
        break;
    }


    for (length--; length >= 1; length--)
    for (int i = 0; i <= 9; i++) if (dfs(length-1, c-arr[i])) {
        cout << i;
        c -= arr[i];
        break;
    }
}


void solve(){
    int c; cin >> c;
    solve2(c);
    cout << ' ';
    if (c&1) {
        c -= 3;
        cout << 7;
    }
    for (int i = 2; i <= c; i+=2) cout << 1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N; cin >> N;
    while (N--) {
        solve();
        cout << '\n';
    }
    return 0;
}
