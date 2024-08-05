#include<stdio.h>

void main(){
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
