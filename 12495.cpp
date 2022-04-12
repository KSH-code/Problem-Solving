#include <iostream>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b) {
  return a*b/gcd(a,b);
}

void solve(){
  int N, L, H; cin >> N >> L >> H;
  int r = 1;
  int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = L; i <= H; i++) {
    bool found = true;
    for (int j = 0; j < N; j++) {
      found &= arr[j]%i==0 || i % arr[j] == 0;
    }
    if (found) {
      cout << i;
      return;
    }
  }
  cout << "NO";
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #"<<i<<": ";
    solve();
    cout << '\n';
  }
  return 0;
}
