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
    int A,B,C; cin >> A >> B >> C;

    int r = 0;
    int f = 0;
    for (int x = -100; x <= 100; x++) {
        if (x*x*A + B*x + C == 0) {
            int br = r;
            for (int i = 2; i <= x; i <<= 1) if (x == i) r++;
            if (br == r) f++;
        }
    }

    if (r==2) cout << "이수근";
    else if (f+r==2) cout << "정수근";
    else cout << "둘다틀렸근";
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
