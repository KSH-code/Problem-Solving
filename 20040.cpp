#include <iostream>
using namespace std;
typedef long long ll;

const int MAX = 1e5*5;
int parent[MAX + 1];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}

void solve(){
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) parent[i] = i;
    for (int i = 1; i <= M; i++){
        int a, b; cin >> a >> b;
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) {
            cout << i;
            return;
        }
        merge(a, b);
    }
    cout << 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
