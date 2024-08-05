#include <stdio.h>
#include <stdlib.h>

void FCFS();
void SJF();
void Priority();
void Round_robin();

int main(){
	int choice;
	
	while(choice!=5){
		printf("\n1.FCFS 2.SJF 3.PRIORITY 4.ROUNDROBIN 5.EXIT");
		printf("\nenter your choice\t");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				FCFS();
				break;
			}
			case 2:{
				SJF();
				break;
			}
			case 3:{
				Priority();
				break;
			}
			case 4:{
				Round_robin();
				break;
			}
			default:{
				exit(0);
				}
		}
	}
}


void FCFS(){
	int lim;
	printf("enter the total number of processes\t");
	scanf("%d",&lim);
	
	int process[lim],wt[lim],bt[lim],tat[lim];
	
	printf("enter the processes and their bt\n");
	for (int i=0;i<lim;i++){
		scanf("%d%d",&process[i],&bt[i]);
		}
		
	wt[0]=0;
	tat[0]=bt[0];
	
	float tot_wt=wt[0],tot_tat=tat[0];
	
	for (int i=1; i<lim; i++){
		wt[i]= wt[i-1] + bt[i-1];
		tat[i]= tat[i-1] + bt[i];
		tot_wt += wt[i];
		tot_tat += tat[i];
		}
		
	printf("Process\tBT\tWT\tTAT\n");
   	for (int i = 0; i < lim; i++) {
        	printf("%d\t%d\t%d\t%d\n", process[i], bt[i], wt[i], tat[i]);
    		}
   	printf("total wt= %f\ntotal tat=%f\n",tot_wt,tot_tat);	
    	printf ("\naverage waiting time is %.2f\naverage turn around time is %.2f\n",tot_wt/lim,tot_tat/lim);
    	
    	printf("\tGANTT chart\n");
    	for (int i=0;i <lim; i++){
    		printf("\tP%d",process[i]);
    		}
    	printf("\n");
    	for (int i=0;i<lim;i++){
    		printf("     %d\t",wt[i]);
    		}
    	printf("   %d\t",tat[lim-1]);
    	printf("\n");		
    }


void SJF(){
	int lim;
	printf("enter the total number of processes\t");
	scanf("%d",&lim);
	
	int process[lim],wt[lim],bt[lim],tat[lim];
	
	printf("enter the processes and their bt\n");
	for (int i=0;i<lim;i++){
		scanf("%d%d",&process[i],&bt[i]);
		}
		
	int j,temp;
    	for (int i = 0; i < lim - 1; i++) {
		for (j = i + 1; j < lim; j++) {
		    if (bt[i] > bt[j]) {
		        temp = bt[i];
		        bt[i] = bt[j];
		        bt[j] = temp;
		        
		        temp = process[i];
		        process[i] = process[j];
		        process[j] = temp;
		    		}
        		}
  		}
		
	wt[0]=0;
	tat[0]=bt[0];
	
	float tot_wt=wt[0],tot_tat=tat[0];
	
	for (int i=1; i<lim; i++){
		wt[i]= wt[i-1] + bt[i-1];
		tat[i]= tat[i-1] + bt[i];
		tot_wt += wt[i];
		tot_tat += tat[i];
		}
		
	printf("Process\tBT\tWT\tTAT\n");
   	for (int i = 0; i < lim; i++) {
        	printf("%d\t%d\t%d\t%d\n", process[i], bt[i], wt[i], tat[i]);
    		}
    	printf("total wt= %f\ntotal tat=%f\n",tot_wt,tot_tat);
    	printf ("\naverage waiting time is %.2f\naverage turn around time is %.2f\n",tot_wt/lim,tot_tat/lim);
    	
    	printf("\tGANTT chart\n");
    	for (int i=0;i <lim; i++){
    		printf("\tP%d",process[i]);
    		}
    	printf("\n");
    	for (int i=0;i<lim;i++){
    		printf("     %d\t",wt[i]);
    		}
    	printf("   %d\t",tat[lim-1]);
    	printf("\n");		
    }
    
    
