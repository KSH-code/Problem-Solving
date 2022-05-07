#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, M; cin >> N >> M;
    stack<int> st[7];
    int result = 0;

    for (int i = 0; i < N; i++) {
        int a,b; cin >> a >> b;
        while (st[a].size() && st[a].top() > b) {
            st[a].pop();
            result++;
        }

        if (st[a].empty() || (st[a].size() && st[a].top() != b)) {
            result++;
            st[a].push(b);
        }
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
