#include <iostream>
#include <vector>
using namespace std;
int N, M;
int arr[101][101][101];

int dp(int a, int b, int c)
{
    if (arr[a][b][c] > -1)
        return arr[a][b][c];

    if (a <= 50 || b <= 50 || c <= 50)
        return arr[a][b][c] = 1;

    if (a > 70 || b > 70 || c > 70)
        return arr[a][b][c] = dp(70, 70, 70);

    if (a < b && b < c)
        return arr[a][b][c] = dp(a, b, c - 1) + dp(a, b - 1, c - 1) - dp(a, b - 1, c);

    return arr[a][b][c] = dp(a - 1, b, c) + dp(a - 1, b - 1, c) + dp(a - 1, b, c - 1) - dp(a - 1, b - 1, c - 1);
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            for (int k = 0; k < 101; k++)
                arr[i][j][k] = -1;

    int a, b, c;
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << dp(a + 50, b + 50, c + 50);
        cout << "\n";
    }
    return 0;
}