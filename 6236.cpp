#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve(){
  int N,M; cin >> N>>M;
  int arr[N]; for (int i = 0; i< N;i++) cin >> arr[i];
  int l=*max_element(arr, arr+N)-1,r=1e9;
  int result = 1e9;
  while(l+1<r){
    int m=(l+r)/2;
    int count = 0;
    int remains = 0;
    for (int i = 0; i < N; i++) {
      if (remains < arr[i]) remains = m, count++;
      remains -= arr[i];
    }
    if (count > M) l = m;
    else r = m;
  }
  cout << r;
}

int main()
{
  cin.tie(0) -> sync_with_stdio(0);
  solve();
  return 0;
}
