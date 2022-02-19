#include <iostream>
#include <algorithm>
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

  int result = 1;
  int temp = 1;
  for (int i = 1; i < N; i++) if (arr[i] >= arr[i-1]) temp++; else result = max(result, temp), temp = 1;
  result = max(temp, result);
  temp = 1;
  for (int i = N - 2; i >= 0; i--) if (arr[i] >= arr[i+1]) temp++; else result = max(result, temp), temp = 1;

  cout << max(temp, result);
  return 0;
}
