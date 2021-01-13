#include<stdio.h>
#include<math.h>
void tobin(int num, int binarray[])
{
	static int i=0;
	int c=0,rem=0;
	binarray[i]=0;
	while (num>0)
	{
		rem=num%2;
		num=num/2;
		binarray[i]=binarray[i]+(pow(10,c)*rem);
		c++;
	}
	i++;
}
void radixsort(int num,int binarray[],int result[])
{
	int count[2],c=1,max,counter=0;
	max = binarray[0];
	for(int i=0;i<num;i++)
	{
		if (binarray[i]>max)
			max=binarray[i];
	}
	while(max>0)
	{
		max=max/10;
		counter++;
	}
	while(counter--)
	{ 	
	  count[0]=0;
	  count[1]=0;
		for(int i=0;i<num;i++)
		{
			if((binarray[i]/c)%10)
				count[1]++;
			else
				count[0]++;
		}
		count[1]=count[1]+count[0];
		for(int i=num-1;i>=0;i--)
		{
			if((binarray[i]/c)%10)
			{
			    count[1]--;
				result[count[1]]=binarray[i];
			}
			else
			{
			    count[0]--;
				result[count[0]]=binarray[i];
			}
		}
		for(int i=0;i<num;i++)
		{
		    binarray[i]=result[i];
		}
		printf("\nPhase %d: \n",num-counter);
	for (int i=0;i<num;i++)
	{
		printf("%d  ",result[i]);
	}
	c=c*10;
	}
}
void todec(int num,int binarray[], int result[])
{
  int rem;
	for(int i=0;i<num;i++)
	{
		int c=0;
		result[i]=0;
		while(binarray[i]>0)
		{
			rem=binarray[i]%10;
			result[i]=result[i]+(rem*pow(2,c));
			binarray[i]/=10;
			c++;
		}
	}
}
int main()
{
  printf("Code to Radix Sort Decimal Numbers (in Binary form) \n");
	int num, result[num];
	printf("\nHow many numbers do you want to enter? \n");
	scanf("%d",&num);
	int array[num], binarray[num];
	printf("\nEnter numbers in decimal form\n");
	for (int i=0;i<num;i++)
	{
		scanf("%d",&array[i]);
		tobin(array[i],binarray);
	}
	printf("\nYour numbers in decimal form: \n");
	for (int i=0;i<num;i++)
	{
		printf("%d  ",array[i]);
	}
	printf("\nYour numbers in binary form are:\n ");
	for (int i=0;i<num;i++)
	{
		printf("%d  ",binarray[i]);
	}
	radixsort(num,binarray,result);
	printf("\n\nYour result in binary: \n");
	for (int i=0;i<num;i++)
	{
		printf("%d  ",binarray[i]);
	}
	todec(num,binarray,result);
	printf("\n\nYour result in decimal: \n");
	for (int i=0;i<num;i++)
	{
		printf("%d  ",result[i]);
	}
}
