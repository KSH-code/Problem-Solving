#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;


void solve(){
  ll N,K,M; cin >>N>>K>>M;

  int bits = 1; for (; (1LL<<bits) <= M; bits++);
  bits += 2;

  int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
  int sparse[K+1][bits+1];
  for (int i = 1; i <= K; i++) cin >> sparse[i][0];
  for (int j = 1; j <= bits; j++) {
    for (int i = 1; i <= K; i++) {
      sparse[i][j] = sparse[sparse[i][j-1]][j-1];
    }
  }

  for (int i = 0; i < N; i++) {
    ll n=M-1,x=arr[i];
    for (int j = bits; j >= 0; j--) {
      if (n>=(1LL<<j)) {
        n -= 1<<j;
        x = sparse[x][j];
      }
    }
    cout << x << ' ';
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();

  return 0;
}
