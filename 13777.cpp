#include <iostream>
using namespace std;
typedef long long ll;

bool solve (){
  int N;
  cin >> N;
  if (!N) return false;

  int l = 1, r = 50;
  while (l <= r) {
    int m = (l + r) / 2;
    cout << m << ' ';
    if (m == N) break;
    if (m > N) r = m - 1;
    else l = m + 1;
  }
  cout << '\n';

  return true;
}
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cout.tie(0);
  while (solve());
  return 0;
}
