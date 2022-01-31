#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[100];
void dfs(int *data, bool *visited, int count)
{
  if (count == M)
  {
    for (int i = 0; i < M; i++)
      cout << data[i] << " ";
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++)
  {
    if (visited[i])
      continue;

    data[count] = arr[i];
    visited[i] = true;
    dfs(data, visited, count + 1);
    visited[i] = false;

    while (i < N && data[count] == arr[i + 1])
      i++;
  }
}
int main()
{
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  sort(arr, arr + N);
  int data[N];
  bool visited[N];
  for (int i = 0; i < N; i++)
    visited[i] = false;
  dfs(data, visited, 0);
  return 0;
}
