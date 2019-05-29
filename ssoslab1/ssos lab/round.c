#include<stdio.h>

int n;
float findavg(int a[n])
{	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	return sum/n;
}
int findmin(int flag[n],int bt[n])
{	
	int min=99;
	int k;
	for(int j=0;j<n;j++)
	{
		if(flag[j]==1)
		{
			if(min>bt[j])
			{
				min=bt[j];
				k=j;
			}
		}
	}
	return k;
}					
	
void srtf(int arr[n],int bt[n],int max )
{	
	int k;
	int flag[n],ct[n],btt[n];
	for(int j=0;j<n;j++)
		btt[j]=bt[j];
	int i=0;	
	for(int j=0;j<n;j++)
			flag[j]=0;
	for(int j=0;j<n;j++)
	{	
		if(arr[j]<=i)
			flag[j]=1;
		if(bt[j]<=0)
			flag[j]=0;
		k=findmin(flag,bt);
		bt[k]-=1;
		ct[k]=i;
		i++;
		if(i>max)
			break;

	}
	max++;
	for(int j=0;j<n;j++)
	{
		if(bt[j]<=0)
			flag[j]=0;
		else flag[j]=1;
	}
	for(int i=0;i<n;i++)
	{	
		k=findmin(flag,bt);
		max+=bt[k];
		bt[k]=0;
		ct[k]=max;
		flag[k]=0;
	}
	for(int j=0;j<n;j++)
		printf("%d ",ct[j]);
	int tat[n],wt[n];
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-arr[i];
		wt[i]=tat[i]-btt[i];
	}
	printf("AVG tat= %f\n avg wt= %f\n",findavg(tat),findavg(wt));
	
	
}
void main()
{
	printf("Enter the no. of processes: ");
	scanf("%d",&n);
	printf("Enter the arrival time \n");
	int max=0;
	
	int arr[n],bt[n];	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the burst time\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(max<arr[i])
			max=arr[i];
	}
	srtf(arr,bt,max);
}
