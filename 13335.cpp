#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
  int weight, finish_time;
};

int main(){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int N,W,L; cin >> N >> L >> W;

  int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
  queue<int> q; for (int i = 0; i < N; i++) q.push(arr[i]);
  queue<node> cur_q;
  int current_time = 0;
  int current_weight = 0;

  while (q.size()) {
    int w = q.front();
    while (current_weight + w > W) {
      current_weight -= cur_q.front().weight;
      current_time = max(current_time, cur_q.front().finish_time - 1);
      cur_q.pop();
    }
    current_weight += w;

    current_time++;
    cur_q.push({w, current_time + L});

    q.pop();
  }

  while (cur_q.size()) {
    current_time = cur_q.front().finish_time;
    cur_q.pop();
  }

  cout << current_time;

  return 0;
}
