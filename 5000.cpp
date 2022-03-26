#include <iostream>
#include <memory.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5;
int tree[MAX*4];


void update(int start, int end, int node, int index) {
  if (start > index || index > end) return;
  tree[node] = (tree[node] + 1)%2;
  if (start == end) return;
  int m = (start + end) / 2;
  update(start,m,node*2,index);
  update(m+1,end,node*2+1,index);
}
int query(int start, int end, int node, int left, int right) {
  if (start > right || end < left) return 0;
  if (left <= start && end <= right) return tree[node];
  int m = (start + end) / 2;
  return query(start,m,node*2,left,right) + query(m+1,end,node*2+1,left,right);
}

void solve(){
  int N; cin >> N;
  int arr[N+1];

  int A = 0, B = 0;
  for (int i = 0; i < N; i++) {
    int a; cin >> a; arr[a] = i;
  }
  for (int i = N; i >= 1; i--) {
    int idx = arr[i];
    A += query(0,N-1,1,0,idx);
    update(0,N-1,1,idx);
  }
  memset(tree,0,sizeof(tree));

  for (int i = 0; i < N; i++) {
    int a; cin >> a; arr[a] = i;
  }
  for (int i = N; i >= 1; i--) {
    int idx = arr[i];
    B += query(0,N-1,1,0,idx);
    update(0,N-1,1,idx);
  }

  cout << (A%2 == B%2 ? "Possible" : "Impossible");
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}
