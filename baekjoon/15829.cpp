#include <iostream>

using namespace std;

int main()
{
  int L;
  scanf("%d", &L);
  long long result = 0;
  long long power = 1;
  char c[L];
  scanf("%s", c);
  for (int i = 0; i < L; i++)
  {
    result += power * (c[i] - 'a' + 1);
    result %= 1234567891;
    power = (power * 31) % 1234567891;
  }
  printf("%lld", result);
  return 0;
}
