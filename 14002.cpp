#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  int arr[N];
  for (int i = 0; i < N; i++) cin >> arr[i];

  vector<vector<int>> list(N);
  int dp[N];
  for (int i = 0; i < N; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j] && dp[i] <= dp[j]) {
        list[i] = list[j];
        dp[i] = dp[j] + 1;
      }
    }
    list[i].push_back(arr[i]);
  }

  vector<int> result;
  for (int i = 0; i < N; i++) if (result.size() < list[i].size()) result = list[i];
  cout << result.size() << "\n";
  for (auto n : result) cout << n << " ";
  return 0;
}
