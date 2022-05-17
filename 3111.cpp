#include <iostream>

#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    cin.tie(0);

    string A, T;

    cin >> A >> T;
    deque<char> left, right;

    int l = 0;
    int r = T.size() - 1;

    while (1)
    {
        int count = 0;
        while (l <= r)
        {
            left.push_back(T[l++]);
            if (left.size() < A.size())
                continue;
            while (count < A.size() &&
                   left[left.size() - A.size() + count] == A[count])
                count++;

            if (count == A.size())
            {
                for (int i = 0; i < count; i++)
                    left.pop_back();
                break;
            }
            count = 0;
        }
        if (count < A.size())
            break;
        count = 0;

        while (l <= r)
        {
            right.push_front(T[r--]);
            if (right.size() < A.size())
                continue;

            while (count < A.size() &&
                   right[count] == A[count])
                count++;

            if (count == A.size())
            {
                for (int i = 0; i < count; i++)
                    right.pop_front();
                break;
            }
            count = 0;
        }
        if (count < A.size())
            break;
    }

    string str;

    for (auto a : left)
        str += a;
    for (auto a : right)
        str += a;
    while (str.find(A) < T.size())
        str.erase(str.find(A), A.size());
    cout << str;

    return 0;
}
