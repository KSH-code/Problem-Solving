#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 5e5;
int composition_numbers[MAX+1];
vector<int> primes;

void sieve() {
    composition_numbers[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (!composition_numbers[i]) {
            primes.push_back(i);
            composition_numbers[i]=i;
        }

        for (auto prime : primes) {
            if (i*prime > MAX) break;
            composition_numbers[i*prime]=prime;
            if (i%prime==0) break;
        }
    }
}


void solve(){
    sieve();
    int N; cin >> N;
    int color[N+1];
    int c = 1;
    for (int i = 1; i <= N; i++) {
        if (composition_numbers[i] == i) color[i] = c++;
        else color[i] = color[composition_numbers[i]];
    }
    cout << c-1 << '\n';
    for (int i = 1; i <= N; i++) cout << color[i] << ' ';
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
