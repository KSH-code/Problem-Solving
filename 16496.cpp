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
    auto compare = [](string a, string b) {
        int s = a.size()+b.size();
        for (int i = 0; i < s; i++) {
            if (a[i % a.size()] == b[i % b.size()]) continue;
            return a[i % a.size()] < b[i % b.size()];
        }
        return true;
    };
    priority_queue<string, vector<string>, decltype(compare)> q(compare);
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        q.push(s);
    }
    if (q.top() == "0") {
        cout << 0;
        return;
    }

    while(q.size()) {
        cout << q.top(); q.pop();
    }

}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
