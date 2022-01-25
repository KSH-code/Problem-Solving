#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> stack;
    int result[N];
    result[N - 1] = -1;
    for (int i = N - 1; i >= 0; i--)
    {
        result[i] = -1;
        while (!stack.empty())
        {
            if (arr[i] >= stack.back())
            {
                stack.pop_back();
            }
            else
            {
                result[i] = stack.back();
                break;
            }
        }
        stack.push_back(arr[i]);
    }

    for (int i = 0; i < N; i++)
        cout << result[i] << " ";
    return 0;
}