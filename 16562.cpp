#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX = 1e4+1;
pair<int,int> parent[MAX];
bool visited[MAX];

pair<int,int> find(int x) {
  auto [a,b] = parent[x];
  if (a == x) return {a,b};
  auto [c,d] = find(a);
  return parent[x] = {c, min(b,d)};
}

void merge(int x, int y) {
  auto [a,b] = find(x);
  auto [c,d] = find(y);
  if (b < d) parent[c] = {a, min(b,d)};
  else parent[a] = {c, min(b,d)};
}

void solve(){
  int N,M,K; cin >> N>>M>>K;
  for (int i = 1; i <= N; i++) {
    int a; cin >> a;
    parent[i] = {i,a};
  }
  while (M--) {
    int a,b; cin >> a >> b;
    merge(a,b);
  }
  int result = 0;
  for (int i = 1; i <= N; i++) {
    auto [a,b] = find(i);
    if (visited[a]) continue;
    visited[a]=true;
    result+=b;
  }
  if (result <= K) {
    cout << result;
  } else {
    cout << "Oh no";
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
