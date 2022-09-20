#include <bits/stdc++.h>

const int MAX = 5e5;
int memo[MAX];
int N;
std::string strs[MAX];

int dfs(int s) {
  auto &ref = memo[s];
  if (ref > -1) return ref;

  ref = N - s - 1;
  for (int j = 0; j < strs[s].size(); j++)
  for (int i = s + 1; i < N; i++) {
    bool found = false;
    if (strs[i][j] == strs[s][j]) {
      ref = std::min(ref, i - s - 1 + dfs(i));
      found = true;
    }
    if (found) break;
  }
  return ref;
}

void solve(){
  int K;
  std::cin >> N >> K;
  memset(memo, -1, sizeof memo);
  for (int i = 0; i < N; i++) std::cin >> strs[i];

  int result = MAX;
  for (int i = 0; i < N; i++) {
    result = std::min(result, dfs(i)+i);
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
