#include <stdio.h>

#define MAX_FRAMES 3   // Number of frames in memory
#define MAX_PAGES 10   // Maximum number of pages in the reference string

// Function to find the Least Recently Used page
int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

// Function to simulate the LRU page replacement algorithm
void simulateLRU(int pages[], int n) {
    int memory[MAX_FRAMES], time[MAX_FRAMES];
    int pageFaults = 0;

    // Initialize the memory and time arrays
    for (int i = 0; i < MAX_FRAMES; i++) {
        memory[i] = -1;  // Initially, memory is empty
        time[i] = -1;    // Time array is also initialized
    }

    // Simulate the page reference process
    for (int i = 0; i < n; i++) {
        int found = 0;  // Flag to check if the page is already in memory

        // Check if the page is already in memory
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                time[j] = i;  // Update the time of the accessed page
                break;
            }
        }

        // If the page is not found in memory, perform page replacement
        if (!found) {
            int lru = findLRU(time, MAX_FRAMES);  // Find the least recently used page
            memory[lru] = pages[i];  // Replace the LRU page with the new page
            time[lru] = i;           // Update the time of the newly inserted page
            pageFaults++;            // Increment the page fault count
        }

        // Print the current state of memory
        printf("\nMemory after reference to page %d: ", pages[i]);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (memory[j] != -1) {
                printf("%d ", memory[j]);
            }
        }
    }

    printf("\n\nTotal number of page faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES], n;

    // Input the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    // Input the page reference string
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Simulate the LRU page replacement
    simulateLRU(pages, n);

    return 0;
}

