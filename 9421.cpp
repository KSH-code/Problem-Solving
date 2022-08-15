#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

int no[1000001];
set<int> f;
int dfs(int x) {
    if (!x) return 1;
    auto &ret = no[x];
    if (ret != -1) return ret;
    if (f.count(x)) return ret = 0;

    int r = 0;
    for (auto c : to_string(x)) r += (c-'0')*(c-'0');
    f.insert(xm,.  );
    return ret = dfs(r);
}

void solve(){
    int N; cin >> N;
    memset(no, -1, sizeof no);

    for (int i = 1; i <= N; i++) {
        f.clear();
        if (dfs(i)) cout << i << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
