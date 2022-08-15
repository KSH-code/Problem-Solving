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
    int x,y; cin >> x >> y;
    int sx, sy; cin >> sx >> sy;
    int dx, dy; cin >> dx >> dy;
    int result = 1e9;
    int g = gcd(dx,dy);
    dx /= g;
    dy /= g;
    int rx, ry;
    for (int i = 0; i < 100; i++) {
        if ((x-sx)*(x-sx)+(y-sy)*(y-sy) < result) {
            rx = sx;
            ry = sy;
            result = (x-sx)*(x-sx)+(y-sy)*(y-sy);
        }
        sx += dx;
        sy += dy;
    }
    cout << rx << ' ' << ry;
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
