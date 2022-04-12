#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

void solve(){
  int N; cin >> N;
  pair<int,int> arr[N];
  for (int i = 0; i < N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr, arr+N);
  priority_queue<int> pq; pq.push(-arr[0].second);
  for (int i = 1; i < N; i++){
    auto [a,b] = arr[i];
    if (a >= -pq.top()) pq.pop();
    pq.push(-b);
  }
  cout << pq.size();
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
