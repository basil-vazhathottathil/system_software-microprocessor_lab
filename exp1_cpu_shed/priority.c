#include <stdio.h>

void main(){
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
