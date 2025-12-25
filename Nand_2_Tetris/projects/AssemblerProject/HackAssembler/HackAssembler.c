//assembler_modified5.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

int main(int argc, char* argv[]) 
{
        ////////////////////////////////////////////////////////////
        //Initialization
        ////////////////////////////////////////////////////////////
        printf("\n\n\n");
        printf("Initialization\n");
        printf("=======================\n");

        //Opens the input file, and gets ready to process it
        const char* assemblyFilename;
        if (argc < 2) {
            fprintf(stderr, "Assembly filename is ../file.asm\n");
            assemblyFilename = "../file.asm";
        }
        else
            assemblyFilename = argv[1];
        if (!parser_init(assemblyFilename)) {
            fprintf(stderr, "Usage: assembler filename (default ../file.asm)\n");
            perror("fopen");
            exit(0);
        }



        // SymbolTable module
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
        symbolTable_addEntry("SCREEN0", 16384);
        symbolTable_addEntry("KBD", 24576);
        symbolTable_addEntry("SP", 0);
        symbolTable_addEntry("LCL", 1);
        symbolTable_addEntry("ARG", 2);
        symbolTable_addEntry("THIS", 3);
        symbolTable_addEntry("THAT", 4);


        printf("symbolTable_print().\n");
        symbolTable_print();
        printf("\nsymbolTable_getAddress(\"CC\") returns: %d.\n", symbolTable_getAddress("CC"));
        printf("symbolTable_getAddress(\"FF\") returns: %d.\n\n\n", symbolTable_getAddress("FF"));


         
        // Parser module
        printf("\nprinting all the lines till the end and then calling parser_rewind().\n");
        char line[LINE_MAX_SIZE];
        while (parser_parseNextLine(line)) {
            printf("%s", line);
        }
        parser_rewind();

        printf("\nReading and parsing the asembly file.\n");
        char symbol[LINE_MAX_SIZE];
        char addressStr[LINE_MAX_SIZE];
        char dest[LINE_MAX_SIZE];
        char comp[LINE_MAX_SIZE];
        char jump[LINE_MAX_SIZE];
        int lineCounter = 0;

        // First pass
        printf("First Pass:\n");
        while (parser_parseNextLine(line)) {
            if (parser_instructionType() == L_INSTRUCTION) {
                parser_symbol(symbol);
                symbolTable_addEntry(symbol, lineCounter + 1);
                printf("symbol= %-33s, label : %s", symbol ,line);
            }
            else if (parser_instructionType() != COMMENT_OR_EMPTY)
                lineCounter++;
        }

        printf("\nsymbolTable_print().\n");
        symbolTable_print();

        // Second pass
        printf("\nSecond Pass:\n");
        lineCounter = 0;
        while (parser_parseNextLine(line)) {
            if (parser_instructionType() == A_INSTRUCTION) {
                parser_address(addressStr);
                if (symbolTable_getAddress(addressStr) != -1)
                    symbolTable_addEntry(symbol, lineCounter);
                    
                printf("symbol or address= %-14s, A instruction : %s", addressStr, line);
            }
            else if (parser_instructionType() == C_INSTRUCTION) {
                parser_dest(dest);
                parser_comp(comp);
                parser_jump(jump);
                printf("dest= %-3s, comp= %-5s, jump= %-3s, C instruction : %s", dest, comp, jump, line);
            }
        }



        //example of using the Code module
        printf("\n\n\n");
        printf("example of using the Code module\n");
        printf("====================================\n");
        char destBinaryStr[20];
        char compBinaryStr[20];
        char jumpBinaryStr[20];
        char addressStr1[LINE_MAX_SIZE];
        strcpy(dest, "D");
        code_dest(dest, destBinaryStr);
        printf("strcpy(dest, \"D\");\ncode_dest(dest, destBinaryStr);\ndestBinaryStr <- \"%s\".\n\n", destBinaryStr);
        strcpy(comp, "D+1");
        code_comp(comp, compBinaryStr);
        printf("strcpy(comp, \"D+1\");\ncode_comp(comp, destBinaryStr);\ncompBinaryStr <- \"%s\".\n\n", compBinaryStr);
        strcpy(jump, "JMP");
        code_jump(jump, jumpBinaryStr);
        printf("strcpy(jump, \"JMP\");\ncode_jump(jump, jumpBinaryStr);\njumpBinaryStr <- \"%s\".\n\n", jumpBinaryStr);

        char binaryString[17];
        code_convertIntToBinString(135, binaryString);
        printf("code_convertIntToBinString(135, binaryString)\nbinaryString <- \"%s\".\n\n", binaryString);



        //example of writing to the machine language file 
        printf("\n\n\n");
        printf("example of writing to the machine language file\n");
        printf("====================================\n");

        printf("opening machine language file for writing.\n");
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

        printf("Writes the string to the output file.\n");
        char hackLine[] = "1110110000010000";
        fprintf(hackFP, "%s\n", hackLine);

        printf("Closing the output file.\n");
        fclose(hackFP);
}
