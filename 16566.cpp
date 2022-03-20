#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e6 * 4 + 1;
int parent[MAX];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        parent[px] = py;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> arr;
    for (int i = 0; i < M; i++) {
        int t; cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++) parent[i] = i;

    for (int i = 0; i < K; i++) {
        int t; cin >> t;
        auto it = upper_bound(arr.begin(), arr.end(), t);
        int idx = find(parent[it - arr.begin()]);
        cout << arr[idx] << '\n';
        merge(idx, idx + 1);
    }
    return 0;
}
