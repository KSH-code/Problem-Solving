#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

const int MAX = 5e6;

int composition_numbers[MAX+1];
vector<int> primes;

void sieve() {
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
    int N; cin >> N;
    sieve();
    for (int i = 0; i < N; i++) {
        int z; cin >> z;
        while (composition_numbers[z]) {
            cout << composition_numbers[z] << ' ';
            z /= composition_numbers[z];
        }
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
