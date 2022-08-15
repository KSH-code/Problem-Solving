#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

string memo[13];

string dfs(int x) {
    auto &ref = memo[x];
    if (ref.size()) return ref;

    ref = dfs(x-1) + string(pow(3,max(x-1, 0)), ' ') + dfs(x-1);
    return ref;
}

void solve(int N){
    memo[0] = "-";
    cout << dfs(N);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t;
    while (cin >> t) {
        solve(t);
        cout << '\n';
    }
    return 0;
}
