#include<stdio.h>
#include<stdlib.h>
int n,r,allocation[20][20],max[20][20],need[20][20],availiable[20];

void safe() 
{
	int count=0,looping=0,finish[20]={0},work[20]={0},i=1,j,flag=0,p[20];
	for(i=0;i<r;i++) 
		work[i] = availiable[i];
	i=0;
	while(count<n && looping<5*n) 
	{
		flag=0;
		looping++;
		if(finish[i]==0) 
		{
			for(j=0;j<r;j++) 
			{
				if(need[i][j]>work[j]) 
				{
					flag=1;
					break;
				}
			}
			if(!flag) 
			{
				for(j=0;j<r;j++) 
					work[j]=work[j] + allocation[i][j];
				finish[i]=1;
				count++;
				p[count]=i;
			}
		}
		i=(i+1)%n;
	}
	flag=0;
	for(i=0;i<n;i++) 
	{
		if(finish[i]==0) 
		{
			flag =1;
			break;
		}
	}
	if(flag==0) 
	{
		printf("\nSYSTEM IN SAFE STATE AND THE SEQUENCE IS \n");
		for(i=1;i<=n;i++) 
			printf("%d\t",p[i]);
		printf("\n");
	}
	else 
		printf("\nSYSTEM NOT IN SAFE STATE\n");
}


void newreq() 
{
	int p,nr[20],flag=0,j,i;
	printf("\nEnter Requesting process\n");
	scanf("%d",&p);
	printf("\nEnter request in order of resources\n");
	for(i=0;i<r;i++) 
		scanf("%d",&nr[i]);
	for(j=0;j<r;j++) 
	{
		if(need[p][j]<nr[j] && nr[j]>availiable[j]) 
			flag=1;
	}
	if(!flag) 
	{
		for(i=0;i<r;i++) 
		{
			availiable[i] -= nr[i];
			allocation[p][i] += nr[i];
			need[p][i] -= nr[i];
		}
		safe();
	}
	else printf("\nThe process exceeds its maximum\n");
}



int main() 
{
	int i,j,ch;
	printf("\nEnter the number of processes\n");
	scanf("%d",&n);
	printf("\nEnter the number of resources\n");
	scanf("%d",&r);
	printf("\nEnter the allocation matrix\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<r;j++)
			scanf("%d",&allocation[i][j]);
			
	printf("\nEnter max matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);
			
	for(i=0;i<n;i++)
		for(j=0;j<r;j++)
			need[i][j] = max[i][j] - allocation[i][j];
			
	printf("\nNeed matrix\n");
	for(i=0;i<n;i++) 
	{
		for(j=0;j<r;j++) 
			printf("%d ",need[i][j]);
		printf("\n");
	}
	
	printf("\nEnter available resources\n");
	for(i=0;i<r;i++) 
		scanf("%d",&availiable[i]);
	safe();
	
	printf("\n1.New request\n2.Exit\nEnter your choice:\n");
	scanf("%d",&ch);
	switch(ch) 
	{
		case 1: newreq();
			break;
		case 2: exit(0);
	}
	return 0;
}
