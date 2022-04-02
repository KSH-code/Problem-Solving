#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
int N, K; int arr[1001];
int counts[1001];

int parent[1001];
int mark[1001];
int cycle[1001];
int no_cycle[1001];

int m;
void dfs(int x) {
  if (!parent[x] && parent[arr[x]]) {
    parent[x] = parent[arr[x]];
    no_cycle[parent[x]]++;
    return;
  }
  if (counts[x] == 2) return;
  counts[x]++;
  parent[x] = m;
  parent[arr[x]] = m;
  if (counts[x] == 1) no_cycle[m]++;
  if (counts[x] == 2) cycle[m]++;

  dfs(arr[x]);
}

void solve(){
  cin >> N >> K;for (int i = 1; i <= N; i++) cin >> arr[i];
  for (int i = 1; i <= N; i++) {
    m = i;
    if (!parent[i]) dfs(i);
  }

  bool visited[1001] = {0};
  visited[0] = true;
  for (int i = 1; i <= N; i++) {
    for (int j = K; j >= 0; j--) {
      for (int w = cycle[i]; w <= no_cycle[i]; w++) {
        if (j >= w) visited[j] |= visited[j - w];
      }
    }
  }
  for (int i = K; i >= 0; i--) {
    if (visited[i]) {
      cout << i;
      break;
    }
  }
}

int main()
{
  solve();
  return 0;
}
