//assembler_modified5.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"
int isNumber(const char* s);

int isNumber(const char* s) {
    if (!s || !*s) return 0;
    for (int i = 0; s[i]; i++) {
        if (!isdigit((unsigned char)s[i])) return 0;
    }
    return 1;

}


int main(int argc, char* argv[])
{
    const char* assemblyFilename;

    if (argc < 2) {
        fprintf(stderr, "Assembly filename is .../file.asm\n");
        assemblyFilename = ".../file.asm";
    }
    else {
        assemblyFilename = argv[1];
    }


    // 2) open input file for the parser
    if (!parser_init(argv[1])) {
        fprintf(stderr, "Usage: assembler filename (default .../file.asm\n)");
        perror("fopen");
        exit(0);
    }




    symbolTable_addEntry("R0", 0);
    symbolTable_addEntry("R1", 1);
    symbolTable_addEntry("R2", 2);
    symbolTable_addEntry("R3", 3);
    symbolTable_addEntry("R4", 4);
    symbolTable_addEntry("R5", 5);
    symbolTable_addEntry("R6", 6);
    symbolTable_addEntry("R7", 7);
    symbolTable_addEntry("R8", 8);
    symbolTable_addEntry("R9", 9);
    symbolTable_addEntry("R10", 10);
    symbolTable_addEntry("R11", 11);
    symbolTable_addEntry("R12", 12);
    symbolTable_addEntry("R13", 13);
    symbolTable_addEntry("R14", 14);
    symbolTable_addEntry("R15", 15);
    symbolTable_addEntry("SCREEN", 16384);
    symbolTable_addEntry("KBD", 24576);
    symbolTable_addEntry("SP", 0);
    symbolTable_addEntry("LCL", 1);
    symbolTable_addEntry("ARG", 2);
    symbolTable_addEntry("THIS", 3);
    symbolTable_addEntry("THAT", 4);

    symbolTable_print();

    char symbol[LINE_MAX_SIZE];
    char addressStr[LINE_MAX_SIZE];
    char dest[LINE_MAX_SIZE];
    char comp[LINE_MAX_SIZE];
    char jump[LINE_MAX_SIZE];
    char line[LINE_MAX_SIZE];
    int counter = 0;

    parser_rewind();

	printf("First Pass:\n");

    while (parser_parseNextLine(line)) {
        if (parser_instructionType() == L_INSTRUCTION) {
            parser_symbol(symbol);
            symbolTable_addEntry(symbol, counter);
            printf("symbol= %-33s, label : %s", symbol, line);
        }
        else if (parser_instructionType() != COMMENT_OR_EMPTY) {
            counter++;
        }
    }

	printf("\nSecond Pass:\n");
    parser_rewind();

    // Setup output file
    char hackFilename[100];
    strcpy(hackFilename, assemblyFilename);
    char* dotPosition = strrchr(hackFilename, '.');
    if (dotPosition != NULL) {
        strcpy(dotPosition + 1, "hack");
    }

    FILE* new_f = fopen("output.hack", "wt");
    if (new_f == NULL) {
        printf("Error\n");
        exit(0);
    }
    
    int nextVar = 17;

    while (parser_parseNextLine(line))
    {
        if (parser_instructionType() == COMMENT_OR_EMPTY)
            continue;
        if (parser_instructionType() == L_INSTRUCTION) {
            continue;
        }
        if (parser_instructionType() == A_INSTRUCTION) {
            parser_address(addressStr);
            int value;
            if (isNumber(addressStr)) {
                value = atoi(addressStr);
            }
            else {
                int addr = symbolTable_getAddress(addressStr);
                if (addr == -1) {
                    symbolTable_addEntry(addressStr, nextVar);
                    addr = nextVar;
                    nextVar++;
                }
                value = addr;
            }
            char bin[17];
            code_convertIntToBinString(value, bin);
            bin[0] = '0';                 // A-instruction starts with 0
            fprintf(new_f, "%s\n", bin);
        }
        else if (parser_instructionType() == C_INSTRUCTION) {
            char destBinary[4], compBinary[8], jumpBinary[4];

            // Get symbolic fields
            parser_dest(dest);
            parser_comp(comp);
            parser_jump(jump);

            // If dest is empty and jump is empty, it's an invalid instruction
            if (strlen(dest) == 0 && strlen(jump) == 0) {
                fprintf(stderr, "Error: C-instruction at line %d must have a dest or a jump.\n", counter);
				fclose(new_f);
                exit(1);
            }

            // Translate symbolic fields to binary bits
            code_dest(dest, destBinary);
            code_comp(comp, compBinary);
            code_jump(jump, jumpBinary);

            fprintf(new_f, "111%s%s%s\n", compBinary, destBinary, jumpBinary);
        }
    }

    fclose(new_f);
    printf("\nClosing the output file.\n");
    return 0;
}