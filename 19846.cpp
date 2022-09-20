#include <bits/stdc++.h>

void solve(){
  // alpha, length, query;
  int N, M, Q; std::cin >> N >> M >> Q;

  int c = 0;
  std::string str = "";
  for (int i = 0; i < M; i++) {
    str += 'a' + c;
    if (i & 1) c = (c + 1) % N;
  }
  std::cout << str;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
