#include <bits/stdc++.h>

void solve(){
  int N; std::cin >> N;
  std::stack<int> st;
  for (int i = 0; i < N; i++) {
    int a; std::cin >> a;
    st.push(a);
  }
  long long result = 0;
  int max = st.top();
  while (st.size()) {
    auto c = st.top(); st.pop();
    if (max > c) {
      result += max - c;
    } else {
      max = std::max(max, c);
    }
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  int T; std::cin >> T;
  while (T--) {
    solve();
    std::cout << '\n';
  }
  return 0;
}
