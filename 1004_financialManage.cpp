#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	double total = 0;
	double monthBalance;
	for(int i=0;i<12;i++){
		cin >> monthBalance;
		total += monthBalance;
	}
	//cout << "$" << total << endl;
	printf("$%.2f\n",total/12);
	//system("pause");//debug
	return 0;
}