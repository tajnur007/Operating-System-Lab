/*  Implementation of Round Robin (RR)
    CPU Scheduling Algorithm

    Implemented by Kazi Tajnur Islam
    Student ID: 15-0-52-020-028
    Year & Semester: 3rd Year 1st Semester
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, bt[10], wt[10], tat[10], t, ct[10], maximum;
    float tot_wt=0,tot_tat=0,temp=0;

    cout << "Enter the no of processes: ";
    cin >> n;

    for(i=0;i<n;i++) {
        cout << "\nEnter Burst Time for process " << i+1 << ": ";
        cin >> bt[i];
        ct[i]=bt[i];
    }

    cout << "\nEnter the size of time slice: ";
    cin >> t;

    maximum = bt[0];
    for(i=1; i<n; i++)
        if(maximum < bt[i])
            maximum = bt[i];

    for(j=0; j<(maximum/t)+1; j++)
        for(i=0; i<n; i++)
            if(bt[i]!=0)
                if(bt[i]<=t) {
                    tat[i]=temp+bt[i];
                    temp=temp+bt[i];
                    bt[i]=0;
                }
                else {
                    bt[i]=bt[i]-t;
                    temp=temp+t;
                }

    for(i=0;i<n;i++) {
        wt[i]=tat[i]-ct[i];
        tot_tat+=tat[i];
        tot_wt+=wt[i];
    }

    cout << "\n\tPROCESS\t\t BT \t\t WT\t\tTT\n";
    for(i=0; i<n; i++)
    cout << "\t" << i+1 << " \t\t " << ct[i] << " \t\t " << wt[i] << " \t\t " << tat[i] << "\n";

    cout << "\nThe Average Turnaround time is " << tot_tat/n;
    cout << "\nThe Average Waiting time is " << tot_wt/n;

    return 0;
}


/* Input:

    3

    7
    6
    3
    3
*/
