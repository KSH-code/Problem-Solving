#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <assert.h>
using namespace std;

typedef long long ll;

struct Node {
    ll i, k, diff;
};


struct Compare {
	bool operator()(const Node& m1, const Node& m2) {
		return m1.diff >= m2.diff;
	}
};

int main()
{
    ll N; cin >> N;

    ll students[N];
    for (int i = 0; i < N; i++) cin >> students[i];
    if (N == 1) {
        cout << 0;
        return 0;
    }

    priority_queue<Node, vector<Node>, Compare> q;
    for (int i = 0; i < N; i++) {
        ll diff = 3 * students[i];
        q.push({i, 1, diff});
    }

    for (int i = 0; i < N - 2; i++) {
        Node n = q.top();
        q.pop();
        n.k++;
        // (a + 1)^2 - a^2
        q.push({n.i, n.k, (n.k * 2 + 1) * students[n.i]});
    }
    ll result = 0;
    while (q.size()) {
        Node n = q.top();
        q.pop();
        result += n.k * n.k * students[n.i];
    }
    cout << result;
    return 0;
}
