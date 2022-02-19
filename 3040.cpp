#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int arr[9];
  int f = 0;
  for (int i = 0; i < 9; i++) cin >> arr[i], f += arr[i];

  int x, y;
  for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) if (i != j && f - arr[i] - arr[j] == 100) x = i, y = j;
  for (int i = 0; i < 9; i++) if (i != x && i != y) cout << arr[i] << "\n";
  return 0;
}
