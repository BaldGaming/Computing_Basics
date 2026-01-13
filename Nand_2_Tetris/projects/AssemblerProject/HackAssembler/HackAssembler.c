#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

int main(int argc, char *argv[])
{
    // Initialization
    const char* assemblyFilename;
    if (argc < 2) {
        fprintf(stderr, "Assembly filename is ../file.asm\n");
        assemblyFilename = "../file.asm";
    } else {
        assemblyFilename = argv[1];
    }

    if (!parser_init(assemblyFilename)) {
        fprintf(stderr, "Usage: assembler filename (default ../file.asm)\n");
        perror("fopen");
        exit(0);
    }

    char line[LINE_MAX_SIZE];
    char symbol[LINE_MAX_SIZE];
    char addressStr[LINE_MAX_SIZE];
    char dest[LINE_MAX_SIZE], comp[LINE_MAX_SIZE], jump[LINE_MAX_SIZE];
    int lineCounter = 0;

    // SymbolTable module
    symbolTable_addEntry("R0", 0); symbolTable_addEntry("R1", 1); symbolTable_addEntry("R2", 2); symbolTable_addEntry("R3", 3);
    symbolTable_addEntry("R4", 4); symbolTable_addEntry("R5", 5); symbolTable_addEntry("R6", 6);
    symbolTable_addEntry("R7", 7); symbolTable_addEntry("R8", 8); symbolTable_addEntry("R9", 9);
    symbolTable_addEntry("R10", 10); symbolTable_addEntry("R11", 11); symbolTable_addEntry("R12", 12);
    symbolTable_addEntry("R13", 13); symbolTable_addEntry("R14", 14); symbolTable_addEntry("R15", 15);

    symbolTable_addEntry("SCREEN", 16384);
    symbolTable_addEntry("KBD", 24576);
    symbolTable_addEntry("SP", 0);
    symbolTable_addEntry("LCL", 1);
    symbolTable_addEntry("ARG", 2);
    symbolTable_addEntry("THIS", 3);
    symbolTable_addEntry("THAT", 4);

    symbolTable_print();

    // First pass
    printf("\nFirst Pass:\n");
    while (parser_parseNextLine(line)) {
        
        if (parser_instructionType() == L_INSTRUCTION) {
            parser_symbol(symbol);
            symbolTable_addEntry(symbol, lineCounter);
            printf("symbol= %-33s, label : %s", symbol, line);
        }
        else if (parser_instructionType() != COMMENT_OR_EMPTY) {
            lineCounter++;
        }
    }


    // Second pass
    printf("\nSecond Pass:\n");
    parser_rewind();

    // Setup output file
    char hackFilename[100];
    strcpy(hackFilename, assemblyFilename);
    char* dotPosition = strrchr(hackFilename, '.');
    if (dotPosition != NULL) {
        strcpy(dotPosition + 1, "hack");
    }
    FILE* hackFP = fopen(hackFilename, "wt");
    if (hackFP == NULL) {
        perror("fopen");
        exit(0);
    }

    int nextVariableAddress = 16;

    while (parser_parseNextLine(line)) {
        if (parser_instructionType() == COMMENT_OR_EMPTY || parser_instructionType() == L_INSTRUCTION)
            continue;

        if (parser_instructionType() == A_INSTRUCTION) {
            char addressBinary[20];
            parser_address(addressStr);
            int addressValue;

            // Check if the address is a number or a symbol
            if (isdigit(addressStr[0])) {
                addressValue = atoi(addressStr);
            }

            else {
                addressValue = symbolTable_getAddress(addressStr);
                
                // If symbol is not in table, it's a new variable 
                if (addressValue == -1) {
                    symbolTable_addEntry(addressStr, nextVariableAddress);
                    addressValue = nextVariableAddress++;
                }
            }

            // Translate address to 16-bit binary string
            code_convertIntToBinString(addressValue, addressBinary);
            fprintf(hackFP, "%s\n", addressBinary);
        }

        else if (parser_instructionType() == C_INSTRUCTION) {
            char destBinary[4], compBinary[8], jumpBinary[4];

            // Get symbolic fields
            parser_dest(dest);
            parser_comp(comp);
            parser_jump(jump);

            // If dest is empty and jump is empty, it's an invalid instruction
            if (strlen(dest) == 0 && strlen(jump) == 0) {
                fprintf(stderr, "Error: C-instruction at line %d must have a dest or a jump.\n", lineCounter);
                fclose(hackFP);
                exit(1); 
            }

            // Translate symbolic fields to binary bits
            code_dest(dest, destBinary);
            code_comp(comp, compBinary);
            code_jump(jump, jumpBinary);

            // Assemble the 16-bit instruction: 111 + comp + dest + jump
            fprintf(hackFP, "111%s%s%s\n", compBinary, destBinary, jumpBinary);
        }
    }

    fclose(hackFP);
    printf("\nClosing the output file.\n");
    return 0;
}