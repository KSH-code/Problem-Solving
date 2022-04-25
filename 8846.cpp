#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    ll r = 1, b = 0;
    ll result = 1;
    for (int i = 1; i < N; i++) {
        r = (r * 4) % 500000009;
        result += r;
        result %= 500000009;
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
