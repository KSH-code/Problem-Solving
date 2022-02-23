#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

struct Node {
    int weight, x, y, count;
};

struct Compare {
    bool operator()(const Node& m1, const Node& m2) {
        return m1.weight >= m2.weight;
    }
};

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    int SX, SY, EX, EY; cin >> SX >> SY >> EX >> EY;

    int map[N+1][M+1];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> map[i][j];

    int weights[N+1][M+1][3];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) for (int k = 0; k < 3; k++) weights[i][j][k] = 1e8;

    queue<Node> q;
    q.push({0, SX, SY, 1});
    while (q.size()) {
        Node n = q.front();
        q.pop();

        int xxxx[3][4] = {
            {0, -1, 0, 1},
            {-1, 1, 0, 0},
            {0, 0, 0, 0}
        };
        int yyyy[3][4] = {
            {1, 0, -1, 0},
            {0, 0, 0, 0},
            {1, -1, 0, 0}
        };
        int d = n.count % 3;
        for (int i = 0; i < 4; i++) {
            int nx = n.x + xxxx[d][i];
            int ny = n.y + yyyy[d][i];
            if (nx == n.x && ny == n.y) continue;
            if (nx < 1 || nx > N || ny < 1 || ny > M || map[nx][ny] == -1) continue;
            if (weights[nx][ny][d] > n.weight + map[nx][ny]) {
                weights[nx][ny][d] = n.weight + map[nx][ny];
                q.push({n.weight + map[nx][ny], nx, ny, n.count + 1});
            }
        }
    }

    int result = 1e8;
    for (int i = 0; i < 3; i++) result = min(result, weights[EX][EY][i]);
    cout << (result == 1e8 ? -1 : result);
    return 0;
}
