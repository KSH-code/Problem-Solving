#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;

struct Node
{
    int x, y, z, day, count;
};

int xxxx[] = {-1, 0, 1, 0};
int yyyy[] = {0, 1, 0, -1};

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    string map[N];
    for (int i = 0; i < N; i++)
        cin >> map[i];

    int counts[N][M][K + 1][2];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k <= K; k++)
                counts[i][j][k][0] = counts[i][j][k][1] = 1e9;

    queue<Node> q;
    q.push({0, 0, 0, 0, 1});
    while (q.size())
    {
        auto [x, y, z, day, count] = q.front();
        q.pop();

        if (x == N - 1 && y == M - 1)
        {
            cout << count;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + xxxx[i];
            int next_y = y + yyyy[i];
            int next_z = z;
            int next_count = count + 1;
            int next_day = (day + 1) % 2;
            if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)
                continue;
            if (map[next_x][next_y] == '1')
            {
                if (next_day)
                    next_z++;
                else
                {
                    next_x -= xxxx[i];
                    next_y -= yyyy[i];
                }
                if (next_z > K)
                    continue;
            }

            if (counts[next_x][next_y][next_z][next_day] <= next_count)
                continue;
            counts[next_x][next_y][next_z][next_day] = next_count;
            q.push({next_x, next_y, next_z, next_day, next_count});
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