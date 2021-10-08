#include <stdio.h>
#define SIZE 10

typedef struct {
    int data[SIZE];
    int count;
} SET;

void displaySet(SET A)
{
    for (int i = 0; i < A.count; i++)
        printf("%d ", A.data[i]);
    printf("\n");
}

SET unionSetUnsorted(SET A, SET B)
{
    // set the elements of A to C
    SET C = A;

    int i, j;
    // loop B
    for (i = 0; i < B.count; i++) {
        // check each element of B in C
        for (j = 0; j < C.count && B.data[i] != C.data[j]; j++) {}
        // if the element of B is unique, then insert to C
        if (j == C.count) {
            C.data[C.count++] = B.data[i];
        }
    }

    return C;
}

SET unionSetSorted(SET A, SET B)
{
    SET C = {.count = 0};
    int i, j;
    
    for (i = 0, j = 0; i < A.count && j < B.count ;) {
        if (A.data[i] == B.data[j]) {
            C.data[C.count++] = A.data[i];
            i++;    // para sa A
            j++;    // para sa B
        } else if (A.data[i] < B.data[j]) {
            C.data[C.count++] = A.data[i];
            i++;
        } else {
            C.data[C.count++] = B.data[j];
            j++;
        }
    }

    for (; j < B.count; j++) {
        C.data[C.count++] = B.data[j];
    }


    for (; i < A.count; i++) {
        C.data[C.count++] = A.data[i];
    }
    
    return C;
}

SET intersectionSetUnsorted(SET A, SET B) 
{

}

SET intersectionSetSorted(SET A, SET B) {
    SET C = {.count = 0};

    int i, j;
    for (i = 0; i < A.count; i++) {
        for (j = 0; j < B.count && B.data[j] < A.data[i]; j++) {}
        
        // check if ni exist
        if (j < B.count && B.data[j] == A.data[i]) {
            C.data[C.count++] = A.data[i];
        }
    }

    return C;
}

SET setDifference(SET A, SET B)
{
    SET C = {.count = 0};
    
    int i, j;
    for (i = 0; i < A.count; i++) {
        for (j = 0; j < B.count && A.data[i] != B.data[j]; j++) {}
        if (j == B.count) {
            C.data[C.count++] = A.data[i];
        }
    }

    return C;
}

int main()
{
    SET A = {
        {10, 1, 4, 5, 6}, 
        5
    };

    SET B = {
        {10, 8, 9, 4, 5, 1, 2},
        7
    };

    printf("SET A = ");
    displaySet(A);
    /**
     * 
     *      SET A = {10 1 4 5 6} 
     * 
     **/


    printf("\nSET B = ");
    displaySet(B);
     /**
     * 
     *      SET B = {10 8 9 4 5 1 2}
     * 
     **/

    SET C;
    C = unionSetUnsorted(A, B);
    printf("\nC = A UNION B\n");
    displaySet(C);
     /**
     * 
     *           A UNION B
     *      SET A = {10 1 4 5 6} 
     *      SET B = {10 8 9 4 5 1 2}
     * 
     *      SET C = {10 1 4 5 6 8 9 2}
     * 
     **/


    SET AS = {
        {1, 4, 5, 6, 10},
        5
    };

    SET BS = {
        {1, 2, 4, 5, 8, 9, 10, 11, 12},
        9
    };


    displaySet(AS);
    /**
     *
     *      SET AS = {1 4 5 6 10} 
     * 
     * 
     **/
    displaySet(BS);
    /**
     *
     *      SET BS = {1 2 4 5 8 9 10 11 12}
     * 
     * 
     **/


    SET D;
    D = unionSetSorted(AS, BS);
    printf("\nD = AS UNION BS sorted\n");
    displaySet(D);
    /**
     * 
     *           AS UNION BS
     *      SET AS = {1 4 5 6 10} 
     *      SET BS = {1 2 4 5 8 9 10 11 12}
     * 
     *      SET D = {1 2 4 5 6 8 9 10 11 12}
     * 
     **/

    SET E;
    E = intersectionSetSorted(AS, BS);
    printf("\nE = AS INTERSECTION BS sorted\n");
    displaySet(E);
    /**
     * 
     *           AS INTERSECTION BS
     *      SET AS = {1 4 5 6 10} 
     *      SET BS = {1 2 4 5 8 9 10 11 12}
     * 
     *      SET E = {1 4 5 10}
     * 
     **/


    SET F;
    F = setDifference(AS, BS);
    printf("\nF = AS Difference BS\n");
    displaySet(F);
    /**
     * 
     *           AS DIFFERENCE BS
     *      SET AS = {1 4 5 6 10} 
     *      SET BS = {1 2 4 5 8 9 10 11 12}
     * 
     *      SET F = {6}
     * 
     **/
}

