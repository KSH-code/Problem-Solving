#include <bits/stdc++.h>

void solve(){
  int T, N; std::cin >> T >> N;
  std::pair<int,int> arr[N];
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i].first;
    arr[i].second = i;
  }
  std::sort(arr,arr+N);
  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  int idx = 0;
  int results[N];
  for (; idx < 2 && idx < N; idx++) {
    q.push(arr[idx].first);
    results[arr[idx].second] = 0;
  }
  for (int i = 1; i <= T; i++) {
    while (q.size() && q.top() <= i) q.pop();
    while (q.size() < 2 && idx < N) {
      results[arr[idx].second] = i;
      q.push(arr[idx++].first + i);
    }
  }
  for (int i = 0; i < N; i++) std::cout << results[i] << ' ';
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
