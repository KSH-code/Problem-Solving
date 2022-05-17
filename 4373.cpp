#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const INF = -1e18;

bool solve(){
    int N; cin >> N;
    if (!N) return false;

    ll arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr+N);
    unordered_map<ll, vector<pair<int,int>>> data;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            data[arr[j] - arr[i]].push_back({j,i});
        }
    }

    ll result = INF;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll cur = arr[j] + arr[i];
            if (!data.count(cur)) continue;
            for (auto [x,y] : data[cur]) {
                if (x==i||x==j||y==i||y==j) continue;
                result = max(result, arr[x]);
                break;
            }
        }
    }

    if (result == INF) {
        cout << "no solution";
    } else {
        cout << result;
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    while (solve()) cout << '\n';
    return 0;
}
