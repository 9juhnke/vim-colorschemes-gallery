#include <stdio.h>
#include <stdlib.h>
#define BLKSIZE 8

int main(void) {
    int n = 0, max = BLKSIZE, z, i;
    int *numbers = calloc(BLKSIZE, sizeof(*numbers));
    if (numbers == NULL) {
        return EXIT_FAILURE;
    }
    printf("Insert numbers here --- 0 = quit\n");
    while (1) {
        printf("Number (%d): ", n + 1);
        scanf("%d", &z);
        if (z == 0) break;
        if (n >= max -1) {
            max += BLKSIZE;
            numbers = realloc(numbers, max * sizeof(*numbers));
            if (numbers == NULL) {
                return EXIT_FAILURE;
            }
            printf("New storage : %d Bytes\n", (int) (sizeof(int) * BLKSIZE));
            printf("Overall     : %d Bytes\n", (int) (sizeof(int) * max));
            printf("Space for   : %d elements\n", max);
        }
        numbers[n++] = z;
    }
    printf("Numbers given ->\n\n");
    for (i= 0; i < n; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    free(numbers);
    return EXIT_SUCCESS;
}
