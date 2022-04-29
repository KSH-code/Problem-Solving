#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    deque<int> dq;
    int v[N+1];
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        dq.push_back(i);
    }

    for (int i = 0; i < N; i++) {
        int x = dq.front();
        int y = v[x];
        cout << x << ' ';
        dq.pop_front();
        if (y > 0) {
            y--;
            while ((y--)>0) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            while (y++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
