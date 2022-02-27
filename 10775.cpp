#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int tree[100001];

int find(int x) {
    if (tree[x] == x) return x;
    return tree[x] = find(tree[x]);
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    int G, P; cin >> G >> P; for (int i = 0; i <= G; i++) tree[i] = i;
    int result = 0;
    bool full = false;
    for (int i = 0; i < P; i++) {
        int gi; cin >> gi; if (full) continue;

        int found = find(gi);
        if (found > 0) {
            result++;
            tree[found] = found - 1;
        } else full = true;
    }
    cout << result;
    return 0;
}
