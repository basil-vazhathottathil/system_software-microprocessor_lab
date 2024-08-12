#include <stdio.h>
#include <stdlib.h>

void main() {
	int head, lim, seektime = 0, disk_size, direction, temp;
	printf("Enter the total number of requests: ");
	scanf("%d", &lim);
    
	int request[lim + 1];
    
	printf("Enter the head position: ");
	scanf("%d", &head);
	request[0] = head;
    
	printf("Enter the requests:\n");
	for (int i = 1; i <= lim; i++) {
		scanf("%d", &request[i]);
		}
    
	printf("Enter the disk size: ");
	scanf("%d", &disk_size);
    
	printf("Enter the direction (1--right, 0--left): ");
	scanf("%d", &direction);
    
	for (int i = 0; i < lim; i++) {
		for (int j = i + 1; j < lim + 1; j++) {
			if (request[i] > request[j]) {
				temp = request[i];
				request[i] = request[j];
				request[j] = temp;
				}
			}
		}
 
	int head_pos;
	for (head_pos = 0; head_pos <= lim; head_pos++) {
		if (request[head_pos] == head) {
			break;
			}
		}
    
    
	if (direction == 1) {
		for (int i = head_pos; i <= lim; i++) {
			if (i == head_pos) {
				seektime += abs(request[i] - head);
				}
			else {
				seektime += abs(request[i] - request[i - 1]);
				}
			}
       
		if (head_pos> 0) {
			seektime += abs(disk_size - request[lim - 1]);
			seektime += abs(disk_size - request[0]);
			}
		}
	else { 
		for (int i = pos; i >= 0; i--) {
			if (i == pos) {
				seektime += abs(request[i] - head);
				}
			else {
				seektime += abs(request[i] - request[i + 1]);
				}
			}
        
			if (head_pos < lim) {
				seektime += abs(request[0]);
				seektime += abs(request[lim] - request[0]);
				}
			}
    
	printf("Total seek time: %d\n", seektime);
	}
