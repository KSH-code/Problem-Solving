#include <iostream>
using namespace std;

typedef long long ll;
ll tree[(ll)1e6*4+1];
ll arr[(ll)1e6+1];
ll mod = 1e9+7;

ll build(int s, int e, int node) {
  if (s == e) return tree[node] = arr[s];

  int m = (s+e)/2;
  return tree[node] = (build(s, m, node * 2) * build(m+1, e, node * 2 + 1)) % mod;
}

ll update(int s, int e, int node, int index, ll diff) {
  if (index < s || index > e) return tree[node];

  if (s == e) return tree[node] = diff;

  int m=(s+e)/2;
  return tree[node] = (update(s, m, node*2, index, diff) * update(m+1, e, node*2+1, index, diff)) % mod;
}

ll query(int s, int e, int from, int to, int node) {
  if (s > to || e < from) return 1;
  if (s >= from && to >= e) return tree[node];

  int m = (s+e)/2;
  return (query(s, m, from, to, node*2) * query(m+1, e, from, to, node*2+1)) % mod;
}

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int N,M,K;
  cin >>N>>M>>K;

  for (int i =1;i<=N;i++) cin >> arr[i];
  build(1,N,1);
  M+=K;
  while(M--){
    ll a,b,c;
    cin >>a>>b>>c;

    if (a==1){
      update(1,N,1,b,c);
      arr[b] = c;
    } else {
      cout << query(1,N,b,c,1) << '\n';
    }
  }
  return 0;
}
