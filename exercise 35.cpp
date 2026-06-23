#include <stdio.h>
#include <string.h>

#define MAX_BLOCKS 5   // Maximum number of data blocks
#define MAX_FILE_SIZE 50  // Maximum size of each block

// Structure to represent the file system
typedef struct {
    char data[MAX_BLOCKS][MAX_FILE_SIZE];  // Data blocks to store file data
    int indexBlock[MAX_BLOCKS];  // Index block to store pointers to data blocks
} FileSystem;

// Function to initialize the file system
void initializeFileSystem(FileSystem *fs) {
    // Initialize the data blocks with default data
    for (int i = 0; i < MAX_BLOCKS; i++) {
        snprintf(fs->data[i], MAX_FILE_SIZE, "Data Block %d", i + 1);
        fs->indexBlock[i] = i;  // Pointing to corresponding data block
    }
}

// Function to access a specific block in the file
void accessBlock(FileSystem *fs, int blockNumber) {
    if (blockNumber < 1 || blockNumber > MAX_BLOCKS) {
        printf("Error: Invalid block number! Please enter a number between 1 and %d.\n", MAX_BLOCKS);
        return;
    }
    
    // Find the corresponding block pointer from the index block
    int index = fs->indexBlock[blockNumber - 1];  // indexBlock[0] -> data block 1, indexBlock[1] -> data block 2, etc.
    
    // Output the content of the data block
    printf("Accessing Block %d: %s\n", blockNumber, fs->data[index]);
}

int main() {
    FileSystem fs;
    int blockNumber;

    // Initialize the file system
    initializeFileSystem(&fs);

    // Menu for accessing blocks
    while (1) {
        printf("\nEnter the block number to access (1 to %d) or 0 to exit: ", MAX_BLOCKS);
        scanf("%d", &blockNumber);
        
        if (blockNumber == 0) {
            break;  // Exit the loop if the user enters 0
        }
        
        // Access the requested block
        accessBlock(&fs, blockNumber);
    }

    return 0;
}

