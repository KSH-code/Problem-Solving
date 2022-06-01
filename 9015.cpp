#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

typedef pair<int,int> pii;

ll square(pii a, pii b) {
    return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
}

pii points[3000];
int N;

bool find(int x, int y) {
    int l = 0, r = N;
    while (l + 1 < r) {
        int m = (l+r)/2;
        auto [fx,fy] = points[m];
        if (fx == x && fy == y) return true;

        if (fx > x) {
            r = m;
        } else if (fx == x) {
            if (fy > y) {
                r = m;
            } else {
                l = m;
            }
        } else {
            l = m;
        }
    }
    return false;
}

void solve(){
    cin >> N;
    for (int i = 0; i < N; i++){
        auto &[x,y] = points[i];
        cin >> x >> y;
    }
    sort(points, points+N);

    ll result = 0;
    for (int i = 0; i < N; i++) {
        auto [lx, ly] = points[i];
        for (int j = i + 1; j < N; j++) {
            auto [rx, ry] = points[j];
            if (square(points[i], points[j]) <= result) continue;

            int flx = lx-(ry-ly);
            int fly = ly+(rx-lx);

            int frx = rx-(ry-ly);
            int fry = ry+(rx-lx);


            if (find(flx, fly) && find(frx, fry)) result = square(points[i], points[j]);
        }
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
