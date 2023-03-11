#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

int nIter;

double f(double x)
{
	return pow(x,2)-9;
}

int FNum(int n)
{
	int i;
	int num1=1;
	int num2=1;
	int rs;
	if(n==0) return 1;
	if(n==1) return 1;
	if(n>1)
	{
		for(i=2;i<=n;i++)
		{
			rs = num1 + num2;
			num1 = num2;
			num2 = rs;
		}
		return rs;
	}
}

int pF(double a, double b, double e)
{
	double q = fabs(b-a)/(2*e);
	int rs=1;
	while(FNum(rs)<q) rs++;
	return rs;
}


int main()
{
	nIter=0;
	double e;
	double a,b;
	double ex, ey;
	double x1,x2;
	double y1,y2;
	int p;
	int i;
	double delta;

	printf(" Optimization task. \n");
	printf(" f(x) = x*x-9 on the interval [a, b] \n\n");

	printf(" Left border of the interval à: ");
	scanf("%lf",&a);
	printf(" Right border of the interval b: ");
	scanf("%lf",&b);
	printf(" Specify calculation accuracy x: ");
	scanf("%lf",&e);

	p = pF(a,b,e);
	printf(" p = %d \n",p);


	for(i=0;i<p-1;i++)
	{
		nIter++;
		delta = b-a;
		x1 = b - delta*FNum(p-1-i)/FNum(p-i);
		x2 = a + delta*FNum(p-1-i)/FNum(p-i);
		y1 = f(x1);
		y2 = f(x2);
		printf("\n b-a = %lf \n",delta);
		printf(" x1 = %lf; f(x1) = %lf;  x2 = %lf; f(x2) = %lf\n",x1,y1,x2,y2);
		if(y1<y2) b=x2;
		else a=x1;
	}
	x2 += e/4;
	y2 = f(x2);
	if(y1<y2) b=x2;
	else a=x1;
	nIter++;
	printf(" Low point: õ* = %lf \n",(b+a)/2);
	printf(" Function value f(x) = %lf \n",f((b+a)/2));
	printf(" Number of iterations: n = %d \n",nIter);

	getch();
	return 0;
}
