#include <iostream>
#include <algorithm>
using namespace std;

bool visited[1000][1000];
int map[1000][1000];

int N, M;
int dfs(int x, int y)
{
  visited[x][y] = true;
  int result = 1;
  int xxxx[] = {-1, 0, 1, 0};
  int yyyy[] = {0, 1, 0, -1};

  for (int i = 0; i < 4; i++)
  {
    int nextX = x + xxxx[i];
    int nextY = y + yyyy[i];

    if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M || visited[nextX][nextY] || map[nextX][nextY] == 0)
      continue;

    result += dfs(nextX, nextY);
  }

  return result;
}

int main()
{

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      visited[i][j] = false;
      cin >> map[i][j];
    }
  }

  int count = 0;
  int maximum = 0;

  for (int i = 0; i < N; i++)

  {
    for (int j = 0; j < M; j++)
    {
      if (visited[i][j] || !map[i][j])
        continue;

      count++;

      maximum = max(maximum, dfs(i, j));
    }
  }

  cout << count << "\n"
       << maximum;

  return 0;
}
