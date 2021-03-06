

#include <stdio.h>

void print_frame(int fr[],int f)
{
	for(int i=0;i<f;i++)
	{
		printf("%d\t",fr[i]);
	}
	printf("\n");
}

int min(int counter[],int f)
{
	int pos1=0;
	int min=counter[0];
	for(int i=0;i<f;i++)
	{
		if(min>counter[i])
		{
			min=counter[i];
			pos1=i;
		}
	}
	return pos1;
}

void lru(int fr[],int pa[],int counter[],int f,int p)
{
	int flag,position,page,fault=0;
	int recent=0;
	for(int i=0;i<p;i++)
	{
		flag=0;
		page=pa[i];
		for(int j=0;j<f;j++)
		{
			if(page==fr[j])
			{
				flag=1;
				recent++;
				counter[j]=recent;
				break;
			}
		}
		if(flag==0)
		{
			position=min(counter,f);
			fr[position]=page;
			recent++;
			counter[position]=recent;
			fault++;
		}
		print_frame(fr,f);
	}
	printf("fault:%d\n",fault);
}

void fifo(int fr[],int pa[],int f,int p)
{
	int flag,fault=0,k=0,page;
	for(int i=0;i<p;i++)
	{
		page=pa[i];
		flag=1;
		for(int j=0;j<f;j++)
		{
			if(page==fr[j])
			{
				flag=0;
				break;
			}
		}
		if(k==f)
			k=0;
		if(flag==1)
		{
			fr[k++]=page;
			print_frame(fr,f);
			printf("\n");
			fault++;
		}
		else
			print_frame(fr,f);
	}
	printf("fault : %d\n",fault);
}

void main()
{
	int ch,f,p,fr[20],pa[20],counter[20];
	printf("enter the frame size : ");
	scanf("%d",&f);
	printf("enter the size of the reference string : ");
	scanf("%d",&p);
	for(int i=0;i<f;i++)
	{
		fr[i]=-1;
		counter[i]=0;
	}
	printf("enter the reference string :");
	for(int i=0;i<p;i++)
	scanf("%d",&pa[i]);
	printf("\n");
	printf("1.FIFO\n2.LRU\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : printf("\nFIRST IN FIRST OUT\n");
			fifo(fr,pa,f,p);
			break;
		case 2: printf("\nLEAST RECENTLY USED\n");
			lru(fr,pa,counter,f,p);
			break;
	}
}
