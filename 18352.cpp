#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int N,M,K,X;
  cin >>N>>M>>K>>X;

  vector<vector<int>> adj(N+1);
  while(M--) {
    int s,e;
    cin >>s>>e;
    adj[s].push_back(e);
  }

  queue<pair<int,int>> q;
  q.push({X,0});

  bool visited[N+1];
  for (int i = 1; i<= N;i++)visited[i]=false;
  visited[X] = true;


  vector<int> result;
  while (q.size()) {
    auto [current_node, count] = q.front();
    q.pop();

    if (count == K) {
      result.push_back(current_node);
      continue;
    }

    for (auto next_node : adj[current_node]) {
      if (visited[next_node]) continue;

      q.push({next_node, count+1});
      visited[next_node] = true;
    }
  }

  if (result.size() == 0) {
    cout << -1;
  } else {
    sort(result.begin(), result.end());
    for (auto node : result) {
      cout << node << " ";
    }
  }
  return 0;
}
