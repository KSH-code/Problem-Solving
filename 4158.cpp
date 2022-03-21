#include <iostream>
#include <unordered_set>
using namespace std;
typedef long long ll;

bool solve(){
    int N, M; cin >> N >> M;
    if (N + M == 0) return false;

    unordered_set<int> s;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    int result = 0;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        if (s.count(x)) result++;
    }
    cout << result;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    while (solve()) cout << '\n';
    return 0;
}
