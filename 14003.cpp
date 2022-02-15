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
      indices[index] = i;
      lis[index++] = arr[i];
    } else {
      int j = lower_bound(lis, lis + index, arr[i]) - lis;
      indices[j] = i;
      lis[j] = arr[i];
    }
  }

  cout << index << "\n";
  for (int i = 0; i < index; i++) cout << arr[indices[i]] <<  " ";
  return 0;
}
