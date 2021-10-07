#include <stdio.h>
#define SIZE 14
typedef int SET[SIZE];


void initSet(SET S)
{
    for (int i = 0; i < SIZE; i++)
        S[i] = 0;
}

void displaySet(SET S)
{
    for (int i = 0; i < SIZE; i++)
        if (S[i]) printf("%d ", i);
    printf("\n");
}

void insertToSet(SET S, int data)
{
    if (data >= 0 && data < SIZE) S[data] = 1;
}

void deleteFromSet(SET S, int data)
{
    if (data >= 0 && data < SIZE) S[data] = 0;
}

void populate(SET S, int data[], int size)
{
    for (int i = 0; i < size; i++)
        insertToSet(S, data[i]);
}

// union = all elements in SET A and SET B
SET *unionSet(SET A, SET B)
{
    SET *C = (SET *) calloc (SIZE, sizeof(SET));

    for (int i = 0; i < SIZE; i++)
        (*C)[i] = A[i] | B[i];

    return C;
}

// intersection = all elements of A that also belong to B
SET *intersectionSet(SET A, SET B)
{
    SET *C = (SET *) calloc (SIZE, sizeof(SET));

    for (int i = 0; i < SIZE; i++)
        (*C)[i] = A[i] & B[i];
    
    return C;
}

// set difference = elements in A but not in B
SET *setDifference(SET A, SET B)
{
    SET *C = (SET *) calloc (SIZE, sizeof(SET));

    for (int i = 0; i < SIZE; i++)
        (*C)[i] = A[i] & ~B[i];
    return C;
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
    initSet(B);
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



    SET *C;
    C = unionSet(A, B);
    printf("\nPerforming A union B...\n");
    printf("SET C: ");
    displaySet(C);
    /**
     *
     *  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+
     *  | 1 | 0 | 1 | 1 | 0 | 1 | 1 | 1 | 1 | 1 | 0 | 1 | 1 | 1 |
     *  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+
     *    0   1   2   3   4   5   6   7   8   9  10  11  12   13
     * 
     * 
    **/ 


    SET *D;
    D = intersectionSet(A, B);
    printf("\nPerforming A intersection B...\n");
    printf("SET D: ");
    displaySet(D);
    /**
     *
     *  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+
     *  | 1 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 0 | 1 |
     *  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+
     *    0   1   2   3   4   5   6   7   8   9  10  11  12   13
     * 
     * 
    **/ 


    SET *E;
    E = setDifference(A, B);
    printf("\nPerforming A difference B...\n");
    printf("SET E: ");
    displaySet(E);
    /**
     *
     *  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+
     *  | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 0 | 0 | 0 | 0 |
     *  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+
     *    0   1   2   3   4   5   6   7   8   9  10  11  12   13
     * 
     * 
    **/ 


    return 0;
}