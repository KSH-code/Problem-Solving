#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

set<int> primes;
bool composite_numbers[1299709+1];
const int MAX = 1299709;

void init() {
    for (int i = 2; i <= MAX; i++) {
        if (!composite_numbers[i]) primes.insert(i);
        for (auto p : primes) {
            if (i*p > MAX) break;
            composite_numbers[i*p] = true;
            if (i % p == 0) break;
        }
    }
}

void solve(){
    int N; cin >> N;
    if (!composite_numbers[N]) {
        cout << 0;
    } else {
        auto up = primes.upper_bound(N);
        auto lo = --up;
        cout << *++up - *lo;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    init();
    int N; cin >> N;
    while(N--) {
        solve();
        cout << '\n';
    }
    return 0;
}
