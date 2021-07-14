/*  Implementation of Shortest Job First (SJF)
    CPU Scheduling Algorithm

    Implemented by Kazi Tajnur Islam
    Student ID: 15-0-52-020-028
    Year & Semester: 3rd Year 1st Semester
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int bt[20], p[20], wt[20], tat[20], i, j, n, total_wt=0, total_tat=0, temp;
    float  avg_wt, avg_tat;

    printf("Enter number of process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&bt[i]);
    }

    for(i=2;i<=n;i++)
    {
        for(j=1;j<=n;j++)
           {
               if(bt[i]<bt[j])
               {
                  temp=bt[j];
                  bt[j]=bt[i];
                  bt[i]=temp;
               }
           }
    }

    wt[1]=0;
    for(i=2;i<=n;i++)
    {
        wt[i]=0;
        for(j=1;j<i;j++)
            wt[i]+=bt[j];
            total_wt+=wt[i];
    }

    printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time");
    for(i=1;i<=n;i++)
       {
          tat[i]=bt[i]+wt[i];
          total_tat+=tat[i];
          printf("\np%d\t\t %d\t\t %d\t\t %d",i,bt[i],wt[i],tat[i]);
       }

    avg_wt=(float)total_wt/n;
    avg_tat=(float)total_tat/n;

    printf("\nTotal waiting time:%d",total_wt);
    printf("\nTotal turnaround time:%d",total_tat);

    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);


    return 0;
}


/* Input:

    4

    4
    8
    3
    7
*/

