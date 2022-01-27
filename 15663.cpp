#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int arr[100];
void dfs(int *data, int count) {
  if(count==M) {
    for (int i =0;i<M;i++) cout << data[i] << " ";
    cout <<"\n";
    return;
  }

  for (int i = 0; i<N;i++) {
    bool found = false;
    for (int j =0; j < count; j++) found = found || data[j] > arr[i];
    if (found) continue;

    data[count] = arr[i];
    dfs(data, count + 1);
    while (i < N && arr[i] == arr[i+1]) i++;
  }
}
int main(){
  cin >>N>>M;
  for (int i =0;i<N;i++) cin>>arr[i];sort(arr,arr+N);
  int data[N];
  dfs(data,0);
  return 0;
}
