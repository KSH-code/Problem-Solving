#include <bits/stdc++.h>

using ll = long long;
ll memo[101][200][200];

const int MAX = 200;
int N, M;
std::string strs[200], str;
int xxxx[] = {-1,-1,-1,0,1,1,1,0};
int yyyy[] = {-1,0,1,1,1,0,-1,-1};

ll dfs(int c, int x, int y) {
  if (c == str.size()) return 1;

  auto &ref = memo[c][x][y];
  if (ref > -1) return ref;

  ref = 0;
  for (int i = 0; i < 8; i++) {
    auto nx = x + xxxx[i];
    auto ny = y + yyyy[i];
    if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
    if (strs[nx][ny] != str[c]) continue;
    ref += dfs(c+1, nx, ny);
  }

  return ref;
}

void solve(){
  memset(memo, -1, sizeof memo);
  int K;
  std::cin >> N >> M >> K;
  for (int i = 0; i < N; i++) std::cin >> strs[i];
  std::cin >> str;
  ll result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (strs[i][j] == str[0]) result += dfs(1, i, j);
    }
  }
  std::cout << result;
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
