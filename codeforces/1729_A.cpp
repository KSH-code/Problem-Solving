#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int a,b,c; cin >> a >> b >> c;
    a = a-1;
    b = abs(b-c) + abs(1-c);

    if (a < b) cout << 1;
    else if (b < a) cout << 2;
    else cout << 3;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
