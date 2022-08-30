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
    sort(arr,arr+N);
    int result = 1;
    bool visited[N][N]; memset(visited, 0, sizeof visited);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int c = arr[i];
            int t_result = 1;
            int diff = arr[j] - c;
            c = c + diff;
            int k = j;
            while (arr[k] == c && !visited[i][k]) {
                visited[i][k] = true;
                t_result++;
                c += diff;
                k = lower_bound(arr + k + 1, arr + N, c) - arr;
                if (k == N) break;
            }
            result = max(result, t_result);
        }
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    for (int i = 1; i <= T; i++) {
        // cout << "Case #" << i << ": ";
        solve();
        // cout << '\n';
    }
    return 0;
}
