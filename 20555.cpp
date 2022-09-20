#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  std::vector<std::string> v(N);
  for (auto &s : v) std::cin >> s;
  while (1) {
    int counts[4]; memset(counts, 0, sizeof counts);
    for (char i = 'A'; i <= 'D'; i++) {
      for (auto s : v) {
        int temp[4]; memset(temp, 0, sizeof temp);
        for (auto c : s) {
          temp[c] +=
        }
      }
    }
    int i = std::max_element(counts, counts+4) - counts;
    if (!counts[i]) break;
    std::cout << (char)('A' + i);
    for (auto &s : v) {
      if (s.size() && s[0] == 'A' + i) s.erase(0, 1);
    }
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
