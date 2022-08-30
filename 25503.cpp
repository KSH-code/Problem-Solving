#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 3e5;
int N;
int arr[MAX+1];

void solve(){
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> arr[i];

    stack<pair<int,int>> o;
    bool yes = true;
    for (int i = 1; i <= N; i++) {
        int mn = arr[i];
        int mx = arr[i];
        while (i < N && abs(arr[i+1] - arr[i]) == 1) {
            i++;
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }
        while (o.size() && (abs(o.top().first - mx) == 1 || abs(o.top().second - mn) == 1)) {
            mn = min(o.top().first, mn);
            mx = max(o.top().second, mx);
            o.pop();
        }
        o.push({mn, mx});
    }
    cout << (o.size() == 1 ? "YES" : "NO");
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
