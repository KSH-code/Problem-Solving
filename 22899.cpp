#include <bits/stdc++.h>

using pii = std::pair<int,int>;

void solve(){
  int N, K;
  std::cin >> N >> K;
  std::set<int> s;
  int arr1[N]; for (auto &a : arr1) {
    std::cin >> a;
    s.insert(a);
  }
  int arr2[N]; for (auto &a : arr2) std::cin >> a;

  pii arr[N]; for (int i = 0; i < N; i++) arr[i] = {arr2[i], arr1[i]};
  sort(arr,arr+N);
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> store;
  std::priority_queue<pii> pop_store;
  std::map<int,int> counts;
  for (int i = 0; i < N; i++) {
    auto [a,b] = arr[i];
    counts[b]++;
    store.push({counts[b], a});
  }
  int count = 0;
  long long result = 0;
  for (int i = 1; i <= N; i++) {
    while (store.size()) {
      auto [a,b] = store.top();
      if (a > i) break;
      store.pop();
      result += b;
      count++;
      if (count > K) {
        auto [c,d] = pop_store.top();
        if (b < c) {
          pop_store.pop();
          result -= c;
        } else {
          result -= b;
          continue;
        }
      }
      pop_store.push({b,a});
    }
    if (count < K) std::cout << -1 << ' ';
    else std::cout << result << ' ';
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
