#include<stdio.h>

void find_wait_time(int process[], int n, int bt[], int wt[])  
{  
     wt[0] = 0;  
     
    for (int  i = 1; i < n ; i++ )  
        wt[i] =  bt[i-1] + wt[i-1] ;  
}  
    

void find_tat_time( int process[], int n,int bt[], int wt[], int tat[])  
{  

    for (int  i = 0; i < n ; i++)  
        tat[i] = bt[i] + wt[i];  
}  
    


void FCFS_avg_time(int process[],int n,int BT[])
{
    int wt[n],tat[n],total_wt=0,total_tat=0;

    find_wait_time(process,n,BT,wt);
    find_tat_time(process,n,BT,wt,tat);

    printf("Processes   Burst time   Waiting time   Turn around time\n");  
    
    // Calculate total waiting time and total turn around time  
    for (int  i=0; i<n; i++)  
    {  
        total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        printf("   %d ",(i+1)); 
        printf("       %d ", BT[i] ); 
        printf("       %d",wt[i] ); 
        printf("       %d\n",tat[i] );  
    }  
    int s=(float)total_wt / (float)n; 
    int t=(float)total_tat / (float)n; 
    printf("Average waiting time = %d",s); 
    printf("\n"); 
    printf("Average turn around time = %d ",t);  



}












void main()
{
    int  process[30];
    int BT[30],n,i,ch=1,choice;
    
   printf("\nEnter the number of process-\n");
   scanf("%d\n",&n);
   
   for(i=0;i<n;i++)
    {
        scanf("\n%d",process[i]);
    }

    printf("Enter the burst time for each process");
    for(i=0;i<n;i++)
    {
    scanf("%d",&BT[i]);
    }

    printf("Enter your choice-\n");
    printf("\n1.FCFS.\n2.\n3.\n4.\n");
    scanf("%d",&choice);
        
     while(ch==1)
     {
         switch(choice)
         {
             case 1:FCFS_avg_time(process,n,BT);
                    break;

             case 2: ;break;
         }
     }

}