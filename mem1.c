#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *mem;
    int i;
    printf("How many integers to allocate? ");
    scanf("%d", &n);
    
    mem = (int*)calloc(n, sizeof(int));
    
    if (mem == NULL) {
        printf("Out of memory\n");
        exit(0);
    }

    // Insert values into reserved memory
    /*for(i = 1; i <= n; i++) {
        mem[i-1] = i + 3000;
    }*/

    // Print values in reserved memory
    for(i = 0; i < n; i++) {
        printf("%d, ", mem[i]);
    }

    printf("\n");

    free(mem);
    mem = NULL;
    printf("Memory dealocated\n");
    return 0;
}