// Code for Multiplier 

#include <stdio.h>
#include <stdint.h>

int add(int a, int b)
{
	int sum;
	int carry;
	
	while (b != 0)
	{
	sum = a ^ b;
	carry = a & b;
	a = sum;
	b = carry << 1;
	}
	
	return a;
}


int two_component(int c)
{
	int negate;
	negate = add(~c,1);
	return negate;
}
	
int32_t sig_multiply(int32_t multiplicand , int32_t multiplier)
{
	int n = 16;
	int neg=0;
	int32_t answer = 0;
	if (multiplicand < 0)
	{
		multiplicand = two_component(multiplicand);
		neg = !neg;
	}
	if (multiplier < 0)
	{
		multiplier = two_component(multiplier);
		neg = !neg;
	}
	for(int i = 0 ; i<n; i++) 
	{
		if (multiplier & 1)
		{
			answer = add(answer,multiplicand);
		}
		else 
		{
			answer = answer;
		}
		multiplicand <<= 1;
		multiplier >>= 1;
	}
	
	if (neg)
	{
		answer = two_component(answer);
	}
	return answer;
}

	
	
int main(void)
{
	int16_t multiplicand, multiplier;
	printf("Enter Multiplicand : ");
	scanf("%hd",&multiplicand);
	printf("Enter Multiplier : ");
	scanf("%hd",&multiplier);
	
	int32_t result = sig_multiply(multiplicand,multiplier);
	
	printf("Product is %d \n",result);
	
	return 0;
	
}
	
	