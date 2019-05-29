#include<iostream>
using namespace std;

int n,r,a[20][20],m[20][20],need[20][20],avail[20];
void safe()
{
int count=0,looping=0,finish[20]={0},work[20]={0},i=1,j,flag=0,p[20];
for(i=0;i<r;i++)
 work[i]=avail[i];
 i=0;
while (count<n &&  looping<5*n )
{
	flag=0;
	looping++;
	if(finish[i]==0)
	{
		for(j=0;j<r;j++)
		if(need[i][j]>work[j])
		{	flag=1;
			break;
		}
		if(!flag)
		{
			for(j=0;j<r;j++)
			work[j]=work[j]+a[i][j];
			finish[i]=1;
			count++;
			p[count]=i;
		}
	}
   i=(i+1)%n;
}


flag=0;
	for(i==0;i<n;i++)
		if(finish[i]==0)
		{
		flag=1;break;
		}
	if(flag==0)
	{
		cout<<"\n system is in safe state and the sequence is \n";
	for(i=1;i<=n;i++)
		cout<<p[i]<<"\t";
	cout<<"\n";
	}
	else
	cout<<"\n system is not in safe state\n";
	}


void newreq()	
	{
 int p,nr[20],flag=0,j,i;
 cout<<"\n enter requesting process"<<endl;

cin>>p;
cout<<"\n enter request in order of resources \n";
for(i=0;i<r;i++)
cin>>nr[i];
for(j=0;j<r;j++)
if(need[p][j]<nr[j] && nr[j]>avail[j])
flag=1;
if(!flag)
{
	for(i=0;i<r;i++)
	{
		avail [i]-=nr[i];
		a[p][i]+=nr[i];
		need[p][i]-=nr[i];
	}
	safe();
}
else
{
cout<<"\n the process  exceeds its maximum"<<endl;
}
}
int main()
 {
int i,j,ch;
cout<<"\n enter the the number of process "<<endl;
cin>>n;
cout<<"\n enter the no of resources"<<endl;
cin>>r;
cout<<"\n enter the allocation matrix"<<endl;
for(i=0;i<n;i++)
	for(j=0;j<r;j++)
		cin>>a[i][j];
cout<<"\n enter max matrix"<<endl;
for(i=0;i<n;i++)
	for(j=0;j<r;j++)
		cin>>m[i][j];
for(i=0;i<n;i++)
	for(j=0;j<r;j++)
		need[i][j]=m[i][j]-a[i][j];
cout<<"\n need matrix\n";
for(i=0;i<n;i++)
{
	for(j=0;j<r;j++)
	cout<<need[i][j]<<" ";
	cout<<"\n";
}


cout<<"enter available resource\n";
for(i=0;i<r;i++)
cin>> avail[i];
safe();
cout<<"\n 1.new request.\n 2.exit\n enter your choice:";
cin>>ch;
switch(ch)
{
case 1:newreq();
       break;
case 2: return 0;
}
return 0;
}


