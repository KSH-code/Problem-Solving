#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    getline(cin, str);
    stack<char> st;
    int opened = 0;
    for (auto c : str)
    {
        bool f = false;
        switch (c)
        {
        case ' ':
            break;
        case '<':
            opened++;
            break;
        case '>':
            opened--;
            break;
        default:
            if (!opened)
            {
                f = true;
                st.push(c);
            }
        }
        if (!f){
        while (st.size())
        {
            cout << st.top();
            st.pop();
        }cout<<c;
        }
    }
    while (st.size())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}