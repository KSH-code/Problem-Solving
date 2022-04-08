#include <iostream>
using namespace std;

void solve(){
  int N; cin >> N;
  int result = 0;
  for (int i = 1; i*i <= N; i++) {
    if (N % i == 0) result += 2;
    if (i*i==N) result--;
  }
  cout << result;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
