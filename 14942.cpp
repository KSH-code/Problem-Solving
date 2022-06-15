#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 19;

void solve(){
  int N; cin >> N;
  int arr[N+1]; for (int i = 1; i <= N; i++) cin >> arr[i];

  vector<vector<pair<int,int>>> edges(N+1);
  for (int i = 1; i < N; i++) {
    int u,v,w; cin >> u >> v >> w;
    edges[u].push_back({v,w});
    edges[v].push_back({u,w});
  }

  queue<int> q;
  q.push(1);
  pair<int,int> parent[N+1]; for (int i = 1; i <= N; i++) parent[i] = {-1,-1};
  while (q.size()) {
    auto x = q.front(); q.pop();
    for (auto [nx, w] : edges[x]) {
      if (parent[nx].first != -1) continue;
      parent[nx] = {x,w};
      q.push(nx);
    }
  }

  pair<int,int> energy[MAX][N+1];

  for (int i = 0; i < MAX; i++) for (int j = 1; j <= N; j++) energy[i][j] = {-1,-1};

  for (int i = 2; i <= N; i++) {
    energy[0][i] = parent[i];
  }

  for (int j = 1; j < MAX; j++) {
    for (int i = 1; i <= N; i++) {
      auto [a,b] = energy[j-1][i];
      if (a == -1) continue;
      auto [c,d] = energy[j-1][a];
      if (c == -1) continue;
      energy[j][i] = {c,b+d};
    }
  }

  for (int i = 1; i <= N; i++) {
    int result = i;
    int &remain = arr[i];
    for (int j = MAX-1; j >= 0; j--) {
      if (result == 1) continue;
      auto [next, required] = energy[j][result];
      if (next == -1) continue;
      if (required <= remain) {
        result = next;
        remain -= required;
        j++;
      }
    }

    cout << result << '\n';
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();

  return 0;
}
