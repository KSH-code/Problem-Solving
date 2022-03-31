#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct Node {
  int a,b,c;
};

Node arr[10000];
ll N, K, D;
bool ok(int m) {
  ll count = 0;
  for (int i = 0; i < K; i++) {
    auto [a,b,c] = arr[i];
    if (a > m) continue;
    count+=(min(b,m)-a)/c+1;
  }
  return count < D;
}

void solve(){
  cin >> N >> K >> D;
  for (int i = 0; i< K;i++) cin >>arr[i].a>>arr[i].b>>arr[i].c;

  int l = 0, r = N;
  while(l+1<r){
    int m=(l+r)/2;
    if (ok(m)) l = m;
    else r = m;
  }
  cout << r;
}

int main()
{
  cin.tie(0) -> sync_with_stdio(0);
  solve();
  return 0;
}
