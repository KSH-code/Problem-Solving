#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

using pll = pair<ll,ll>;
void solve(){
    ll N, M;
    cin >> N >> M;

    pll arr[N]; for (auto &[a,b] : arr) cin >> a >> b;

    map<ll,int> spicy;

    int l = 0, r = 0;
    ll cur = 0;

    ll result = 1e9;
    while (l <= r) {
        if (cur >= M) result = min(result, (*--spicy.end()).first);

        if (cur < M && r < N) {
            auto [a,b] = arr[r++];
            spicy[b]++;
            cur += a;
        } else {
            auto [a,b] = arr[l++];
            cur -= a;
            spicy[b]--;
            if (!spicy[b]) spicy.erase(b);
        }
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
