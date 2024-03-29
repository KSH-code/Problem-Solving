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

  int N; cin >> N;
  int arr[N];
  for (int i = 0; i < N; i++) cin >> arr[i];

  int lis[N];
  int indices[N];
  int index = 0;
  for (int i = 0; i < N; i++) {
    if (index == 0 || lis[index-1] < arr[i]) {
      indices[i] = index;
      lis[index++] = arr[i];
    } else {
      int j = lower_bound(lis, lis + index, arr[i]) - lis;
      indices[i] = j;
      lis[j] = arr[i];
    }
  }

  cout << index << "\n";
  vector<int> ans;
  for (int i = N - 1; i >= 0; i--) {
    if (indices[i] == index - 1) {
      index--;
      ans.push_back(arr[i]);
    }
  }

  reverse(ans.begin(), ans.end());
  for (auto c : ans) cout << c << " ";
  return 0;
}
