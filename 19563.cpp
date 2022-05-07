#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int a,b,c; cin >> a >> b>> c;
    int count = abs(a)+abs(b)-c;
    bool yes = count <= 0 && count % 2 == 0;
    cout << (yes ? "YES" : "NO");
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
