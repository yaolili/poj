#include <iostream>
using namespace std;
int fib(int n){
	if(n==1 || n==2) return 1;
	return fib(n-1) + fib(n-2);
}

int main(){
	int n;
	int a;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		cout << fib(a) << endl;
	}
}