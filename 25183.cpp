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
    string str; cin >> str;
    int r = 1;
    int result = 0;
    for (int i = 1; i < N; i++) {
        if (abs(str[i]-str[i-1])==1) {
            result=max(result,++r);
        } else {
            r = 1;
        }
    }
    cout << (result>=5?"YES":"NO");
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
