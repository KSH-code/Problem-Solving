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
    string str; cin >> str; int K; cin >> K;
    int size = str.size();
    int arr[26][size];
    for (int i = 0; i < 26; i++) for (int j = 0; j < size; j++) arr[i][j] = -1;

    int counts[26]; memset(counts, 0, sizeof(counts));

    int result_min = 1e5;
    int result_max = 0;
    for (int i = 0; i < size; i++) {
        char c = str[i];
        int z = c-'a';
        arr[z][counts[z]++]=i;
        if (counts[z] >= K) {
            result_min = min(
                result_min,
                arr[z][counts[z]-1] - arr[z][counts[z] - K] + 1
            );
            result_max = max(
                result_max,
                arr[z][counts[z]-1] - arr[z][counts[z] - K] + 1
            );
        }
    }
    if (result_min == 1e5 && result_max == 0) cout << -1;
    else cout << result_min << ' ' << result_max;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--){
        solve();
        cout << '\n';
    }
    return 0;
}
