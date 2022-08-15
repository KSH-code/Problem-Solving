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
    string str;cin>>str;
    queue<int> a;
    priority_queue<int> b;
    int result = 0;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == 'A') {
            a.push(i);
        } else if (c == 'B') {
            b.push(-i);
        } else {
            if (b.size()) {
                result++;
                b.pop();
            }
        }
    }
    while (a.size()) {
        if (b.size()) {
            auto i = b.top(); b.pop();
            i *= -1;
            if (i < a.front()) continue;
            result++;
            a.pop();
        } else break;
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
