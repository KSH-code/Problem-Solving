#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  int arr[N];
  for (auto &a : arr) std::cin >> a;
  long long result = 1;
  for (int i = N-1; i >= 0; i--) {
    auto t = arr[i];
    if (result % t != 0) {
      result += t - result % t;
    }
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
