#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int arr[5];
    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    int max = 999999999;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (i == j || j == k || i == k)
                    continue;
                int l = lcm(arr[i], lcm(arr[j], arr[k]));
                if (max > l)
                    max = l;
            }
        }
    }

    cout << max;
    return 0;
}