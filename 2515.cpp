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
ll memo[MAX+1];
pair<int,int> arr[MAX+1];
int N,M;

void solve(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        auto &[a,b] = arr[i];
        cin >> a >> b;
    }
    sort(arr, arr+N);

    memo[0] = arr[0].second;
    for (int i = 1; i < N; i++) {
        auto [a,b] = arr[i];
        int l=0,r=i;
        while (l+1<r) {
            int m = (l+r)/2;
            if (a - arr[m].first >= M) l = m;
            else r = m;
        }
        if (a - arr[l].first >= M) memo[i] = max(memo[l]+b, memo[i-1]);
        else memo[i] = max(memo[i-1], (ll)b);
    }
    cout << memo[N-1];
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
