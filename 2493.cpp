#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);


    int N; cin >>N;
    int arr[N+1];
    for (int i=1;i<=N; i++) cin >> arr[i];

    priority_queue<pair<int, int>> remains;
    arr[0] = 1e9;

    int result[N+1];
    for (int i = N; i >= 0; i--) {
        while (remains.size()) {
            auto [t, index] = remains.top();
            t = -t;
            if (t <= arr[i]) {
                result[index] = i;
                remains.pop();
            } else break;
        }
        remains.push({-arr[i], i});
    }

    for (int i = 1; i <= N; i++) cout << result[i] << ' ';

    return 0;
}
