#include <stdio.h>
#define SIZE 14
typedef int SET[SIZE];

void displaySet(SET S)
{
    for (int i = 0; i < SIZE; i++) {
        // Need to explicitly compare to 1
        // because I did initialize SET to 0
        // SET may contain 1 as its garbage value :)
        if (S[i] == 1)
            printf("%d ", i);
    }
    printf("\n");
}

void insertToSet(SET S, int data)
{
    S[data] = 1;
}

void populate(SET S, int data[], int size)
{
    for (int i = 0; i < size; i++)
        insertToSet(S, data[i]);
}

int main()
{
    SET A = {1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1};
    /**
     *
     *  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+
     *  | 1 | 0 | 0 | 1 | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 1 | 0 | 1 |
     *  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+
     *    0   1   2   3   4   5   6   7   8   9  10  11  12   13
     * 
     * 
    **/ 
    printf("SET A: ");
    displaySet(A);


    int data[] = {0, 2, 3, 5, 7, 8, 11, 12, 13};
    SET B;
    populate(B, data, 9);
    /**
     *
     *  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+
     *  | 1 | 0 | 1 | 1 | 0 | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 1 |
     *  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+
     *    0   1   2   3   4   5   6   7   8   9  10  11  12   13
     * 
     * 
    **/ 
    printf("SET B: ");
    displaySet(B);
    



    return 0;
}