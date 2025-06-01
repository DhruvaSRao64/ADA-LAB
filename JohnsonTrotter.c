#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

// Structure to store element and its direction
typedef struct {
    int value;
    int dir;  // -1 = LEFT, 1 = RIGHT
} Element;

// Function to print a permutation
void printPermutation(Element *perm, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i].value);
    }
    printf("\n");
}

// Function to find the largest mobile element's index
int getLargestMobile(Element *perm, int n) {
    int mobile_index = -1;
    int mobile_value = 0;

    for (int i = 0; i < n; i++) {
        int next_index = i + perm[i].dir;
        if (next_index >= 0 && next_index < n) {
            if (perm[i].value > perm[next_index].value && perm[i].value > mobile_value) {
                mobile_value = perm[i].value;
                mobile_index = i;
            }
        }
    }
    return mobile_index;
}

// Function to swap two elements
void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Johnson–Trotter main algorithm
void johnsonTrotter(int n) {
    Element perm[n];
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].dir = LEFT;
    }

    printPermutation(perm, n);

    while (1) {
        int mobile_index = getLargestMobile(perm, n);
        if (mobile_index == -1) break;  // No mobile element means we're done

        int next_index = mobile_index + perm[mobile_index].dir;
        swap(&perm[mobile_index], &perm[next_index]);

        // After swapping, reverse the direction of all elements greater than the moved one
        for (int i = 0; i < n; i++) {
            if (perm[i].value > perm[next_index].value) {
                perm[i].dir *= -1;
            }
        }

        printPermutation(perm, n);
    }
}

// Driver code
int main() {
    int n;
    printf("Enter the number of elements for permutation: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
