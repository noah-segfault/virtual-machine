#include <stdio.h>
#include <stdlib.h>

#define MAX_PAS_LENGTH 500

typedef struct instruction
{
    int opcode;
    int l;
    int m;
} instruction;


int main (void)
{
    
}

/**********************************************/
/*Find base L levels down */
/*                        */
/**********************************************/
int base(int L)
{
    int arb = BP;      // arb = activation record base
    while ( L > 0)     // find base L levels down
    {arb = pas[arb];
    L--;}return arb;
}