#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a file block
typedef struct Block {
    char data[50];        // Data in the block
    struct Block* next;   // Pointer to the next block
} Block;

// Function to create a new block with data
Block* createBlock(const char* data) {
    Block* newBlock = (Block*)malloc(sizeof(Block));  // Create a new block
    strcpy(newBlock->data, data);  // Store data in the block
    newBlock->next = NULL;         // Next block is NULL for now
    return newBlock;
}

// Function to simulate adding a block to the file
void addBlock(Block** firstBlock, const char* data) {
    Block* newBlock = createBlock(data);
    if (*firstBlock == NULL) {
        // If it's the first block, set it as the starting block
        *firstBlock = newBlock;
    } else {
        // If not, find the last block and link the new block
        Block* temp = *firstBlock;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBlock;
    }
}

// Function to display the file content
void displayFile(Block* firstBlock) {
    if (firstBlock == NULL) {
        printf("The file is empty.\n");
        return;
    }

    Block* temp = firstBlock;
    while (temp != NULL) {
        printf("%s\n", temp->data);  // Print data of each block
        temp = temp->next;           // Move to the next block
    }
}

int main() {
    Block* firstBlock = NULL;  // Pointer to the first block of the file

    // Adding blocks to the file
    addBlock(&firstBlock, "Block 1: Hello");
    addBlock(&firstBlock, "Block 2: Linked");
    addBlock(&firstBlock, "Block 3: Allocation");

    // Display the contents of the file
    printf("File Content:\n");
    displayFile(firstBlock);

    return 0;
}

