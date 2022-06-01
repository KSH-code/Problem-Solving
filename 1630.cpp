#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void solve(){
    int N; cin >> N;
    int co_primes[N+1]; memset(co_primes, 0, sizeof(co_primes));
    vector<int> primes;

    for (int i = 2; i <= N; i++) {
        if (!co_primes[i]) primes.push_back(i);

        for (auto prime : primes) {
            if (i * prime > N) break;
            co_primes[i*prime]=prime;
            if (i % prime == 0) break;
        }
    }

    ll result = 1;

    for (auto prime : primes) {
        ll k = prime;
        while (k * prime <= N) k *= prime;
        result *= k;
        result %= 987654321;
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
