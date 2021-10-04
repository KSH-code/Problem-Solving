#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int K;
  scanf("%d", &K);
  stack<int> numbers;
  for (int i = 0; i < K; i++)
  {
    int n;
    scanf("%d", &n);
    if (n == 0)
      numbers.pop();
    else
      numbers.push(n);
  }

  int result = 0;
  while (numbers.size())
  {
    result += numbers.top();
    numbers.pop();
  }
  printf("%d", result);
  return 0;
}
