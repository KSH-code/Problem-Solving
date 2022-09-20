#include <bits/stdc++.h>


#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

const int MAX = 3e5;
std::vector<std::vector<int>> edges(MAX+1);
int parents[MAX+1];
bool visited[MAX+1];
int c;
void dfs(int x) {
  if (parents[x] == x) return;
  if (visited[x]) return;
  visited[x] = true;
  while (edges[x].size()) {
    int l = edges[x].back();
    edges[x].pop_back();
    dfs(l);
  }
  c++;
  std::cout << 1 << ' ' << x << ' ' << parents[x] << '\n';
}

void solve(){
  int N, M; std::cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    std::cin >> parents[i];
    edges[parents[i]].push_back(i);
  }
  int K; std::cin >> K;
  std::cout << N << ' ' << M << '\n';
  for (int i = 0; i < K; i++) {
    int t;
    std::cin >> t;
    std::cout << 2 << ' ' << t << '\n';
  }
  for (int i = 1; i <= N; i++) dfs(i);
  if (K + c != M) {
    int z = 0;
    for (int i = 1; i <= N; i++) if (parents[i] == i) z = i;
    while (K + c != M) {
      std::cout << 1 << ' ' << z << ' ' << z << '\n';
      c++;
    }
  }
}

int main(){
  std::cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}
