#include <stdio.h>
#include <stdlib.h>

void main(){
	int lim,head,seektime=0,distance;
	printf ("enter the total number of requests\t");
	scanf("%d",&lim);
	int request[lim+1];
	printf("\nenter the position of the head\t");
	scanf("%d",&head);
	
	request[0]= head;
	printf("\nenter the requests\n");
	for (int i=1;i<=lim;i++){
		scanf("%d",&request[i]);
		}
		
	printf("\n\n");
	for (int i=0; i<lim;i++){
		distance = abs(request[i]-request[i+1]);
		printf("Head movement from %d to %d is %d\n",request[i],request[i+1],distance);
		seektime+= distance;
		}
	printf("\n");
	printf("Total seektime is %d\n",seektime);
	}
