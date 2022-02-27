#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> edges(N+1);
    for (int i = 0; i < M; i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    ll mod = (ll)(1e9+7);
    int counts[N+1][8]; for (int i = 0; i <= N; i++) for (int j = 0; j < 8; j++) counts[i][j] = 0;
    for (int i = 1; i <= N; i++) counts[i][1] = edges[i].size();
    for (int j = 1; j <= 7; j++) {
        for (int i = 1; i <= N; i++) {
            for (auto n : edges[i])
                counts[i][j] = (counts[i][j] + counts[n][j-1]) % mod;
        }
    }

    ll result = 0;
    for (int i = 1; i <= N; i++) result = (result + counts[i][7]) % mod;
    cout << result;
    return 0;
}
