#include <iostream>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int map[1000000 + 1];
    for (int i = 0; i < 1000000 + 1; i++)
        map[i] = 0;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = 0;
    int x;
    cin >> x;
    for (int i = n - 1; i >= 0; i--)
    {
        if (x - arr[i] > 0 && x - arr[i] <= 1000000)
            result += map[x - arr[i]];
        map[arr[i]]++;
    }
    cout << result;
    return 0;
}