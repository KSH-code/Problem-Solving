#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

void solve(){
    int K,N;cin>>K>>N;
    set<int> results[9];
    int check = 0;
    for (int i = 1; i <= 8; i++) results[i].insert(check = check * 10 + K);

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (i+j>8) break;
            for (auto x : results[i]) {
                for (auto y : results[j]) {
                    results[i+j].insert(x+y);
                    if(x-y) results[i+j].insert(x-y);
                    if(y-x) results[i+j].insert(y-x);
                    results[i+j].insert(x*y);
                    if(y&&x/y) results[i+j].insert(x/y);
                    if(x&&y/x) results[i+j].insert(y/x);
                }
            }
        }
    }

    while(N--) {
        int c;cin>>c;
        for (int i = 1; i <= 8; i++) {
            if (results[i].count(c)) {
                cout << i << '\n';
                break;
            } else if (i==8) cout << "NO" << '\n';
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
