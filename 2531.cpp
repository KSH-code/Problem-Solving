#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
void solve(){
  int N, d, K, c; cin >> N >> d >> K >> c;
  int arr[N+d]; for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = 0; i < d; i++) arr[N+i] = arr[i];

  int l = -1, r = 0;
  int counts[9999] = {0};
  counts[arr[0]]++;
  int result = 0;
  while (r+1 < N+d) {
    int z = 0;
    for (int i = 1; i <= d; i++) if (counts[i] || (r - l == K && i==c)) z++;
    result = max(result, z);
    if (r - l == K) {
      counts[arr[++l]]--;
      counts[arr[++r]]++;
    } else {
      counts[arr[++r]]++;
    }
  }

  cout << result;
}

int main()
{
  solve();
  return 0;
}
