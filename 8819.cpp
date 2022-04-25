#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        if (gcd(i, N) == 1) {
            cout << i << ' ';
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
    return 0;
}
