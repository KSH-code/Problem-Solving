#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    queue<int> arr;
    while (N--)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int n;
            cin >> n;
            arr.push(n);
        }
        else if (str == "pop")
        {
            if (arr.empty())
                cout << -1;
            else
            {
                cout << arr.front();
                arr.pop();
            }
            cout << "\n";
        }
        else if (str == "size")
        {
            cout << arr.size() << "\n";
        }
        else if (str == "empty")
        {
            cout << (arr.empty() ? 1 : 0) << "\n";
        }
        else if (str == "front")
        {
            if (arr.empty())
                cout << -1;
            else
            {
                cout << arr.front();
            }
            cout << "\n";
        }
        else if (str == "back")
        {
            if (arr.empty())
                cout << -1;
            else
            {
                cout << arr.back();
            }
            cout << "\n";
        }
    }
    return 0;
}