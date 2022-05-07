#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll A,B,K; cin >> A >> B >>K;
    int i = 0;
    while (A < B) {
        A*=K;
        i++;
    }
    cout << i;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
