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
  for (int i = 1; i <= 1e6;i++)distance[i]=1e6;
  distance[a] = 0;

  int result = 1e7;
  while (q.size()) {
    auto [current_node, count] = q.front();
    q.pop();

    int xxxx[] = {current_node-1, current_node+1, current_node*2};
    for (auto next_node : xxxx) {
      int next_count = count+ (next_node != current_node * 2);
      if (next_node < 0 || distance[next_node] <= next_count || next_node >= 1e5 * 2) continue;
      q.push({next_node, next_count});
      distance[next_node] = next_count;
    }
  }

  cout << distance[b];

  return 0;
}
