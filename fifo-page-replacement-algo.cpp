/*  Implementation of FIFO
    Page Replacement Algorithm

    Implemented by Kazi Tajnur Islam
    Student ID: 15-0-52-020-028
    Year & Semester: 3rd Year 1st Semester
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n,a[50],frame[10],no,k,avail,count=0;
    printf("\nenter the length of the Reference string: ");
    scanf("%d",&n);

    printf("\n enter the reference string: ");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    printf("\n enter the number of Frames: ");
    scanf("%d",&no);
    for(i=0;i<no;i++)
        frame[i]= -1;

    j=0;
    printf("\tref string\t page frames\n");
    for(i=1;i<=n;i++) {
        printf("%d\t\t",a[i]);
        avail=0;
        for(k=0;k<no;k++)
            if(frame[k]==a[i])
                avail=1;
        if (avail==0){
            frame[j]=a[i];
            j=(j+1)%no;
            count++;
            for(k=0;k<no;k++)
            printf("%d\t",frame[k]);
        }
        printf("\n\n");
    }

    printf("Page Fault Is %d\n",count);

    return 0;
}


/* Input:

    20

    7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

    3

*/

