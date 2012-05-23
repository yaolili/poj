#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
#define PI 3.141592654

int compute_time(float x,float y){
	float d2 = x*x + y*y;
	int n = ceil(PI*d2/100);
	return n;
}

int main(){
	int N;
	float x,y;
	// input N lines
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> x >> y;
		printf("Property %d: This property will begin eroding in year %d.\n",(i+1),compute_time(x,y));
	}
	cout << "END OF OUTPUT." << endl; 
	//system("pause"); //debug
}