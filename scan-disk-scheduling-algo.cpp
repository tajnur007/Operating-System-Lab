/*  Implementation of SCAN Disk Scheduling Algorithm

    Implemented by Kazi Tajnur Islam
    Student ID: 15-0-52-020-028
    Year & Semester: 3rd Year 1st Semester
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,sum=0,n;
    int d[20];
    int disk;   //loc of head
    int temp,max;
    int dloc;   //loc of disk in array

    printf("Enter number of location: ");
    scanf("%d",&n);

    printf("Enter position of head: ");
    scanf("%d",&disk);

    printf("Enter elements of disk queue\n");
    for(i=0;i<n;i++)
        scanf("%d",&d[i]);

    d[n]=disk;
    n=n+1;

    for(i=0;i<n;i++)    // sorting disk locations
    {
        for(j=i;j<n;j++)
        {
            if(d[i]>d[j])
            {
                temp=d[i];
                d[i]=d[j];
                d[j]=temp;
            }
        }
    }

    max=d[n];
    for(i=0;i<n;i++)   // to find loc of disc in array
        if(disk==d[i]) { dloc=i; break;  }

    for(i=dloc;i>=0;i--)
        printf("%d -->",d[i]);

    printf("0 -->");
    for(i=dloc+1;i<n;i++)
        printf("%d-->",d[i]);

    sum = disk+max;

    printf("\n\nMovement of total cylinders %d\n",sum);

    return 0;
}



/* Input:

    8
    53
    98 183 37 122 14 124 65 67

*/

