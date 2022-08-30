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
    deque<string> q;
    while (N--) {
        string str; cin >> str;
        q.push_back(str);
    }
    int z = 0;
    while (q.size()) {
        if (q.front() < q.back()) {
            z++;
            cout << q.front(); q.pop_front();
            if (z % 80 == 0) cout << '\n';
        } else if (q.front() == q.back()) {
            string a="", b="";
            for (int i = 0; i < q.size(); i++) {
                a += q[i];
                b += q[q.size() - 1 - i];
                if (q[i] != q[q.size() - i - 1]) break;
            }

            if (a + b <= b + a) {
                while (q.size() && q.front() == q.back()) {
                    z++;
                    cout << q.front(); q.pop_front();
                    if (z % 80 == 0) cout << '\n';
                }
            } else {
                while (q.size() && q.front() == q.back()) {
                    z++;
                    cout << q.back(); q.pop_back();
                    if (z % 80 == 0) cout << '\n';
                }
            }
        } else {
            z++;
            cout << q.back(); q.pop_back();
            if (z % 80 == 0) cout << '\n';
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
    }
    return 0;
}
