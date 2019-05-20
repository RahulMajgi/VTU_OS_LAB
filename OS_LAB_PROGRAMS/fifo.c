#include<stdio.h>

void LRU(int nof,int nop,int Frame[],int pages[]);
void FIFO(int nof,int nop,int Frame[],int pages[]);

void print_frame(int nof,int Frame[])
{
	for(int i=0;i<nof;i++)
		{
			printf("%d",Frame[i]);
		}
}

void LRU(int nof,int nop,int Frame[],int pages[])
{

}
void FIFO(int nof,int nop,int Frame[],int pages[])
{
	int i,j,flag=0,p_fault=0,k=0;
	for(i=0;i<nop;i++)
	{
		for(j=0;j<nof;j++)
		{
			if(pages[i] == Frame[j])
			{
				flag=1;
				break;
			}
		if(flag == 1)
		{
			printf("Page %d is found in Frame",pages[i]);
			print_frame(nop,Frame);
		}
		else
		{
			for(int j=0;j<nof;j++)
			{
				p_fault++;
				Frame[j] = pages[i];
				k++;
				flag = 2;
				print_frame(nop,Frame);
				break;
			}
			if(k == 3)
			{
				k = 0;
			}
			if(flag!=2)
			{
				Frame[k] = pages[i];
				k++;
				p_fault++;
				print_frame(nop,Frame);
			}
		}
		}
	}
	printf("\n\n page faults =%d\n",p_fault);	
}


void main()
{
	int ch,nof,nop,i;
	printf("Enter the number of frames:\n");
	scanf("%d",&nof);
	int Frame[nof];
	printf("Enter number of pages\n");
	scanf("%d",&nop);
	int pages[nop];
	printf("Enter the pages in sequence:\n");
	for(i=0;i<nop;i++)
	{
		scanf("%d",&pages[i]);
	}
	printf("1.FIFO\n2.LRU\nEnter the choice:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:FIFO(nof,nop,Frame,pages);
			break;
		case 2:LRU(nof,nop,Frame,pages);
			break;
	}	
}
