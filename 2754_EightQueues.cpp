#include <iostream>
using namespace std;

int record[92][9],mark[9],count=0;
bool range[9],line1[17],line2[17];
void tryToPut(int);

int main(){
	int i,testtimes,num;
	cin >> testtimes;
	
	for(i=0;i<9;i++){
		range[i] = true;
	}
	for(i=0;i<17;i++){
		line1[i] = true;
		line2[i] = true;
	}
	tryToPut(1);		// put the queue
	while(testtimes--){
		cin >> num;
		for(i=1;i<=8;i++){
			cout << record[num-1][i];
		}
		cout << endl;
	}
}

void tryToPut(int i){
	if(i > 8){
		for(int k=1;k<9;k++){
			record[count][k] = mark[k];
		}
		count ++;
	}
	for(int j=1;j<=8;j++){
		if(range[j] && line1[i+j] && line2[i-j+9]){
			mark[i] = j;
			range[j] = line1[i+j] = line2[i-j+9] = false;
			tryToPut(i+1);
			range[j] = line1[i+j] = line2[i-j+9] =true;
		}
	}
}