/*  Implementation of First Come First Serve (FCFS)
    CPU Scheduling Algorithm

    Implemented by Kazi Tajnur Islam
    Student ID: 15-0-52-020-028
    Year & Semester: 3rd Year 1st Semester
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int at[20], bt[20],ct[20],wt[20],tat[20];
    int i,j,n,tot_wt=0, tot_tat=0, tot_bt=0;
    float avg_wt, avg_tat, throughput;

    printf("Enter the Number of Process: ");
    scanf("%d",&n);

    printf("Enter Process Arrival Time and Burst Time:\n");
    for(i=1;i<=n;i++)
       {
         scanf("%d%d",&at[i],&bt[i]);
       }

     ct[1]=bt[1];
     for(i=2; i<=n;i++)
        {
           ct[i]=ct[i-1]+bt[i];
        }

     for(i=1; i<=n;i++)
         {
           tat[i]=ct[i]-at[i];
           wt[i]=tat[i]-bt[i];
         }

     printf("\nprocess\t  arrive_time\t burst_time\t complete_time\t taround_time\t waiting_time");
     for(i=1; i<=n;i++)
        {
           printf("\nP[%d]\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d",i,at[i],bt[i],ct[i],tat[i],wt[i]);
        }

    for(j=1;j<=n;j++)
       {
          tot_wt=tot_wt + wt[j];
          tot_tat=tot_tat + tat[j];
          tot_bt=tot_bt + bt[j];
       }

    avg_wt=(float)tot_wt/n;
    avg_tat=(float)tot_tat/n;
    throughput= n/(float)tot_bt;

    printf("\nTotal Waiting time=%d", tot_wt);
    printf("\nTotal Turnaround time=%d", tot_tat);
    printf("\nAverage Waiting Time=%f",avg_wt);

    printf("\nAverage Turnaround Time=%f",avg_tat);
    printf("\nThroughput=%f",throughput);


    return 0;
}


/* Input:

    4

    0 5
    1 3
    2 8
    3 6

*/

