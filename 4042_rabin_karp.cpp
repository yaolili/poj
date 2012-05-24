#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


void printSubStr(char* str, int start, int m) {
	for(int i=start;i<start+m;i++) {
		cout << str[i];
	}
	cout << endl;
}

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; i++) {
		char str[101];
		int pos[101];
		int m,q;
		cin >> str >> m >> q;
		int strLen = strlen(str);
		if(strLen < m) {
			cout << 0 << endl;
		} else {
			int sum = 0;
			for(int j=0; j<m; j++) sum += int(str[j] - 'a' + 1);
			int start = 0; int end = m-1;
			int count = 0;
			while(end <= strLen) {
				if(sum == q) {
					pos[count] = start;
					count ++;
					
				}
				sum -= int(str[start] - 'a' + 1);
				start ++; end ++;
				sum += int(str[end] - 'a' + 1);
			}
			pos[count] = -1;
			cout << count << endl;;
			for(int k=0; k<count; k++) {
				printSubStr(str,pos[k],m);
			}
		}
	}
}
