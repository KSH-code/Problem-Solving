#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    int count = 0;
    for (int i = 2; i <= 100000; i++)
    {
        if (N % i == 0)
        {
            count++;
            N /= i;
            i--;
            continue;
        }
        else
        {
            if (count)
            {
                cout << i << ' ' << count << '\n';
            }
            count = 0;
        }
    }
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