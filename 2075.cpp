#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int N; cin >>N;
  int arr[N * N];
  for (int i = 0; i < N * N; i++) cin >> arr[i];
  sort(arr, arr + N * N);
  cout << arr[N * N - N];
  return 0;
}
