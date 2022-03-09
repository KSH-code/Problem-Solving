#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int arr[101][101], N;
int xxxx[] = {-1, 0, 1, 0};
int yyyy[] = {0, 1, 0, -1};
int m = 2;
void dfs(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N || arr[x][y] != 1)
        return;

    arr[x][y] = m;
    for (int i = 0; i < 4; i++)
        dfs(x + xxxx[i], y + yyyy[i]);
}

struct Node
{
    int x, y, count;
};

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] != 1)
                continue;
            dfs(i, j);
            m++;
        }
    }

    int result = 9999999;
    for (int i = 2; i < m; i++)
    {
        int counts[N][N];
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                counts[j][k] = 9999999;

        queue<Node> q;

        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (arr[j][k] == i)
                {
                    counts[j][k] = 0;
                    q.push({j, k, 0});
                }

        while (q.size())
        {
            auto [x, y, count] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int next_x = x + xxxx[i];
                int next_y = y + yyyy[i];
                int next_count = count + 1;

                if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N || arr[next_x][next_y] == i || counts[next_x][next_y] <= next_count)
                    continue;
                if (arr[next_x][next_y] > 1)
                {
                    result = min(result, count);
                    continue;
                }

                counts[next_x][next_y] = next_count;
                q.push({next_x, next_y, next_count});
            }
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