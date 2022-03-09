#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;

struct Node
{
    int x, y, z, count;
};

void solve(int L, int R, int C)
{
    string map[L][R];
    for (int i = 0; i < L; i++)

        for (int j = 0; j < R; j++)
            cin >> map[i][j];

    bool visited[L][R][C];
    queue<Node> q;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < R; j++)
            for (int k = 0; k < C; k++)
                if (map[i][j][k] == 'S')
                    q.push({i, j, k, 0}), visited[i][j][k] = true;
                else
                    visited[i][j][k] = false;

    while (q.size())
    {
        auto [x, y, z, count] = q.front();
        q.pop();
        if (map[x][y][z] == 'E')
        {
            cout << "Escaped in " << count << " minute(s).\n";
            return;
        }
        int xxxx[] = {-1, 1, 0, 0, 0, 0};
        int yyyy[] = {0, 0, 1, 0, -1, 0};
        int zzzz[] = {0, 0, 0, 1, 0, -1};
        for (int i = 0; i < 6; i++)
        {
            int next_x = x + xxxx[i];
            int next_y = y + yyyy[i];
            int next_z = z + zzzz[i];
            if (next_x < 0 || next_x >= L || next_y < 0 || next_y >= R || next_z < 0 || next_z >= C || visited[next_x][next_y][next_z] || map[next_x][next_y][next_z] == '#')
                continue;
            visited[next_x][next_y][next_z] = true;
            q.push({next_x, next_y, next_z, count + 1});
        }
    }
    cout << "Trapped!\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    while (1)
    {
        int L, R, C;
        cin >> L >> R >> C;
        if (L + R + C == 0)
            break;
        solve(L, R, C);
    }
    return 0;
}