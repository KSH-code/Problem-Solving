#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N, L;
    cin >> N >> L;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        pq.push({a, i});
        while (pq.top().second + L <= i)
            pq.pop();
        cout << pq.top().first << " ";
    }
    return 0;
}