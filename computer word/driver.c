#include <stdio.h>

typedef char SET;

void displayBitPattern(SET s)
{
	int bit = sizeof(s) * 8 - 1;
	unsigned int masked = 1 << bit;
	
    int count = 1;
	while (masked > 0) {
		if (masked & s) printf("1");
		else printf("0");

        if (count++ % 4 == 0) printf(" ");
		masked >>= 1;
	}
	printf("\n");
}

// data is just the position of the bit :)
void insertToSet(SET *s, int data)
{
    if (data <= sizeof(*s) * 8) *s = *s | (1 << data);
}

// data is just the position of the bit :)
void deleteFromSet(SET *s, int data)
{
    if (data <= sizeof(*s) * 8) *s = *s & ~(1 << data);
}

void populate(SET *s, int data[], int size)
{
    for (int i = 0; i < size; i++)
        insertToSet(s, data[i]);
}

void displayElement(SET s)
{
    int bit = sizeof(s) * 8 - 1;
	unsigned int masked = 1 << bit;
	
    printf("Elements: { ");
	while (masked > 0) {
		if (masked & s) printf("%d ", bit);

		masked >>= 1;
        bit--;
	}
	printf("}\n");
}

SET unionSet(SET A, SET B)
{
    return A | B;
}

SET intersectionSet(SET A, SET B)
{
    return A & B;
}

SET setDifference(SET A, SET B)
{
    return A & ~B;
}

int main()
{

    SET A = 41;
    printf("Bit Pattern of SET A = %d\n", A);
    displayBitPattern(A);
    displayElement(A);
    /**
     *    SET     Bit
     *    |    |||||||||
     *    v    vvvvvvvvv
     *    41 = 0010 1001
     *           |  |  |
     *           5  3  0   <== elements
     * 
     **/


    SET B = 14;
    printf("\nBit Pattern of SET B = %d\n", B);
    displayBitPattern(B);
    displayElement(B);
    /**
     *    SET     Bit
     *    |    |||||||||
     *    v    vvvvvvvvv
     *    14 = 0000 1110
     *              |||
     *              321   <== elements
     * 
     **/


    SET C;
    int data[] = {0, 4, 7, -1};
    populate(&C, data, 4);
    printf("\nBit Pattern of SET C = %d\n", C);
    displayBitPattern(C);
    displayElement(C);
    /**
     *    SET     Bit
     *    |    |||||||||
     *    v    vvvvvvvvv
     *  -111 = 1001 0001
     *         |  |    |
     *         7  4    0   <== elements : see data[]
     * 
     **/

    deleteFromSet(&C, 4);
    printf("\nBit Pattern of SET C = %d\n", C);
    displayBitPattern(C);
    displayElement(C);

    SET D;
    D = unionSet(A, B);

    printf("\n\n");
    printf("Performing A union B...\n");
    printf("Bit Pattern of SET D = %d\n", D);
    displayBitPattern(D);
    displayElement(D);
    /**
     *             UNION
     *    SET A         0010 1001  <====== 41
     *    SET B         0000 1110  <====== 14
     *                  =========       ======
     *    SET D         0010 1111  <====== 47
     * 
     * 
     *    Count the position of the ON bits to know the element/s.
     *      Start from the right and count starts from 0.
     *    
     **/

    SET E;
    E = intersectionSet(A, B);
    
    printf("\n\n");
    printf("Performing A intersection B...\n");
    printf("Bit Pattern of SET E = %d\n", E);
    displayBitPattern(E);
    displayElement(E);
    /**
     *             INTERSECTION
     *    SET A         0010 1001  <====== 41
     *    SET B         0000 1110  <====== 14
     *                  =========       ======
     *    SET E         0000 1000  <====== 8
     *    
     *    Count the position of the ON bits to know the element/s.
     *      Start from the right and count starts from 0.
     **/

    SET F;
    F = setDifference(A, B);

    printf("\n\n");
    printf("Performing A difference B...\n");
    printf("Bit Pattern of SET F = %d\n", F);
    displayBitPattern(F);
    displayElement(F);
    /**
     *             SET DIFFERENCE
     *    SET A         0010 1001  <====== 41
     *    SET B         0000 1110  <====== 14
     *                  =========       ======
     *    SET F         0010 0001  <====== 33
     *    
     *    Count the position of the ON bits to know the element/s.
     *      Start from the right and count starts from 0.
     **/

    return 0;
}