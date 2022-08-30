#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

set<string> s;

void dfs(string str, string go) {
    if (str.empty()) {
        result++;
        return;
    }

    dfs(str.substr(1, str.size() - 1), go + str);
    dfs(str.substr(0, str.size() - 1), go + str);
}

void solve(){
    string str; cin >> str;
    dfs(str, "");
    cout << s.size();
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
