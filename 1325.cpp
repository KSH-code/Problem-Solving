#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> edges(N + 1);

  while (M--)
  {
    int A, B;
    cin >> A >> B;
    edges[B].push_back(A);
  }

  int max_count = 0;
  vector<int> result;

  for (int i = 1; i <= N; i++)
  {
    queue<int> q;
    q.push(i);
    bool visited[N + 1] = {false};
    visited[i] = true;
    int count = 0;
    while (q.size())
    {
      auto cur = q.front();
      count++;
      for (auto next : edges[cur])
      {
        if (!visited[next])
          q.push(next);
        visited[next] = true;
      }
      q.pop();
    }

    if (max_count < count)
    {
      max_count = count;
      result.clear();
    }
    if (max_count <= count)
      result.push_back(i);
  }

  for (auto r : result)
    cout << r << " ";

  return 0;
}
