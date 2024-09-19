#include<stdio.h>
int main()
{
int i,j,n,bt[10],wt[10],tat[10],t,ct[10],max;
float avwt=0,avtat=0,temp=0;
printf("Enter total number of processes(maximum 20) ");
scanf("%d",&n);
printf("Enter Process Burst Time\n");
for(i=0;i<n;i++)
{
printf("P[%d]: ",i+1);
scanf("%d",&bt[i]);
ct[i]=bt[i];
}
printf("Enter the size of time slice ");
scanf("%d",&t);
max=bt[0];
for(i=1;i<n;i++)
if(max<bt[i])
max=bt[i];
for(j=0;j<(max/t)+1;j++)
for(i=0;i<n;i++)
if(bt[i]!=0)
if(bt[i]<=t)
{
tat[i]=temp+bt[i];
temp=temp+bt[i];
bt[i]=0;
}
else
{
bt[i]=bt[i]-t;
temp=temp+t;
}
printf("\nProcess\tBurstTime\tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++) //calculating turnaround time
{
wt[i]=tat[i]-ct[i];
avtat=avtat+tat[i];
avwt=avwt+wt[i];
printf("\nP[%d]\t%d\t\t%d\t\t%d",i+1,ct[i],wt[i],tat[i]);
}
avwt=avwt/i;
avtat=avtat/i;
printf("\n\nAverage waiting time:%.2f",avwt);
printf("\nAverage turnaround time:%.2f",avtat);
}