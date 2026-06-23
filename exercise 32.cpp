#include <stdio.h>

#define MAX_PAGES 10  // Maximum number of pages in memory

// Function to find the least recently used page
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

int main() {
    int frames, pages, pageFaults = 0;
    int pageReferenceString[MAX_PAGES], memory[MAX_PAGES], time[MAX_PAGES];
    
    // Input number of frames and number of pages
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // Input page reference string
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    printf("Enter page reference string:\n");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &pageReferenceString[i]);
    }

    // Initialize memory and time arrays
    for (int i = 0; i < frames; i++) {
        memory[i] = -1;  // -1 indicates an empty slot in memory
        time[i] = -1;    // Initialize the time array to -1 (unused)
    }

    // Process the page reference string
    for (int i = 0; i < pages; i++) {
        int found = 0;  // Flag to indicate if page is found in memory

        // Check if the page is already in memory
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pageReferenceString[i]) {
                found = 1;
                time[j] = i;  // Update the time for the recently used page
                break;
            }
        }

        // If page not found in memory, replace the least recently used page
        if (!found) {
            // Find the least recently used page (oldest entry in time array)
            int lru = findLRU(time, frames);
            memory[lru] = pageReferenceString[i];  // Replace it with the new page
            time[lru] = i;  // Update the time for the newly inserted page
            pageFaults++;    // Increment page fault count
        }

        // Print the current state of memory
        printf("\nMemory after reference to page %d: ", pageReferenceString[i]);
        for (int j = 0; j < frames; j++) {
            if (memory[j] != -1) {
                printf("%d ", memory[j]);
            }
        }
    }

    printf("\n\nTotal number of page faults: %d\n", pageFaults);

    return 0;
}


