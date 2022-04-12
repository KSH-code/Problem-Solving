#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

void solve(){
  int N,K; cin >> N >> K;

    for (int j =0; j <N;j++) {
  for (int i = 1; i <= N; i++) {
      int T = i + j*N;
      int count = 0;
      for (int k = 1; k*k<=T; k++) {
        if (T==k*k) count++;
        else if (T % k == 0) count+=2;
      }
      cout << (count <= K ? '*' : '.');
    }
    cout << '\n';
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
