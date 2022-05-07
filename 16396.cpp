#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;

    bool lines[10001]; memset(lines, 0, sizeof(lines));

    int result = 0;
    for (int i = 0; i < N; i++) {
        int x,y;cin>>x>>y;
        for (;x < y; x++) {
            if (lines[x]) continue;
            lines[x] = true;
            result++;
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
