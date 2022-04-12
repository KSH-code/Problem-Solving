#include <iostream>
#include <memory.h>
using namespace std;

typedef long long ll;

void solve(){
  int N,L; cin >> N >> L;
  int t = 0;
  bool check[2000]; memset(check, 0, sizeof(check));
  while (N--) {
    int c; cin >> c;
    check[c] = true;
  }
  for (int i = 1; i <= 1000; i++) {
    if (check[i]) {
      t++;
      i+=L-1;
    }
  }
  cout << t;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
