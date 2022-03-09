#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    int arr[N + 1];
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    bool loop[N + 1];
    for (int i = 1; i <= N; i++)
        loop[i] = false;
    bool no_loop[N + 1];
    for (int i = 1; i <= N; i++)
        no_loop[i] = false;

    int result = N;
    for (int i = 1; i <= N; i++)
    {
        if (loop[i])
            continue;
        unordered_map<int, int> s;
        queue<int> q;
        q.push(i);
        while (q.size())
        {
            int n = q.front();
            if (loop[n] || (s[n] != 1 && no_loop[n]))
                break;
            q.pop();
            if (s[n] == 2)
                continue;
            if (s[n])
            {
                result--;
                loop[n] = true;
                no_loop[n] = false;
            }
            else
            {
                no_loop[n] = true;
            }
            s[n]++;

            q.push(arr[n]);
        }
    }

    cout << result << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}