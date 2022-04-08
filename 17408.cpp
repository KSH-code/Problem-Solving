#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+10;
pair<int,int> tree[MAX*4];

const pair<int,int> NULL_PAIR = {0,0};

pair<int,int> query(int start, int end, int node, int left, int right) {
    if (end < left || right < start) return NULL_PAIR;
    if (start >= left && right >= end) return tree[node];

    int m = (start+end)/2;
    auto [a,b] = query(start, m, node*2, left, right);
    auto [c,d] = query(m+1, end, node*2+1, left, right);
    int arr[4] = {a,b,c,d};
    sort(arr, arr+4);
    return {arr[3], arr[2]};
}

pair<int,int> update(int start, int end, int node, const pair<int,int> &data) {
    auto index = data.second;
    if (start > index || index > end) return tree[node];
    if (start == end) return tree[node] = {data.first,0};

    int m = (start+end)/2;
    auto [a,b] = update(start, m, node*2, data);
    auto [c,d] = update(m+1, end, node*2+1, data);
    int arr[4] = {a,b,c,d};
    sort(arr, arr+4);
    return tree[node] = {arr[3], arr[2]};
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
            auto [e,f] = query(1, N, 1, b, c);
            cout << e+f << '\n';
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
