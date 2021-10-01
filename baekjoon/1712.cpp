#include <iostream>

int main()
{
  long long a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);

  if (b >= c)
  {
    printf("-1");
    return 0;
  }

  long long result = a / (c - b) + 1;
  printf("%lld", result);
  return 0;
}
