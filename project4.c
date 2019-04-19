#include<stdio.h>
int main() 
{ 
	int n;
	printf("\n\t\t\t *Enter details of process*");
	printf("\n\t\t\t____________________________\n\n");
	printf("\n Enter number of process : ");
	scanf("%d",&n);
	int burst[n],arrival[n],pro[n],turn_a_t=0,waiting=0,rtime[n],s=n,i,ct,t,Tq=2;
	for(i=0;i<n;i++){
		pro[i]=i;
		printf("\nEnter Arrival Time of pro[%d] process : ",i+1);
		scanf("%d",&arrival[i]);
		printf("Enter Burst Time of pro[%d] process : ",i+1);
		scanf("%d",&burst[i]);
		rtime[i]=burst[i];
	}
	system("cls");
	printf("\n\t\t\t\t*** Result ***\n");
	printf("\t\t\t\t==============\n");
	printf("\nProcess\t|  arrival Time |   Burst Time  |Turnaround Time|   Waiting Time\n");
	for(t=0,ct=0;s!=0;)
	{
		if(rtime[ct]<=Tq&&rtime[ct]>0)
		{
			t=t+rtime[ct];
			rtime[ct]=0;
			
		}
		else if(rtime[ct]>0)
		{
		rtime[ct]-=Tq;
		t=t+Tq;
		}
		if(rtime[ct]==0)
		{
		s--;
		printf("Pro[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",ct+1,arrival[ct],burst[ct],t-arrival[ct],t-arrival[ct]-burst[ct]);
		waiting+=t-arrival[ct]-burst[ct];
		turn_a_t+=t-arrival[ct];
		
		}
		if(ct==n-1)
		ct=0;
		else if(arrival[ct+1]<=t)
		ct++;
		else
		ct=0;
	}
printf("\n\n\nAverage Waiting Time= %f\n",waiting*1.0/n);
printf("Average Turn-around-Time = %f",turn_a_t*1.0/n);
}

