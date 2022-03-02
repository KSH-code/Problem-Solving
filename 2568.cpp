#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int T; cin >> T;
  int N = 500001;
  int arr[N + 1]; for (int i = 0; i <= N; i++) arr[i] = -1e9;
  for (int i = 0; i < T; i++) {
    int a, b; cin >> a >> b;
    arr[a] = b;
  }

  int lis[N+1];
  int indices[N+1];
  int index = 0;
  for (int i = 0; i <= N; i++) {
    if (index == 0 || lis[index-1] < arr[i]) {
      indices[i] = index;
      lis[index++] = arr[i];
    } else {
      int j = lower_bound(lis, lis + index, arr[i]) - lis;
      indices[i] = j;
      lis[j] = arr[i];
    }
  }
  vector<int> ans;
  for (int i = N; i >= 1; i--) {
    if (indices[i] == index - 1) {
      index--;
    } else {
      if (arr[i] != -1e9) ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  reverse(ans.begin(), ans.end());
  for (auto c : ans) cout << c << "\n";
  return 0;
}
