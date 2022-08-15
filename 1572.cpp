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
    int N, K; cin >> N >> K;
    multiset<int> low, high;
    int arr[N]; for (auto &a : arr)cin >> a;
    ll result = 0;
    for (int i = 0; i < N; i++) {
        if (i >= K) {
            if (low.find(arr[i-K]) != low.end()) low.erase(low.find(arr[i-K]));
            else high.erase(high.find(arr[i-K]));
        }

        low.insert(arr[i]);

        while (high.size() && low.size() && *--low.end() > *high.begin()) {
            high.insert(*--low.end());
            low.erase(--low.end());
        }

        while (low.size() > high.size()) {
            high.insert(*--low.end());
            low.erase(--low.end());
        }
        while (low.size() < high.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
        if (i >= K-1) result += *--low.end();
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
