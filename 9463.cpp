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

ll tree[MAX*4];
int arr[MAX+1];


void update(int s, int e, int node, int index) {
  if (index < s || index > e) return;

  if (s == e) {
      tree[node]++;
      return;
  }

  int m=(s+e)/2;
  update(s, m, node*2, index); update(m+1, e, node*2+1, index);
  tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int s, int e, int node, int from, int to) {
  if (s > to || e < from) return 0;
  if (s >= from && to >= e) return tree[node];

  int m = (s+e)/2;
  return query(s, m, node*2, from, to) + query(m+1, e, node*2+1, from, to);
}

void solve(){
    int N; cin >> N;
    memset(tree, 0, sizeof tree);
    for (int i = 1; i <= N; i++) {
        int a;cin>>a;
        arr[a]=i;
    }

    ll result = 0;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        result += query(1,N,1,arr[a],N);
        update(1,N,1,arr[a]);
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
