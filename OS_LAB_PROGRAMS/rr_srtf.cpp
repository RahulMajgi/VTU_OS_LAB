#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;
void srtf();
void rr();

int main() {
	int ch;
	cout<<"1.SJF\n2.RR";
	cin>>ch;
	switch(ch) {
		case 1: cout<<"\n \n SHORTEST REMAINING JOB \n \n";
			srtf();
			break;
		case 2: cout<<"\n \n ROUND ROBIN \n \n";
			rr();
			break;
	}
	return 0;	
}

void rr() {
	int nofp, a[10], b[10],tQuantum,pq[20],totalTime=0,pno=0,pqindex=-1,pAdded[10]={0},c[10],bcopy[10]={0};
	int avgwt[10],avgtt[10],sum1w=0,sum2t=0;
	cout<< "\nEnter the time number of processes:";
	cin>> nofp;
	cout<< "\nEnter the time quantum:";
	cin>> tQuantum;
	cout<< "\nEnter the arrival time and burst times of the processes:";
	cout<<"\n\tProcess";
	for(int i=0;i<nofp;i++) {
		cout<<"\n\t P" << i+1 << "\t\tArrival time:";
		cin>> a[i];
		cout<< "\n\t\t\tBurst time:";
		cin>> b[i];
		bcopy[i] = b[i];
		totalTime += b[i];
	}
	for(int bc=0;bc<20;bc++) {
		pq[bc] = 99;
	}
	for(int i=0;i<totalTime;) {
		pqindex++;
		
		for(int j=0;j<nofp;j++) {
			if(i>=a[j] && pAdded[j]!=1) {
				pq[pno++] = j;
				pAdded[j] = 1;
				cout<< "\nProcess added: "<<j+1;
			}
		}
		if(pq[pqindex]==99) {
			cout<< "\n\tProcessor idle @time : "<<i;
			pqindex--;
			i+=1;
			totalTime+=1;
			continue;
		}
		b[pq[pqindex]] -= tQuantum;
		if(b[pq[pqindex]]>0) {
			i += tQuantum;
			for(int j=0;j<nofp;j++) {
				if(i>=a[j] && pAdded[j]!=1) {
					pq[pno++] = j;
					pAdded[j] = 1;
				}
			}
			pq[pno++] = pq[pqindex];
		}
		else {
			cout<<"\nProcess completed:"<<pq[pqindex]+1;
			if(b[pq[pqindex]]<0) i += (tQuantum + b[pq[pqindex]]);
			else i+=tQuantum;
			c[pq[pqindex]] = i;
		}
	}
	cout<<"\nProcess queue:";
	for(int i=0;i<pno;i++) cout<<"\t" <<pq[i]+1;
	
	cout<<"\n\n\nProcess\t\tA.T\t\tB.T\t\tC.T\t\tT.T\t\tW.T";
	for(int i=0;i<nofp;i++) cout<<"\n\n P"<<i+1<<"\t\t"<<a[i]<<"\t\t"<<bcopy[i]<<"\t\t"<<c[i]<<"\t\t"<<c[i]-a[i]<<"\t\t"<<c[i]-a[i]-bcopy[i]<<"\n\n";
	
	for(int i=0;i<nofp;i++) {
		avgwt[i] = c[i]-a[i]-bcopy[i];
		avgtt[i] = c[i]-a[i];
	}
	for(int i=0;i<nofp;i++) {
		sum1w += avgwt[i];
		sum2t += avgtt[i];
	}
	
	cout<<"\nAverage turnaround time="<<(float)sum2t/nofp;
	cout<<"\nAverage waiting time ="<<(float)sum1w/nofp<<"\n";
}

void srtf() {
	int a[10],b[10],x[10],i,j,smallest,count = 0,time,n;
	int wt[10],tt1[10];
	double avg=0,tt=0,end;
	cout<<"enter the number of processes:\n";
	cin>>n;
	cout<<"enter arrival time\n";
	for(i=0;i<n;i++) cin>>a[i];
	cout<<"enter burst time\n";
	for(i=0;i<n;i++) cin>>b[i];
	for(i=0;i<n;i++) x[i] = b[i];
	
	b[9] = 9999;
	
	for(time=0;count!=n;time++) {
		smallest = 9;
		for(i=0;i<n;i++) {
			if(a[i]<=time && b[i]<b[smallest] && b[i]>0) smallest = i;
		}
		b[smallest]--;
		if(b[smallest]==0) {
			count++;
			end = time+1;
			avg = avg+end-a[smallest]-x[smallest];
			tt = tt+end-a[smallest];
			wt[smallest] = end-a[smallest]-x[smallest];
			tt1[smallest] = end-a[smallest];
		}
	}
	cout<<"Process"<<"\twaiting time"<<"\tturnaround time\n";
	for(i=0;i<n;i++) cout<<i+1<<"\t\t"<<wt[i]<<"\t"<<tt1[i]<<"\n";
	
	cout<<"\nAverage waiting time="<<(float)avg/n;
	cout<<"\nAverage Turnaround time="<<(float)tt/n;
}
