#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  std::string strs[N];
  for (auto &s : strs) std::cin >> s;

  int max = 0;
  int start = 0;
  for (int i = 0; i < N; i++) {
    int c = 0;
    for (int j = 0; j < N; j++) {
      if(strs[i][j] == '+')c++;
    }
    if (c >= max) start = i;
  }
  std::stack<int> s; s.push(start);
  std::vector<int> result;
  std::set<int> duplicate;
  while (s.size()) {
    int x = s.top(); s.pop();
    result.push_back(x+1);
    for (int i = 0; i < N; i++) {
      if (strs[x-1][i] == '+') {
        s.push(i);
      }
    }
  }
  if (reuslt.size() == N) {
    for (auto c : result) std::cout << c << ' ';
  } else std::cout << -1;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
