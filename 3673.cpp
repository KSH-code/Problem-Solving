#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int T; cin >> T;
  while(T--) {
    ll N, M; cin >> M >> N;
    map<int, int> mp; mp[0] = 1;
    ll s = 0;
    ll result = 0;
    for (int i = 0; i < N; i++) {
      ll a; cin >> a; s+= a;
      s %= M; result += mp[s]++;
    }
    cout << result << '\n';
  }
  return 0;
}
