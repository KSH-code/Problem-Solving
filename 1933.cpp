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
    vector<tuple<int,int,int>> arr(N);
    for (auto &[a,b,c] : arr) cin >> a >> b >> c;
    auto compare = [](tuple<int,int,int> a, tuple<int,int,int> b) {
        auto [x1,y1,z1] = a;
        auto [x2,y2,z2] = b;
        if (x1 == x2) {
            if (y1 == y2) return z1 >= z2;
            return y1 >= y2;
        }
        if (y1 == y2) return z1 >= z2;
        return x1 <= x2;
    };
    sort(arr.begin(), arr.end(), compare);

    stack<tuple<int,int,int>> s;
    for (int i = 0; i < N; i++) {
        auto [a,b,c] = arr[i];
        while (s.size()) {
            auto [a2,b2,c2] = s.top();
            if (c2 < a) {
                cout << c2 << ' ' << 0 << ' ';
                s.pop();
            } else if (c2 <= a && c >= c2 && b2 >= b) break;
            else if
        }
        if (s.empty()) s.push({a, b, c});

    }
    cout <<
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
