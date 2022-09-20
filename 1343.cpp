#include <bits/stdc++.h>

void solve(){
  std::string str; std::cin >> str;
  int t = 0;
  std::string result = "";
  for (auto c : str) {
    if (c == 'X') t++;
    else {
      if (t == 2) {
        t = 0;
        result += "BB";
      } else if (t) {
        std::cout << -1;
        return;
      }
      result += ".";
    }
    if (t == 4) {
      t = 0;
      result += "AAAA";
    }
  }
  if (t == 2) {
    t = 0;
    result += "BB";
  }
  if (t || result.size() != str.size()) {
    std::cout << -1;
  } else {
    std::cout << result;
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
