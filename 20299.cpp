#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int N, K, B; cin >> N >> K >> B;

  vector<int> z;
  for (int i = 0; i < N; i++) {
    int a,b,c;
    cin >> a >> b >> c;
    if (a + b + c < K) continue;
    if (a < B || b < B || c < B) continue;

    z.push_back(a);
    z.push_back(b);
    z.push_back(c);
  }

  cout << (z.size() / 3) << "\n";
  for (int a : z) cout << a << " ";

  return 0;
}
