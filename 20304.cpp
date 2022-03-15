#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const int MAX = 1e6;
int counts[MAX + 1];
int N, M;

void solve()
{
    cin >> M >> N;
    for (int i = 0; i <= MAX; i++) counts[i] = MAX;

    queue<int> q;
    int numbers[N]; for (int i = 0; i < N; i++) {
        cin >> numbers[i];
        counts[numbers[i]] = 0;
        q.push(numbers[i]);
    }

    while (q.size()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < 20; i++) {
            int y = 1 << i;
            int xo = x ^ y;
            if (xo <= MAX && counts[xo] == MAX) {
                counts[xo] = counts[x] + 1;
                q.push(xo);
            }
        }
    }
    int result = 0;
    for (int i = 0; i <= M; i++) {
        if (counts[i] == MAX) continue;
        if (counts[i] > result) result = counts[i];
    }
    cout << result;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
