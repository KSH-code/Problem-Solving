#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};


const int MAX = 1e5;
int co_primes[MAX+1];
int counts[MAX+1];
vector<int> primes;

void sieve(){
    for (int i = 2; i <= MAX; i++) {
        if (!co_primes[i]) {
            primes.push_back(i);
            co_primes[i]=i;
        }

        for (auto prime : primes) {
            if (i*prime > MAX) break;
            co_primes[i*prime] = prime;
            if (i % prime == 0) break;
        }
    }
}

void solve(){
    int A, B; cin >> A >> B;
    sieve();

    int result = 0;
    for (int i = A; i<= B; i++) {
        int c = 0;
        int z = i;
        while (co_primes[z]) {
            z /= co_primes[z];
            c++;
        }
        if (co_primes[c]==c) result++;
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
