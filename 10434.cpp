#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


const int MAX = 1e4;
bool composite[MAX+1];
vector<int> primes;

void sieve() {
    for (int i = 2; i <= MAX; i++) {
        if (!composite[i]) primes.push_back(i);
        for (auto p : primes) {
            if (p * i > MAX) break;
            composite[p * i] = true;
            if (i % p == 0) break;
        }
    }
}

set<int> s;
bool dfs(int N) {
    if (s.count(N)) return false;
    s.insert(N);

    int n = 0;
    while(N) {
        int nu = N%10;
        n += nu * nu;
        N /= 10;
    }
    if (n == 1) return true;
    return dfs(n);
}

void solve(){
    s.clear();
    int N, M; cin >> N >> M;
    cout << N << ' ' << M << ' ';
    cout << (dfs(M) && !composite[M]?"YES":"NO");
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    composite[1] = true;
    sieve();
    int T=1;
    cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
