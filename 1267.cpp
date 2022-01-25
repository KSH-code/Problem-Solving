#include <iostream>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int arr[N];
    int M = 0, Y = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i] += 1;
        Y += arr[i] / 30 * 10 + (arr[i] % 30 == 0 ? 0 : 10);
        M += arr[i] / 60 * 15 + (arr[i] % 60 == 0 ? 0 : 15);
    }
    if (M < Y)
        cout << "M " << M;
    else if (M > Y)
        cout << "Y " << Y;
    else
        cout << "Y M " << M;
    return 0;
}