#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N, M; cin >> N >> M;
    if (N+M==2) {
        cout << 0;
        return;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) cout << (N >= M ? (i+M)*j: (j+N)*i) << ' ';
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
