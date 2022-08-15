#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

bool composite[3001];
vector<int> primes;

void sieve() {
    for (int i = 2; i <= 3000; i++) {
        if (!composite[i]) primes.push_back(i);
        for (auto p : primes) {
            if (p * i > 3000) break;
            composite[p * i] = true;
            if (i % p == 0) break;
        }
    }
}

void solve(){
    sieve();
    composite[1]=1;
    int N, M; cin >> N >> M;
    int arr[N]; for (auto &a : arr) cin >> a;
    set<int> s;
    for (int i = 0; i < 1<<N; i++) {
        int f = 0, c = 0;
        for (int j = 0; j < N; j++) if (1 << j & i) f += arr[j], c++;
        if (c == M && !composite[f]) s.insert(f);
    }
    if (s.size()) {
        for (auto result : s) cout << result << ' ';
    } else cout << -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
