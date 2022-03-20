#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N; cin >> N;
    int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i]; sort(arr, arr + N);
    int sum = 0;
    for (int i = 0; i < N - 1; i++) sum += arr[i];
    cout << sum;
    return 0;
}
