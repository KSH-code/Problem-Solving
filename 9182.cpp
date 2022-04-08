#include <iostream>
using namespace std;

int z =1;

bool solve(){
  int a,b,c,d; cin >>a>>b>>c>>d;
  if (a+b+c+d==-4) return false;
  int result = 0;
  for (int i = 1; true; i++) {
    if ((i-a)%23==0&&(i-b)%28==0&&(i-c)%33==0) {
      result = i;break;
    }
  }
  cout << "Case "<<z<<": the next triple peak occurs in ";
  cout << result-d;
  cout << " days.";
  z++;
  return true;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  while(solve()) cout << '\n';
  return 0;
}
