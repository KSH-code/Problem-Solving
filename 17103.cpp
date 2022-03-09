#include <iostream>
using namespace std;
typedef long long ll;

bool is_prime[1000001];
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    for (int i = 2; i <= 1000000; i++)
        is_prime[i] = true;
    for (int i = 2; i <= 1000000; i++)
    {
        if (is_prime[i])
            for (int j = i + i; j <= 1000000; j += i)
            {
                is_prime[j] = false;
            }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int z;
        cin >> z;
        int count = 0;
        for (int i = 2; i < z; i++)
        {
            if (z - i >= i && is_prime[i] && is_prime[z - i])
                count++;
        }
        cout << count << '\n';
    }
    return 0;
}