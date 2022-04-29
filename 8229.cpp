#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> fibos;

void solve(){
    ll N; cin >> N;
    int count = 0;
    while (N!=0) {
        ll remains = N;
        ll d = N;
        for (auto fibo : fibos) {
            if (abs(N-fibo) < abs(remains)) remains = N - fibo;
            if (abs(N+fibo) < abs(remains)) remains = N + fibo;
        }
        N = remains;
        count++;
    }
    cout << count;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    fibos.push_back(0);
    fibos.push_back(1);
    while (fibos.back() <= 4e17) {
        fibos.push_back(
            fibos[fibos.size()-1] + fibos[fibos.size()-2]
        );
    }
    fibos.push_back(
        fibos[fibos.size()-1] + fibos[fibos.size()-2]
    );

    int T; cin >> T;
    while(T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
