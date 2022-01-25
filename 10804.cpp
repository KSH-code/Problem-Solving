#include <iostream>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int arr[21];
    for (int i = 1; i <= 20; i++)
        arr[i] = i;
    for (int i = 0; i < 10; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i <= (b - a) / 2; i++)
        {
            int t = arr[a + i];
            arr[a + i] = arr[b - i];
            arr[b - i] = t;
        }
    }
    for (int i = 1; i <= 20; i++)
        cout << arr[i] << " ";
    return 0;
}