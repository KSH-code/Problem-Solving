#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{

  string arr[] = {
      "c=",
      "c-",
      "dz=",
      "d-",
      "lj",
      "nj",
      "s=",
      "z=",
  };

  char temp[100];
  scanf("%s", temp);
  string str = temp;

  string word = "";
  int count = 0;
  for (int i = 0; i < str.length(); i++)
  {
    word += str[i];
    for (auto cword : arr)
    {
      if (word.find(cword) != string::npos)
      {
        count += 1 + word.length() - cword.length();
        word = "";
        break;
      }
    }
  }

  printf("%d", count + word.length());
  return 0;
}
