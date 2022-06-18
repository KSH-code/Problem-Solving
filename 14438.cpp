#include <iostream>
#include <memory.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5;
int tree[MAX*4];


void update(int start, int end, int node, int index, int diff) {
  if (start > index || index > end) return;
  if (start == end) {
      tree[node] = diff;
      return;
  }
  int m = (start + end) / 2;
  update(start,m,node*2,index,diff);
  update(m+1,end,node*2+1,index,diff);
  tree[node] = min(tree[node*2], tree[node*2+1]);
}
int query(int start, int end, int node, int left, int right) {
  if (start > right || end < left) return 1e9;
  if (left <= start && end <= right) return tree[node];
  int m = (start + end) / 2;
  return min(query(start,m,node*2,left,right), query(m+1,end,node*2+1,left,right));
}

void solve(){
  int N; cin >> N;

    for (int i = 0; i < MAX*4;i++)tree[i] = 1e9;
    for (int i = 1; i <= N; i++) {
        int f; cin >> f;
        update(1,N,1,i,f);
    }

    int M; cin >> M;
    while (M--) {
        int a,b,c;cin>>a>>b>>c;
        if (a&1) {
            update(1,N,1,b,c);
        } else {
            cout << query(1,N,1,b,c) << '\n';
        }
    }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}
