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
    int N; cin >> N;
    string str; cin >> str;

    ll d=0,k=0,s=0,h=0;
    ll result = 0;
    for (int i = N-1; i >= 0; i--) {
        switch(str[i]) {
            case 'D':
                result += k;
                break;
            case 'K':
                k += s;
                break;
            case 'S':
                s += h;
                break;
            case 'H':
                h++;
                break;
        }
    }
    cout << result;
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
