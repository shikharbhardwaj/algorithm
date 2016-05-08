#include <cstdio>
#include <cmath>
const int max = 160;	//The maximum digits possible in the answer
int result[max];
void init(int *ar){
	for(int i = 0;i<max;i++){
		ar[i] = 0;
	}
}
void printNum(int *res){
	for(int i = max-1;i>=0;i--){
		if(res[i] != 0){
			for(int j = i;j>=0;j--)	{
				printf("%d",res[j]);
			}
			break;
		}
	}
	printf("\n");
}
void multipy10(int *res, int pow){
	int i;
	for(i = max-1;i>=0;i--){
		if(res[i] != 0){
			for(int j = i;j>=0;j--)	{
				res[j+pow] = res[j];
			}
			for(int j = 0;j<pow;j++){
				res[j] = 0;
			}
			return;
		}
	}
}
void multiply_digit(int *res,int to){
	int i = 0, carry = 0, dg = 0;
	for(int i = max-1;i>=0;i--){
		if(res[i] != 0){
			dg = i;
			break;
		}
	}
	while(i <= dg+1){
		res[i] *= to;
		res[i] += carry;
		carry = res[i]/10;
		res[i] = res[i]%10;
		i++;
	}
}
void add(int *res, int *adder, int sent){
	int carry = 0;
	if(sent != 0){
		for(int i = 0;i<max;i++){
			res[i] += adder[i] + carry;
			carry = res[i]/10;
			res[i] %= 10;
		}
	}
	else{
		for(int i = max-1;i>=0;i--){
			res[i] = adder[i];
		}	
	}
}
void multiply_num(int *res,int num){
	int multi_table[(int)log10(num)+1][max];	//The multiplication table
	for(int i = 0;i<=log10(num);i++){
		for(int j = 0;j<160;j++){
			multi_table[i][j] = res[j];
		}
	}
	int pos = 0, cp = num;
	while(pos <= log10(cp)){
		multiply_digit(multi_table[pos], num%10);
		multipy10(multi_table[pos], pos);
		add(res,multi_table[pos],pos);
		num/=10;
		pos++;
	}
}
void Factorial(int *res,int num){
	int i = 1;
	while(i <= num){
		multiply_num(result,i);
		i++;
	}
}
int main(){
	int T,N;
	scanf("%d", &T);
	while(T--){
		init(result);
		result[0] = 1;
		scanf("%d", &N);
		Factorial(result,N);
		printNum(result);
	}
}
