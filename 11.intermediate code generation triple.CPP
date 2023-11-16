#include <stdio.h>
#include <stdlib.h>
struct Triple {
    char op;
    char arg1;
    char arg2;
};
void printTriple(struct Triple t) {
    printf("<%c, %c, %c>\n", t.op, t.arg1, t.arg2);
}

int main() {
    struct Triple triples[100]; 
    int tripleCount = 0; 

    // Example expression: a = b + c * d

    // Triple 1: Multiply c and d
    triples[tripleCount].op = '*';
    triples[tripleCount].arg1 = 'c';
    triples[tripleCount].arg2 = 'd';
    tripleCount++;
    triples[tripleCount].op = '+';
    triples[tripleCount].arg1 = 'b';
    triples[tripleCount].arg2 = triples[tripleCount - 1].arg1; 
    tripleCount++;
  
    triples[tripleCount].op = '=';
    triples[tripleCount].arg1 = 'a';
    triples[tripleCount].arg2 = triples[tripleCount - 1].arg1; 
    tripleCount++;

    for (int i = 0; i < tripleCount; i++) {
        printf("Triple %d: ", i + 1);
        printTriple(triples[i]);
    }

    return 0;
}
