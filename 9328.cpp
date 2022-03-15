#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

void solve(){
    int N, M; cin >> N >> M;

    bool keys[26];
    for (int i = 0; i < 26; i++) keys[i] = false;

    string map[N]; for (int i =0 ;i < N; i++) cin >> map[i];
    string temp; cin >> temp;
    if (temp != "0") for (int i = 0; i < temp.size(); i++) keys[temp[i] - 'a'] = true;

    int xxxx[4] = {-1, 0, 1, 0};
    int yyyy[4] = {0, 1, 0, -1};

    int result = 0;
    while (1) {
        bool keep = false;
        bool visited[N][M]; for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) visited[i][j] = false;

        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            q.push({i, 0});
            q.push({i, M-1});
        }

        for (int i = 0; i < M; i++) {
            q.push({0,i});
            q.push({N-1,i});
        }

        while (q.size()) {
            auto [x, y] = q.front(); q.pop();
            if (map[x][y] == '*' || map[x][y] >= 'A' && map[x][y] <= 'Z' && !keys[map[x][y] - 'A']) continue;
            if (map[x][y] >= 'a' && map[x][y] <= 'z') {
                keys[map[x][y] -'a'] = true;
                keep = true;
                map[x][y] = '.';
            }
            if (map[x][y] == '$') {
                map[x][y] = '.';
                result++;
            }
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + xxxx[i];
                int ny = y + yyyy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        if (!keep) break;
    }
    cout << result << '\n';
}
int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
