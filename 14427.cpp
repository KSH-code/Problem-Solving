#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


const int MAX = 1e5;
pair<int,int> tree[MAX*4];

void update(int start, int end, int node, int index, int diff) {
  if (start > index || index > end) return;
  if (start == end) {
      tree[node] = {diff,index};
      return;
  }
  int m = (start + end) / 2;
  update(start,m,node*2,index,diff);
  update(m+1,end,node*2+1,index,diff);
  tree[node] = min(tree[node*2], tree[node*2+1]);
}
pair<int,int> query(int start, int end, int node, int left, int right) {
  if (start > right || end < left) return {1e9,1e9};
  if (left <= start && end <= right) return tree[node];
  int m = (start + end) / 2;
  return min(query(start,m,node*2,left,right), query(m+1,end,node*2+1,left,right));
}

void solve(){
    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        int f; cin >> f;
        update(1,N,1,i,f);
    }

    int M; cin >> M;
    while (M--) {
        int a; cin >> a;
        if (a&1) {
            int b,c;cin>>b>>c;
            update(1,N,1,b,c);
        } else {
            cout << query(1,N,1,1,N).second << '\n';
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
