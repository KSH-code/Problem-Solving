#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  int arr[N]; for (auto &a : arr) std::cin >> a;

  bool yes = true;
  for (int i = 0; i < N; i++) {
    yes &= (i & 1 ? arr[i] % 2 == 0 : arr[i] % 2 == 1);
  }
  std::cout << (yes ? "YES" : "NO");
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
