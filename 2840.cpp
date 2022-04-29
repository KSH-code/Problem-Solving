#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, K; cin >> N >> K;
    deque<int> dq;
    char cell[N+1];
    for (int i = 1; i <= N; i++) {
        cell[i] = '?';
        dq.push_back(i);
    }
    set<char> s;

    for (int i = 0; i < K; i++) {
        int rotate; cin >> rotate;
        char c; cin >> c;
        while (rotate--) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        int cur = dq.front();
        if (cell[cur] == c) continue;

        if (cell[cur] == '?' && !s.count(c)) {
            s.insert(c);
            cell[cur] = c;
        } else {
            cout << "!";
            return;
        }
    }
    while (dq.size()) {
        cout << cell[dq.front()];
        dq.pop_front();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
