#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  std::string str; std::cin >> str;

  for (int i = 0; i < N; i++) {
    for (auto c : str) std::cout << c;
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
