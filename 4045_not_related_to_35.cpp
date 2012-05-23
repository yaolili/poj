#include <iostream>
#include <stdio.h>
using namespace std;
bool isRelated(int);

int main() {
  int n;
  cin >> n;
  int sum = 0;
  for(int i=1; i<=n; i++) {
	if(i % 3 == 0 || i % 5 == 0)
	  continue;
	if(isRelated(i))
	  continue;
	sum += i*i;
  }
  cout << sum << endl;
  return 0;
}

bool isRelated(int p) {
  while(p > 0) {
    int first = p % 10;
	if(first == 3  || first == 5) return true;
	p = p/10;
  }
  return false;
}
