#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll tree[(ll)1e6*4+1];
ll arr[(ll)1e6+1];

ll build(int s, int e, int node) {
  if (s == e) return tree[node] = arr[s];

  int m = (s+e)/2;
  return tree[node] = build(s, m, node * 2) + build(m+1, e, node * 2 + 1);
}

void update(int s, int e, int node, int index, ll diff) {
  if (index < s || index > e) return;

  tree[node] -= diff;
  if (s == e) return;

  int m=(s+e)/2;
  update(s, m, node*2, index, diff);
  update(m+1, e, node*2+1, index, diff);
}

ll query(int s, int e, int from, int to, int node) {
  if (s > to || e < from) return 0;
  if (s >= from && to >= e) return tree[node];

  int m = (s+e)/2;
  return query(s, m, from, to, node*2) + query(m+1, e, from, to, node*2+1);
}

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int N,M;
  cin >>N>>M;

  for (int i =1;i<=N;i++) cin >> arr[i];
  build(1,N,1);
  while(M--){
    ll x,y,a,b;
    cin >>x>>y>>a>>b;
    if (x > y) swap(x,y);

    cout << query(1,N,x,y,1) << '\n';
    ll diff = arr[a] - b;
    update(1,N,1,a,diff);
    arr[a] = b;
  }
  return 0;
}
