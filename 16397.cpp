#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int n, count;
};

const int INF = 99999;

int transform(int x) {
    string str = to_string(x);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0') {
            return x - pow(10, str.size() - 1 - i);
        }
    }
    return x;
}

void solve(){
    int N,T,G; cin >> N>>T>>G;

    queue<Node> q;

    bool visited[100001]; memset(visited, 0, sizeof(visited));
    visited[N] = true;

    if (N == G) {
        cout << 0;
        return;
    }

    q.push({N, 0});
    while (q.size()) {
        auto [x, count] = q.front(); q.pop();
        int next_count = count + 1;
        if (next_count > T) continue;

        if (x + 1 <= INF) {
            int next_x = x + 1;
            if (!visited[next_x]) {
                if (G == next_x) {
                    cout << next_count;
                    return;
                }
                visited[next_x] = true;
                q.push({next_x, next_count});
            }
        }

        if (x * 2 <= INF) {
            int next_x = transform(x * 2);
            if (!visited[next_x]) {
                if (G == next_x) {
                    cout << next_count;
                    return;
                }
                visited[next_x] = true;
                q.push({next_x, next_count});
            }
        }
    }

    cout << "ANG";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
