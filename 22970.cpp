#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

void solve(){
  int N;cin >> N;
  int arr[N];
  for(int i=0;i<N;i++)cin >> arr[i];
  int result = 1;
  for (int i = 0; i < N-1; i++) {
    int prev = arr[i];
    int count = 1;
    bool up=arr[i] < arr[i+1];
    for (int j=i+1;j <N; j++) {
      if (up && prev > arr[j])up=false;
      if (up && prev < arr[j]) {
        prev = arr[j];
        count++;
      } else if (!up && prev > arr[j]) {
        prev = arr[j];
        count++;
      } else {
        break;
      }
    }
    result = max(result, count);
  }
  cout << result;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
