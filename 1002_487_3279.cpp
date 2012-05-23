#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

char dic[100000][9];
char map[] = "22233344455566677778889999";	// map A-Z to 1-9
char s[100];

void standardizeTel(int n,char* s){
	int len = strlen(s);
	int j=0;
	for(int i=0;i<len;i++){
		if(s[i] == '-'){
			continue;
		}	else if(s[i] >= 'A' && s[i] <= 'Z'){
			dic[n][j++]=map[s[i] - 'A'];
		}	else {//if(s[i] >= '0' && s[i] <= '9'){
			dic[n][j++]=s[i];
		}
	}
	if(strlen(dic[n]) == 7){	// should be 8
		for(int i=7;i>3;i--)
			dic[n][i] = dic[n][i-1];
		dic[n][3] = '-';
	}
	dic[n][8] = '\0';
	//cout << "FORMAT:" << dic[n] << endl; //debug
	return;
}

int compare(const void* a,const void*b){
	return strcmp((char*)a,(char*)b);
}

int main(){
	int n;
	int i=0,j=0;
	bool flag = true;
	cin >> n;
	for(i=0;i<n;i++){
		memset(s,0,sizeof(s));
		cin >> s;
		standardizeTel(i,s);
	}
	qsort(dic,n,9,compare);
	i=0;
	while(i<n){
		j = i;
		i++;
		while(i<n && strcmp(dic[j],dic[i])==0){
			i++;
			flag = false;
		}
		if(i-j > 1)
			cout << dic[j] << " " << (i-j) << endl;
	}
	if(flag) cout << "No duplicates."<< endl;
	//system("pause");
	return 0;
}
