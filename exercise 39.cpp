#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to implement the C-SCAN disk scheduling algorithm
void C_SCAN(int arr[], int n, int head, int direction) {
    int totalSeekCount = 0;
    int left = 0, right = 0;
    
    int seekSequence[MAX];
    int index = 0;

    // Separate requests to the left and right of the head
    for (int i = 0; i < n; i++) {
        if (arr[i] < head) left++;
        if (arr[i] > head) right++;
    }

    // Arrays to store the left and right tracks
    int leftArr[left], rightArr[right];
    int leftIndex = 0, rightIndex = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < head) leftArr[leftIndex++] = arr[i];
        if (arr[i] > head) rightArr[rightIndex++] = arr[i];
    }

    // Sort both left and right arrays
    for (int i = 0; i < left; i++) {
        for (int j = i + 1; j < left; j++) {
            if (leftArr[i] < leftArr[j]) {
                int temp = leftArr[i];
                leftArr[i] = leftArr[j];
                leftArr[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < right; i++) {
        for (int j = i + 1; j < right; j++) {
            if (rightArr[i] > rightArr[j]) {
                int temp = rightArr[i];
                rightArr[i] = rightArr[j];
                rightArr[j] = temp;
            }
        }
    }

    // If the direction is left to right, service the requests in that direction
    if (direction == 1) {
        // Service requests on the right side
        for (int i = 0; i < right; i++) {
            seekSequence[index++] = rightArr[i];
        }
        
        // Jump to the start of the disk (track 0) and service left side requests
        seekSequence[index++] = head;
        seekSequence[index++] = 0;  // Jump back to track 0
        
        for (int i = left - 1; i >= 0; i--) {
            seekSequence[index++] = leftArr[i];
        }
    } 
    // If the direction is right to left, service the requests in that direction
    else {
        // Service requests on the left side
        for (int i = left - 1; i >= 0; i--) {
            seekSequence[index++] = leftArr[i];
        }

        // Jump to the end of the disk and service right side requests
        seekSequence[index++] = head;
        seekSequence[index++] = MAX - 1;  // Jump to the highest track
        
        for (int i = 0; i < right; i++) {
            seekSequence[index++] = rightArr[i];
        }
    }

    // Calculate the total seek count
    for (int i = 0; i < index - 1; i++) {
        totalSeekCount += abs(seekSequence[i + 1] - seekSequence[i]);
    }

    // Print the seek sequence and total seek count
    printf("\nSeek Sequence: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", seekSequence[i]);
    }

    printf("\nTotal Seek Count: %d\n", totalSeekCount);
}

int main() {
    int arr[] = {50, 10, 20, 35, 40, 70, 60, 90};  // Disk requests
    int n = sizeof(arr) / sizeof(arr[0]);  // Number of disk requests
    int head = 35;  // Initial head position
    int direction = 1;  // 1 for left to right, -1 for right to left

    // Simulate the C-SCAN disk scheduling algorithm
    C_SCAN(arr, n, head, direction);

    return 0;
}

