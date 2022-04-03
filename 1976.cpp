#include <iostream>
using namespace std;

typedef long long ll;

const int MAX = 2e2+1;
int parent[MAX];

int find(int x) {
  if (parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
  int px = find(x), py = find(y);
  parent[px] = py;
}

void solve(){
  int N; cin >> N;
  int M; cin >> M;
  for (int i = 1; i <= N; i++) parent[i] = i;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int a;cin>>a; if (a)merge(j, i);
    }
  }
  int prev; cin >> prev;
  bool found = false;
  for (int i = 1; i < M; i++) {
    int a; cin >> a;
    found |= find(a) != find(prev);
    prev = a;
  }
  cout << (found ? "NO" : "YES");
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
