#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll m, seed, x1, x2;
    cin >> m >> seed >> x1 >> x2;
    vector<ll> primes;
    for (ll a = 0; a*a < m; a++) {
        bool is_prime = true;
        for (auto prime : primes) {
            if (a % prime == 0) {
                is_prime = false;
                break;
            }
        }
        if (a >= 2 && is_prime) {
            primes.push_back(a);
        } else if (a <= 1) {
        } else continue;
        ll c = (x1 + (m - (a*seed%m)))%m;
        ll X1 = (a * seed + c) % m;
        ll X2 = (a*(a*seed+c)%m + c) % m;
        if (X1 == x1 && X2 == x2) {
            cout << a << ' ' << c;
            return;
        }
    }
    assert(1==0);
    // X1 = (a × Seed + c) % m
    // a^2
    // a*seed
    // a*c
    // X2 = (a × (a * seed + c) % m + c) % m
    // (a^2 seed + a*seed)+ c % m
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
