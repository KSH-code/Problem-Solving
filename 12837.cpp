#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAX = 1e6+1;
ll tree[MAX*4];

void update(int s, int e, int node, int index, ll diff) {
  if (index < s || index > e) return;

  tree[node] += diff;
  if (s == e) return;

  int m=(s+e)/2;
  update(s, m, node*2, index, diff);
  update(m+1, e, node*2+1, index, diff);
}

ll query(int s, int e, int node, int from, int to) {
  if (s > to || e < from) return 0;
  if (s >= from && to >= e) return tree[node];

  int m = (s+e)/2;
  return query(s, m, node*2, from, to) + query(m+1, e, node*2+1, from, to);
}

void solve() {
  int N, M; cin >> N>>M;
  for (int i = 0; i < M; i++) {
    ll a,b,c;cin>>a>>b>>c;
    if (a==1) {
      update(1,N,1,b,c);
    } else {
      cout << query(1,N,1,b,c) << '\n';
    }
  }
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);

  solve();
  return 0;
}
