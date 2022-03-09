#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

struct Node
{
    int x, y, z, count;
};

int xxxx[] = {-1, 0, 1, 0};
int yyyy[] = {0, 1, 0, -1};

void solve()
{
    int N, M, K;
    cin >> K >> M >> N;
    int map[N][M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    int counts[N][M][K + 1];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k <= K; k++)
                counts[i][j][k] = 1e9;

    queue<Node> q;
    q.push({0, 0, 0, 0});
    while (q.size())
    {
        auto [x, y, z, count] = q.front();
        if (x == N - 1 && y == M - 1)
        {
            cout << count;
            return;
        }
        int next_count = count + 1;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + xxxx[i];
            int next_y = y + yyyy[i];
            if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M || map[next_x][next_y] == 1)
                continue;
            if (counts[next_x][next_y][z] <= next_count)
                continue;
            counts[next_x][next_y][z] = next_count;
            q.push({next_x, next_y, z, next_count});
        }
        if (z + 1 <= K)
        {
            int xxxxxxxx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
            int yyyyyyyy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
            for (int i = 0; i < 8; i++)
            {
                int next_x = x + xxxxxxxx[i];
                int next_y = y + yyyyyyyy[i];
                int next_z = z + 1;
                if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M || map[next_x][next_y] == 1)
                    continue;
                if (counts[next_x][next_y][next_z] <= next_count)
                    continue;
                counts[next_x][next_y][next_z] = next_count;
                q.push({next_x, next_y, next_z, next_count});
            }
        }
    }
    cout << -1;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}