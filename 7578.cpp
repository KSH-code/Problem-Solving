#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

const int MAX = 1e5*5;
ll tree[MAX*4];

ll query(int start, int end, int node, int left, int right) {
    if (start > right || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int m = (start+end)/2;
    return query(start, m, node*2, left, right) + query(m+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index) {
    if (start > index || end < index) return;
    tree[node]++;
    if (start == end) return;
    int m = (start+end)/2;
    update(start, m, node*2, index);
    update(m+1, end, node*2+1, index);
}

void solve(){
    int N; cin >> N;
    int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
    unordered_map<int, int> map;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        map[t] = i;
    }
    ll result = 0;
    for (int i = 0; i < N; i++) {
        int t = arr[i];
        int idx = map[t];
        update(0, N-1, 1, idx);
        result += query(0, N-1, 1, idx+1, N-1);
    }
    cout << result;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    solve();
    return 0;
}
