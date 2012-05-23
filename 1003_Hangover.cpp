#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	float totalLength;
	while(true){
		cin >> totalLength;
		if(totalLength == 0.00) break;
		double i = 1;
		float curLength = 0;
		do{
			curLength += 1/(i+1);
			i++;
		}while(curLength<totalLength);
		cout << (i-1) << " card(s)" << endl;
	}
}