#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+10;
pair<int,int> tree[MAX*4];

const pair<int,int> NULL_PAIR = {1e9,1e9};

pair<int,int> query(int start, int end, int node, int left, int right) {
    if (end < left || right < start) return NULL_PAIR;
    if (start >= left && right >= end) return tree[node];

    int m = (start+end)/2;
    return min(query(start, m, node*2, left, right), query(m+1, end, node*2+1, left, right));
}

pair<int,int> update(int start, int end, int node, const pair<int,int> &data) {
    auto index = data.second;
    if (start > index || index > end) return tree[node];
    if (start == end) return tree[node] = data;

    int m = (start+end)/2;
    return tree[node] = min(update(start, m, node*2, data), update(m+1, end, node*2+1, data));
}

void solve(){
    int N; cin >>N;
    for (int i = 0; i < MAX*4; i++) tree[i] = NULL_PAIR;

    for (int i = 1; i <= N; i++) {
        int d; cin >> d;
        update(1, N, 1, {d, i});
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int a,b,c; cin >> a >> b>>c;
        if (a == 1) {
            update(1, N, 1, {c,b});
        } else {
            cout << query(1, N, 1, b, c).second << '\n';
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
