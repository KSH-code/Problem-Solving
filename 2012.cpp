#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);int N;
  cin >>N;int arr[N];for(int i=0;i<N;i++)cin >>arr[i];
  bool visited[N+1];
  for (int i=0;i<=N;i++) visited[i]=false;
  for (int i=0;i<N;i++) {
    if (N<arr[i]) continue;
    if (visited[arr[i]]) continue;
    visited[arr[i]]=true;
    arr[i] = 99999999;
  }
  sort(arr,arr+N);

  int j=1;
  ll result=0;
  for (int i =0;i<N;i++) {
    if (arr[i] == 99999999) break;
    while (visited[j]) j++;
    result += abs(j-arr[i]);
    visited[j]=true;
  }

  cout <<result;
  return 0;
}
