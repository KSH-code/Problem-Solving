#include <iostream>
#include <queue>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int N, K; cin >> N >> K;

  queue<pair<int,int>> q;
  int MAX = 1e5+100;
  pair<int,int> counts[MAX]; for (int i = 0; i < MAX; i++) counts[i] = {9999999,0};
  counts[N] = {0, 0};
  q.push({N,0});

  int result = 0;
  while (q.size()) {
    auto [x, count] = q.front(); q.pop();
    if (counts[x].first == count) counts[x].second++;

    int next_count = count+1;

    int xxx[3] = {x*2, x-1, x+1};
    for (int i = 0; i < 3; i++) {
      int next_x = xxx[i];
      if (next_x < 0 || next_x >= MAX || counts[next_x].first < next_count) continue;
      if (counts[next_x].first > next_count) counts[next_x] = {next_count, 0};
      q.push({next_x, next_count});
    }
  }

  cout << counts[K].first << '\n';
  cout << counts[K].second;
  return 0;
}
