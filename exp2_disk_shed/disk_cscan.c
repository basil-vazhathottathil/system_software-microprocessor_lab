#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
	int temp;
		for(int i = 0; i < n-1; i++) {
			for(int j = i+1; j < n; j++) {
				if(arr[i] > arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

void main() {
	int i, j, n, total_tracks = 0, size, head, direction;
    
	printf("Enter the number of requests: ");
	scanf("%d", &n);

	int requests[n];
	printf("Enter the request sequence: ");
	for(i = 0; i < n; i++) {
		scanf("%d", &requests[i]);
		}

	printf("Enter the initial head position: ");
	scanf("%d", &head);

	printf("Enter the total number of cylinders (disk size): ");
	scanf("%d", &size);

	printf("Enter the direction (1 for high, 0 for low): ");
	scanf("%d", &direction);

	sort(requests, n);

	int index;
    
	for(i = 0; i < n; i++) {
		if(head < requests[i]) {
			index = i;
			break;
			}
		}


	if(direction == 1) {
	for(i = index; i < n; i++) {
		total_tracks += abs(requests[i] - head);
		head = requests[i];
		}

	total_tracks += abs((size - 1) - head);
	head = size - 1;

	total_tracks += abs(head - 0);
	head = 0;
	for(i = 0; i < index; i++) {
		total_tracks += abs(requests[i] - head);
		head = requests[i];
		}
	} 

	else {
	for(i = index - 1; i >= 0; i--) {
		total_tracks += abs(requests[i] - head);
		head = requests[i];
		}

	total_tracks += abs(head - 0);
	head = 0;

	total_tracks += abs((size - 1) - head);
	head = size - 1;
	for(i = n-1; i >= index; i--) {
		total_tracks += abs(requests[i] - head);
		head = requests[i];
		}
	}

	printf("Total number of tracks moved: %d\n", total_tracks);

}

