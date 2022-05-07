#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll> points[300];
bool used[300][300];

bool check(int a, int b, int c) {
    auto [x1, y1] = points[a];
    auto [x2, y2] = points[b];
    auto [x3, y3] = points[c];

    return (x2-x1)*(y3-y1) == (x3-x1)*(y2-y1);
}

void solve(){
    int N, K; cin >> N >> K;
    if (K == 1) {
        cout << "Infinity";
        return;
    }

    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }


    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (used[i][j]) continue;

            vector<int> p;
            p.push_back(i);
            p.push_back(j);
            for (int k = j + 1; k < N; k++) {
                if (check(i,j,k)) {
                    p.push_back(k);
                }
            }

            for (int pi = 0; pi < p.size(); pi++) {
                for (int pj = pi + 1; pj < p.size(); pj++) {
                    used[p[pi]][p[pj]]=true;
                }
            }

            if (p.size() >= K) result++;
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
