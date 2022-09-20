#include <bits/stdc++.h>

using ll = long long;

ll translate(const std::string &str) {
  ll result = 0;
  for (auto c : str) {
    result *= 2;
    result += c - '0';
  }
  return result;
}

void solve(){
  ll K; std::cin >> K;
  std::string str; std::cin >> str;
  int result = 0;
  while (translate(str) > K) {
    bool go = false;
    for (int i = 0; i < str.size(); i++) {
      if ((i == 0 && str[i] == '1' && str[i + 1] == '1') || (i != 0 && str[i] == '1')) {
        str.erase(i, 1);
        go = true;
        break;
      }
    }
    if (!go) str.erase(str.size() - 1);
    result++;
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
