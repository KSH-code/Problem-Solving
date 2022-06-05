#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

queue<int> preorders;
int inorders_index[1001];

void trace(int l, int r) {
    int root = preorders.front(); preorders.pop();
    if (l == r) {
        cout << root << ' ';
        return;
    }

    int found_index = inorders_index[root];

    if (l <= found_index - 1) trace(l, found_index - 1);
    if (found_index + 1 <= r) trace(found_index + 1, r);
    cout << root << ' ';
};

void solve(){
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        preorders.push(c);
    }
    for (int i = 1; i <= N; i++) {
        int t; cin >> t;
        inorders_index[t] = i;
    }

    trace(1, N);
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
