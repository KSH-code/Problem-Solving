#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  std::pair<int,int> arr[N]; for (auto &[x,y]:arr) std::cin>>x>>y;
  std::sort(arr,arr+N);

  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  int result = 0;
  int count = 0;
  for (auto [x,y] : arr) {
    q.push(y);
    while (q.size() && q.top() <= x) q.pop();
    result = std::max(result, (int)q.size());
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
