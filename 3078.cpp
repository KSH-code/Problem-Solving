#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, K; cin >> N >> K;
    queue<int> q[21];
    ll result = 0;
    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        int length = str.size();
        while (q[length].size()) {
            auto j = q[length].front();
            if (i - j > K) q[length].pop();
            else break;
        }
        result += q[length].size();
        q[length].push(i);
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
