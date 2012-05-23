#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAX_LEN = 1000;
bool mul(char* szLine1,char*szLine2,char* aResult){
	unsigned an1[MAX_LEN+10];
	unsigned an2[MAX_LEN+10];
	unsigned ans[MAX_LEN+10];
	char temp[MAX_LEN+10];
	memset(an1,0,sizeof(an1));
	memset(an2,0,sizeof(an2));
	memset(ans,0,sizeof(ans));
	memset(temp,0,sizeof(temp));
	memset(aResult,0,sizeof(aResult));
	int nLen1 = strlen(szLine1);
	int nLen2 = strlen(szLine2);
	int count = 0;
	int j = 0;
	int hasPoint1=0,hasPoint2=0;
	for(int i=nLen1-1; i>=0; i--){
		if(szLine1[i] == '.'){
			count = j;		//小数点后数字个数
			hasPoint1=1;
		}	else if( szLine1[i] >= '0' && szLine1[i] <= '9') {
			an1[j++] = szLine1[i] - '0';
		} else {
			//cout << "error";		// debug
			return false;
		}
	}
	

	j = 0;
	for(int i=nLen2-1; i>=0; i--){
		if(szLine2[i] == '.'){
			count += j;		//小数点后数字个数
			hasPoint2 = 1;
		}	else if( szLine2[i] >= '0' && szLine2[i] <= '9') {
			an2[j++] = szLine2[i] - '0';
		}	else {
			//cout << "error";		// debug
			return false;
		}	
	}

	for(int i=0; i<nLen2-hasPoint2; i++){
		for(int j=0;j<nLen1-hasPoint1;j++){
			ans[i+j] += (an2[i] * an1[j]);
		}
	}
	for(int i=0;i<MAX_LEN;i++){
		if(ans[i]>=10){
			ans[i+1] += ans[i]/10;
			ans[i] %= 10;
		}
	}
	bool bStartOutput = false;
	j = 0;
	for(int i=MAX_LEN;i>=0;i--){
		if(bStartOutput){
			temp[j++] = ans[i] + '0';
		}	else if(ans[i]){		//第一个不为0的数开始
			temp[j++] = ans[i] + '0';
			bStartOutput = true;
		}
	}
	temp[j] = '\0';
	//cout << "TEMP:" << temp << endl;
	// process point problem
	int len = strlen(temp);
	//strcpy(aResult,temp);
	if(count == 0){
		strcpy(aResult,temp);
	}else if(count < len){
		strncpy(aResult,temp,len-count);
		aResult[len-count] = '.';
		strncpy(aResult+len-count+1,temp+len-count,count+1);
	} else if(count-len == 0){
		aResult[0] = '.';
		strcpy(aResult+1,temp);
	} else if(count > len){
		aResult[0] = '.';
		for(int i=1;i<count-len+1;i++){
			aResult[i] = '0';
		}
		strcpy(aResult+count-len+1,temp);
	}
	// process insignificant trailing zeros
	len = strlen(aResult);
	for(int i=len-1;i>=0;i--){
		if(aResult[i] == '0') aResult[i] = '\0';
		else break;
	}
	if(aResult[strlen(aResult)-1] == '.') aResult[strlen(aResult)-1] = '\0';
	return true;
}

bool isZero(char * aResult){
	for(int i=0;i<strlen(aResult);i++){
		if(aResult[i]>'0' && aResult[i] <= '9')	//非零
			return false;
	}
	return true;
}


int main(){
	char s[MAX_LEN];
	int n;
	char aResult[MAX_LEN+10];
	char szLine1[MAX_LEN+10];
	char szLine2[MAX_LEN+10];
	while(cin>>s>>n){
		strcpy(aResult,s);
		if(n==0){
			cout << 1 << endl;
			continue;
		}	else if(n==1){
			int len = strlen(aResult);
			for(int i=len-1;i>=0;i--){
				if(aResult[i] == '0') aResult[i] = '\0';
				else break;
			}
			if(aResult[strlen(aResult)-1] == '.') aResult[strlen(aResult)-1] = '\0';
			cout << aResult << endl;
			continue;
		} else if(isZero(s)){
			cout << "0" << endl;
			continue;		// next
		}
		bool flag = true;
		for(int i=1;i<n;i++){
			memset(szLine1,0,sizeof(szLine1));
			memset(szLine2,0,sizeof(szLine2));
			strcpy(szLine1,s);
			strcpy(szLine2,aResult);
			//cout << szLine1 << endl;	//debug
			//cout << szLine2 << endl;	//debug
			if(!mul(szLine1,szLine2,aResult)){
				flag = false;
				break;
			}
		}
		if(flag) cout << aResult << endl;
	}
	return 0;
}
