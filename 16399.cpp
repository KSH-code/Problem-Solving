#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e4;
const ll INF = 1e18;

pair<int,int> stations[1000];
int N;
int C, E, D;

ll dp[1000][500];

ll dfs(int x, int current_gas) {
    if (dp[x][current_gas] != INF) return dp[x][current_gas];

    ll result = INF;
    auto [current_position, cp] = stations[x];

    if ((D - current_position) * E <= C) {
        int need_gas = (D - current_position) * E;
        if (current_gas >= need_gas) result = 0;
        else result = (need_gas - current_gas) * cp;
    }

    for (int i = x + 1; i < N; i++) {
        auto [distance, price] = stations[i];
        if (distance >= D) break;

        int moving_distance = distance - current_position;
        if (moving_distance * E > C) break;

        int need_gas = moving_distance * E;
        if (price > cp) {
            ll need_price = (C - current_gas) * cp;
            ll c = dfs(i, C - need_gas);
            if (c == -1) c = INF;
            else c += need_price;

            result = min(
                result,
                c
            );
        } else {
            if (current_gas >= need_gas) {
                result = min(
                    result,
                    dfs(i, current_gas - need_gas)
                );
            } else {
                ll need_price = (need_gas - current_gas) * cp;
                ll c = dfs(i, 0);

                if (c == -1) c = INF;
                else c += need_price;

                result = min(
                    result,
                    c
                );
            }
        }
    }

    if (result == INF) result = -1;
    return dp[x][current_gas] = result;
}

void solve(){
    cin >> C >> E >> D;
    cin >> N;
    int distances[N+1], prices[N+1];
    for (int i = 0; i < N; i++) cin >> distances[i];
    for (int i = 0; i < N; i++) cin >> prices[i];

    if (C >= D * E) {
        cout << 0;
        return;
    }

    for (int i = 0; i < N; i++) for (int j = 0; j < 500; j++) dp[i][j] = INF;

    int p = 0;
    for (int i = 0; i < N; i++) {
        stations[i] = {p += distances[i], prices[i]};
    }

    ll result = INF;
    for (int i = 0; i < N; i++) {
        int ng = stations[i].first * E;
        if (ng <= C) {
            ll g = dfs(i, C - ng);
            if (g != -1) result = min(result, g);
        }
    }

    if (result == INF) result = -1;

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
