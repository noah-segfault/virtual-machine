#include <stdio.h>
#include <stdlib.h>

#define MAX_PAS_LENGTH 500

typedef struct instruction
{
    int opcode;
    int l;
    int m;
} instruction;


int main (int argc, char *argv[])
{
    FILE *fp;

    // Starting variables
    int gp, ic, dp, free, pc, sp, bp, program_length;

    gp = ic;    //Global Pointer – Points to DATA segment
    dp = ic -1;  //Data Pointer – To access variables in Main
    free = ic + 40;  // FREE points to Heap
    bp = ic; // Points to base of DATA or activation records
    pc = 0; // Stack pointer – Points to top of stack  
    sp = MAX_PAS_LENGTH;  
    program_length = 0;
  
    // Initialize all the values to the process address space to zero
    int pas [MAX_PAS_LENGTH + 1] = {0};
    
    FILE *fp = NULL;
    fp = fopen(argv[1], "r");
   
    if (fp == NULL)
    {
        return EXIT_FAILURE;
    }
    
    int i = 1;
    while(!feof(fp))
    {
        fscanf(fp, "%d", &pas[i]);
        
        // For checking when the end of a line has been reached
        if ((i % 3 == 0) && (i == 0))
        {
            program_length++;
        }
        
        i++;
    }
    ic = i;

    // Initialize the CPU register values after getting everything into the PAC, updating the values here
    bp = program_length * 3;
    gp = bp;
    dp = ic - 1;
    free = ic + 40;

    return 0;
}

/**********************************************/
/*Find base L levels down */
/*                        */
/**********************************************/
int base(int L, int bp, int pas[])
{
    int arb = bp;      // arb = activation record base
    while ( L > 0)     // find base L levels down
    {
        arb = pas[arb];
        L--;
    }
    return arb;
}