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
    long double Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy>>Dx>>Dy;
    long double result = 1e9;
    for (long double i = 0; i <= 5e5; i++) {
        long double x1 = Ax + (Bx - Ax) / 5e5 * i;
        long double y1 = Ay + (By - Ay) / 5e5 * i;
        long double x2 = Cx + (Dx - Cx) / 5e5 * i;
        long double y2 = Cy + (Dy - Cy) / 5e5 * i;

        result = min(
            result,
            sqrt((x1-x2) * (x1-x2) + (y1 - y2) * (y1 - y2))
        );
    }
    printf("%.10Lf", result);
}

int main()
{
    // cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
