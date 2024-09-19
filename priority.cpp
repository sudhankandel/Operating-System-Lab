#include<stdio.h>
int main()
{
int n,bt[20],wt[20],tat[20],p[20],pri[20],i,j,temp;
float avwt=0,avtat=0;
printf("Enter total number of processes(maximum 20) ");
scanf("%d",&n);
printf("Enter Process Burst Time and Priority of Process\n");
for(i=0;i<n;i++)
{
p[i]=i;
printf("P[%d]: ",i);
scanf("%d%d",&bt[i],&pri[i]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(pri[i]>pri[j])
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
temp=pri[i];
pri[i]=pri[j];
pri[j]=temp;
}
}
}
wt[0]=0; //waiting time for first process is 0
for(i=1;i<n;i++) //calculating waiting time
{
wt[i]=0;
for(j=0;j<i;j++)
{
wt[i]=wt[i]+bt[j];
}
}
printf("\nProcess\tPriority\tBurstTime\tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++) //calculating turnaround time
{
tat[i]=bt[i]+wt[i];
avwt=avwt+wt[i];
avtat=avtat+tat[i];
printf("\nP[%d]\t%d\t\t%d\t\t%d\t\t%d",p[i],pri[i],bt[i],wt[i],tat[i]);
}
avwt=avwt/i;
avtat=avtat/i;
printf("\n\nAverage waiting time:%.2f",avwt);
printf("\nAverage turnaround time:%.2f",avtat);
}