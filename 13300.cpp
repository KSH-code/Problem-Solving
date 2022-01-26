#include <iostream>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    int arr[7][2];
    for (int i = 0; i < 7; i++)
        arr[i][0] = arr[i][1] = 0;
    for (int i = 0; i < N; i++)
    {
        int S, Y;
        cin >> S >> Y;
        arr[Y][S]++;
    }
    int result = 0;
    for (int i = 1; i < 7; i++)
    {
        result += (arr[i][0] % K > 0) + arr[i][0] / K;
        result += (arr[i][1] % K > 0) + arr[i][1] / K;
    }
    cout << result;
    return 0;
}