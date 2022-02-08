#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
pair<ll,ll> tree[(ll)1e6*4+1];
ll arr[(ll)1e6+1];

pair<ll,ll> build(int s, int e, int node) {
  if (s == e) return tree[node] = {arr[s],arr[s]};

  int m = (s+e)/2;
  auto [a,b] = build(s,m,node*2);
  auto [c,d] = build(m+1, e, node * 2 + 1);
  return tree[node] = {min(a,c), max(b,d)};
}

pair<ll,ll> query(int s, int e, int from, int to, int node) {
  if (s > to || e < from) return {1e10, -1};
  if (s >= from && to >= e) return tree[node];

  int m = (s+e)/2;

  auto [a,b] = query(s, m, from, to, node*2);
  auto [c,d] = query(m+1, e, from, to, node*2+1);
  return {min(a,c), max(b,d)};
}

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int N,M,K;
  cin >>N>>M;

  for (int i =1;i<=N;i++) cin >> arr[i];
  build(1,N,1);
  while(M--){
    ll a,b;
    cin >>a>>b;
    auto [x,y] = query(1,N,a,b,1);
    cout << x << " " << y << '\n';
  }
  return 0;
}
