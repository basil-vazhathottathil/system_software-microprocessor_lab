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

void fcfs(int requests[], int n, int head) {
        int total_tracks = 0;
        for(int i = 0; i < n; i++) {
                total_tracks += abs(requests[i] - head);
                head = requests[i];
        }
        printf("Total number of tracks moved (FCFS): %d\n", total_tracks);
}

void scan(int requests[], int n, int head, int size, int direction) {
        int total_tracks = 0;
        sort(requests, n);

        int index;
        for(int i = 0; i < n; i++) {
                if(head < requests[i]) {
                        index = i;
                        break;
                }
        }

        if(direction == 1) {
                for(int i = index; i < n; i++) {
                        total_tracks += abs(requests[i] - head);
                        head = requests[i];
                }
                total_tracks += abs((size - 1) - head);
                head = size - 1;
                for(int i = index - 1; i >= 0; i--) {
                        total_tracks += abs(requests[i] - head);
                        head = requests[i];
                }
        } else {
                for(int i = index - 1; i >= 0; i--) {
                        total_tracks += abs(requests[i] - head);
                        head = requests[i];
                }
                total_tracks += abs(head - 0);
                head = 0;
                for(int i = index; i < n; i++) {
                        total_tracks += abs(requests[i] - head);
                        head = requests[i];
                }
        }

        printf("Total number of tracks moved (SCAN): %d\n", total_tracks);
}

void cscan(int requests[], int n, int head, int size, int direction) {
        int total_tracks = 0;
        sort(requests, n);

        int index;
        for(int i = 0; i < n; i++) {
                if(head < requests[i]) {
                        index = i;
                        break;
                }
        }

        if(direction == 1) {
                for(int i = index; i < n; i++) {
                        total_tracks += abs(requests[i] - head);
                        head = requests[i];
                }
                total_tracks += abs((size - 1) - head);
                head = size - 1;
                total_tracks += abs(head - 0);
                head = 0;
                for(int i = 0; i < index; i++) {
                        total_tracks += abs(requests[i] - head);
                        head = requests[i];
                }
        } else {
                for(int i = index - 1; i >= 0; i--) {
                        total_tracks += abs(requests[i] - head);
                        head = requests[i];
                }
                total_tracks += abs(head - 0);
                head = 0;
                total_tracks += abs((size - 1) - head);
                head = size - 1;
                for(int i = n - 1; i >= index; i--) {
                        total_tracks += abs(requests[i] - head);
                        head = requests[i];
                }
        }

        printf("Total number of tracks moved (C-SCAN): %d\n", total_tracks);
}

void main() {
        int n, head, size, direction;
        int choice;
        do {
                printf("\nDisk Scheduling Algorithms\n");
                printf("1. FCFS\n");
                printf("2. SCAN\n");
                printf("3. C-SCAN\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if(choice == 4) break;

                printf("Enter the number of requests: ");
                scanf("%d", &n);
                int requests[n];
                printf("Enter the request sequence: ");
                for(int i = 0; i < n; i++) {
                        scanf("%d", &requests[i]);
                }

                printf("Enter the initial head position: ");
                scanf("%d", &head);

                if(choice == 2 || choice == 3) {
                        printf("Enter disk size: ");
                        scanf("%d", &size);

                        printf("Enter the direction (1 for high, 0 for low): ");
                        scanf("%d", &direction);
                }

                switch(choice) {
                        case 1:
                                fcfs(requests, n, head);
                                break;
                        case 2:
                                scan(requests, n, head, size, direction);
                                break;
                        case 3:
                                cscan(requests, n, head, size, direction);
                                break;
                        default:
                                printf("Invalid choice!");
                                break;
                }
        } while(choice != 4);

}

