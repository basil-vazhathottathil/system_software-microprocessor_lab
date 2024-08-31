#include <stdio.h>
#include <stdlib.h>

void main() {
        int n, head, size, direction, total_tracks = 0;
        printf("Enter the number of requests: ");
        scanf("%d", &n);
        int requests[n];
        printf("Enter the request sequence: ");
        for(int i = 0; i < n; i++) {
                scanf("%d", &requests[i]);
        }
        printf("head position: ");
        scanf("%d", &head);
        printf("disk size: ");
        scanf("%d", &size);
        printf("Enter the direction (1 for high, 0 for low): ");
        scanf("%d", &direction);

        for(int i = 0; i < n-1; i++) {
                for(int j = i+1; j < n; j++) {
                        if(requests[i] > requests[j]) {
                                int temp = requests[i];
                                requests[i] = requests[j];
                                requests[j] = temp;
                        }
                }
        }

        int index = 0;
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

        printf("Total number of tracks moved: %d\n", total_tracks);

}
