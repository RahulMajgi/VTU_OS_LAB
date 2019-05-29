#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ip[15],stack[15];
int ipp=0,stp=0,len,i;
char temp[2];
char act[15];
void check();
void main()
{
	printf("\n\t\tSHIFT REDUCE PARSER\n");
	printf("\n GRAMMAR\n");
	printf("\nE->E+T|T|\nT->T*F|F\nF->(E)|id\n");
	printf("Enter the input symbol: \t");
	scanf("%s",ip);
	printf("\n\tStack implementation table\n");
	printf("\nstack\t\tinput symbol\t\taction");
	printf("\n-----\t\t------------\t\t-------\n");
	printf("\n$\t\t%s$\t\t--",ip);
	strcpy(act,"shift");
	if(ip[ipp]=='(')
	{
		temp[0]=ip[ipp];
		temp[1]='\0';
	}
	else
	{
		temp[0]=ip[ipp];
		temp[1]=ip[ipp+1];
		temp[2]='\0';
	}
	strcat(act," ");
	strcat(act,temp);
	len=strlen(ip);
	for(int i=0;i<=len;i++)
	{
		if(ip[ipp]=='i'&&ip[ipp+1]=='d')
		{
			stack[stp]=ip[ipp];
			stp++;
			ip[ipp]=' ';
			ipp++;
			stack[stp]=ip[ipp];
			stack[stp+1]='\0';
			ip[ipp]=' ';
			ipp++;
		}
		else
		{
			stack[stp]=ip[ipp];
			stack[stp+1]='\0';
			ip[ipp]=' ';
			ipp++;
		}
		printf("\n$%s\t\t%s$\t\t%s",stack,ip,act);
		strcpy(act,"shift");
		if(ip[ipp]=='('||ip[ipp]=='*'||ip[ipp]=='+'||ip[ipp]==')')
		{
			temp[0]=ip[ipp];
			temp[1]='\0';
		}
		else
		{
			temp[0]=ip[ipp];
			temp[1]=ip[ipp+1];
			temp[2]='\0';
		}
		strcat(act," ");
		strcat(act,temp);
		check();
		stp++;
	}
	stp++;
	check();
}
void check()
{
	int flag=0;
	while(1)
	{
		if(stack[stp]=='d'&&stack[stp-1]=='i')
		{
			stack[stp-1]='F';
			stack[stp]='\0';
			stp--;
			flag=1;
			printf("\n$%s\t\t%s$\t\tF->id",stack,ip);
		}
		if(stack[stp]==')'&&stack[stp-1]=='E'&&stack[stp-2]=='(')
		{
			stack[stp-2]='F';
			stack[stp-1]='\0';
			flag=1;
			stp-=2;
			printf("\n$%s\t\t%s$\t\tF->id",stack,ip);
		}
		if(stack[stp]=='F'&&stack[stp-1]=='*'&&stack[stp-2]=='T')
		{	
			//stack[stp-2]='T';
			stack[stp-1]='\0';
			flag=1;
			stp-=2;
			printf("\n$%s\t\t%s$\t\tT->T*F",stack,ip);
		}
		else
		{
			if(stack[stp]=='F')
			{	
				stack[stp]='T';
				flag=1;
				printf("\n$%s\t\t%s$\t\tT->F",stack,ip);
			}
		}
		if(stack[stp]=='T'&&stack[stp-1]=='+'&&stack[stp-2]=='E'&&ip[ipp]!='*')
		{
			stack[stp-1]='\0';
			flag=1;
			stp-=2;
			printf("\n$%s\t\t%s$\t\tE->E+T",stack,ip);
		}
		else
			if((stack[stp]=='T'&&ip[ipp]=='+')||(stack[0]=='T'&&ip[ipp]=='\0')||(stack[stp]=='T'&&ip[ipp]==')'))
			{
				stack[stp]='E';
				flag=1;
				printf("\n$%s\t\t%s$\t\tE->T",stack,ip);
			}
		if((stack[stp]=='T'&&ip[ipp]=='*')||(stack[stp]=='E'&&ip[ipp]==')')||(stack[stp]=='E'&&ip[ipp]=='+')||(stack[stp]=='+'&&ip[ipp]=='i'&&ip[ipp+1]=='d')||(stack[stp]=='('&&ip[ipp]=='i'&&ip[ipp+1]=='d')||(stack[stp]=='('&&ip[ipp]=='(')||(stack[stp]=='*'&&ip[ipp]=='i'&&ip[ipp+1]=='d')||(stack[stp]=='*'&&ip[ipp]=='(')||(stack[stp]=='+'&&ip[ipp]=='('))
		{
			flag=2;
		}
		if(!strcmp(stack,"E")&&ip[ipp]=='\0')
		{
			printf("\n$%s\t\t%s$\t\tACCEPT\n",stack,ip);
			exit(0);
		}
		if(flag==0)
		{
			printf("\n$%s\t\t%s$\t\tREJECT\n",stack,ip);
			exit(0);
		}
		if(flag==2)
			return;
		flag=0;
	}
}