void Priority(){
	int lim;
	printf("enter the total number of processes\t");
	scanf("%d",&lim);
	
	int process[lim],wt[lim],bt[lim],tat[lim],priority[lim];
	
	printf("enter the processes , bt and their priority\n");
	for (int i=0;i<lim;i++){
		scanf("%d%d%d",&process[i],&bt[i],&priority[i]);
		}
		
	int j,temp;
    	for (int i = 0; i < lim - 1; i++) {
		for (j = i + 1; j < lim; j++) {
		    if (priority[i] > priority[j]) {
		        temp = priority[i];
		        priority[i] = priority[j];
		        priority[j] = temp;
		        
		        temp = process[i];
		        process[i] = process[j];
		        process[j] = temp;
		        
		        temp= bt[i];
		        bt[i]=bt[j];
		        bt[j]=temp;
		    		}
        		}
  		}
		
	wt[0]=0;
	tat[0]=bt[0];
	
	float tot_wt=wt[0],tot_tat=tat[0];
	
	for (int i=1; i<lim; i++){
		wt[i]= wt[i-1] + bt[i-1];
		tat[i]= tat[i-1] + bt[i];
		tot_wt += wt[i];
		tot_tat += tat[i];
		}
		
	printf("Process\tBT\tpri\tWT\tTAT\n");
   	for (int i = 0; i < lim; i++) {
        	printf("%d\t%d\t%d\t%d\t%d\n", process[i], bt[i],priority[i], wt[i], tat[i]);
    		}
    	printf("total wt= %f\ntotal tat=%f\n",tot_wt,tot_tat);
    	printf ("\naverage waiting time is %.2f\naverage turn around time is %.2f\n",tot_wt/lim,tot_tat/lim);
    	
    	printf("\tGANTT chart\n");
    	for (int i=0;i <lim; i++){
    		printf("\tP%d",process[i]);
    		}
    	printf("\n");
    	for (int i=0;i<lim;i++){
    		printf("     %d\t",wt[i]);
    		}
    	printf("   %d\t",tat[lim-1]);
    	printf("\n");		
    }
    
    
void Round_robin(){
	int time_qu,lim,completed=0,time=0,k=1,tot_wt=0,tot_tat=0;
	printf ("\nenter the time quantum\t");
	scanf("%d",&time_qu);
	printf("\nenter the number of processes\t");
	scanf("%d",&lim);
	int pro[lim],bt[lim],wt[lim],tat[lim],rem_bt[lim],new[30];
	printf("\nenter the processes and their respective burst time\n");
	for (int i=0;i<lim;i++){
		scanf("%d%d",&pro[i],&bt[i]);
		rem_bt[i]=bt[i];
		}
	while(completed<lim){
		for (int i=0;i<lim;i++){
			if (rem_bt[i] > 0){
				if (rem_bt[i] > time_qu){
					printf("    P%d\t",pro[i]);
					time+=time_qu;
					rem_bt[i]-=time_qu;
					new[k]=time;
					k++;
					}
				else{
					printf("    P%d\t",pro[i]);
					time += rem_bt[i];
					wt[i]= time- bt[i];
					rem_bt[i]=0;
					completed++;
					tat[i]=time;
					new[k]=time;
					k++;
					tot_wt += wt[i];
					tot_tat += tat[i];
					}
				}
			}
		}
	
	new[0]=0;
	printf("\n");
	for (int i=0;i<k;i++){
		printf(" %d\t",new[i]);
		}
	float avg_wt,avg_tat;
	avg_wt=tot_wt/lim;
	avg_tat=tot_tat/lim;
	
	printf("\ntotal wt =%d\ntotal tat= %d\naverage wt=%.2f\naverage tat=%.2f\n",tot_wt,tot_tat,avg_wt,avg_tat);
	}
