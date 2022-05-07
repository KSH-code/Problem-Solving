#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 123456789;

void solve(){
    ll N; cin >> N;

    bool primes[N+1]; memset(primes, 1, sizeof(primes));
    for (int i = 2; i * i <= N; i++) {
        if (!primes[i]) continue;
        for (int j = i * 2; j <= N; j += i) primes[j] = false;
    }
    vector<ll> prime_vector;
    for (int i = 2; i <= N; i++) if (primes[i]) prime_vector.push_back(i);

    ll dp[N+1]; memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (auto prime : prime_vector) {
        for (int i = prime; i <= N; i++) {
            dp[i] += dp[i-prime];
            dp[i] %= MOD;
        }
    }
    cout << dp[N];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
