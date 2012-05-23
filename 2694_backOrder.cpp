#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double exp(){
	char s[30];
	scanf("%s",s);
	switch(s[0]){
	case '+': return exp() + exp();
	case '-': return exp() - exp();
	case '*': return exp() * exp();
	case '/': return exp() / exp();
	default:  return atof(s);
	}
}

int main(){
	double result = exp();
	printf("%f\n",result);
	//system("pause");
}