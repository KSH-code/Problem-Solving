#include <bits/stdc++.h>

using pii = std::pair<int,int>;
void solve(){
  int N, K; std::cin >> N >> K;
  std::deque<std::deque<int>> v(K+1);
  int arr[K];
  for (int i = 0; i < K; i++) {
    std::cin >> arr[i];
    v[arr[i]].push_back(i);
  }
  int c = 0;
  std::set<int> s;
  std::priority_queue<pii> q;
  int result = 0;
  for (int i = 0; i < K; i++) {
    while (q.size() && q.top().first <= i && s.count(q.top().second)) q.pop();
    auto c = arr[i];
    if (s.size() == N) {
      if (!s.count(c)) {
        auto [r, n] = q.top();
        s.erase(n);
        q.pop();
        result++;
      }
    }
    s.insert(c);
    v[c].pop_front();
    if (v[c].size()) {
      q.push({v[c][0], c});
    } else {
      q.push({K, c});
    }
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
