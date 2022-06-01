#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};


const int MAX = 1e6;
vector<int> co_primes[MAX+1];
vector<int> primes;

void sieve(){
    for (int i = 2; i <= MAX; i++) {
        if (co_primes[i].empty()) primes.push_back(i);

        for (auto prime : primes) {
            if (i*prime > MAX) break;
            co_primes[i*prime].push_back(i);
        }
    }
}

ll results[MAX+1];

ll memo[MAX+1];
bool visited[MAX+1];
int c;
ll dfs(int x) {
    if (memo[x]) return memo[x];
    if (visited[x]==c) return 0;
    visited[x]=c;

    ll &result = memo[x];
    for (auto nx : co_primes[x]) {
        result += dfs(nx);
    }

    return result += x;
}

void solve(){
    int T; cin >> T;
    sieve();
    results[1]=1;
    for (int i = 2; i <= MAX; i++) {
        c=i;
        ll result = 1+dfs(i);
        results[i]=results[i-1]+result;
    }

    while (T--) {
        int N; cin >> N;
        cout << results[N] << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
