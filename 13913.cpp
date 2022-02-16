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

  int a,b;
  cin >>a>>b;

  queue<pair<int,int>> q;
  q.push({a,0});

  int distance[(int)1e6];
  int visited[(int)1e6];
  for (int i = 0; i <= 1e6;i++)distance[i]=1e6;
  distance[a] = 0;

  int result = 1e7;
  while (q.size()) {
    auto [current_node, count] = q.front();
    q.pop();

    int xxxx[] = {current_node-1, current_node+1, current_node*2};
    for (auto next_node : xxxx) {
      int next_count = count + 1;
      if (next_node < 0 || distance[next_node] <= next_count || next_node >= 1e5 * 2) continue;
      q.push({next_node, next_count});
      distance[next_node] = next_count;
      visited[next_node] = current_node;
    }
  }

  cout << distance[b] << "\n";

  vector<int> path;
  path.push_back(b);
  int c = b;
  while (path.back() != a) {
    path.push_back(visited[c]);
    c = visited[c];
  }

  reverse(path.begin(), path.end());

  for (auto p : path) {
    cout << p << " ";
  }

  return 0;
}
