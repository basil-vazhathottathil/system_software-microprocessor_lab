#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void main() {
    FILE *src, *optab, *symtab, *int_file, *len;
    
    src = fopen("src.txt", "r");
    optab = fopen("optab.txt", "r");
    int_file = fopen("int_file.txt", "w");
    symtab = fopen("symtab.txt", "w+");  // Open for reading and writing
    len = fopen("len.txt", "w");
    
    if (!src || !optab || !int_file || !symtab || !len) {
        perror("Error opening file");
        return;
    }
    
    char label[20], symtab_data[20], operand[20], optab_data[20], opcode[20];
    int prog_len, start_add, locctr;
    bool symbol_found, opcode_found;
    
    if (fscanf(src, "%s%s%s", label, opcode, operand) == 3 && strcmp(opcode, "START") == 0) {
        start_add = atoi(operand);
        locctr = start_add;
        fprintf(int_file, "\t\t%s\t\t%s\t%s\n", label, opcode, operand);
    } else {
        locctr = 0;
    }
    
    while (fscanf(src, "%s%s%s", label, opcode, operand) == 3 && strcmp(opcode, "END") != 0) {
        if (strcmp(label, "**") != 0) {
            symbol_found = false;
            rewind(symtab);
            while (fscanf(symtab, "%s", symtab_data) == 1) {
                if (strcmp(symtab_data, label) == 0) {
                    printf("ERROR: label found in SYMTAB\n");
                    symbol_found = true;
                    break;
                }
            }
            if (!symbol_found) {
                fprintf(symtab, "%s\t%d\n", label, locctr);
            }
        }
        
        opcode_found = false;
        rewind(optab);
        while (fscanf(optab, "%s", optab_data) == 1) {
            if (strcmp(optab_data, opcode) == 0) {
                opcode_found = true;
                break;
            }
        }
        
        fprintf(int_file, "%d\t", locctr);
        if (opcode_found) {
            locctr += 3;
        } else if (strcmp(opcode, "WORD") == 0) {
            locctr += 3;
        } else if (strcmp(opcode, "RESW") == 0) {
            locctr += 3 * atoi(operand);
        } else if (strcmp(opcode, "RESB") == 0) {
            locctr += atoi(operand);
        } else if (strcmp(opcode, "BYTE") == 0) {
            locctr += strlen(operand) - 3; // Corrected this line
        } else {
            printf("ERROR: Invalid opcode %s\n", opcode);
        }
        fprintf(int_file, "%d\t%s\t\t%s\t\t%s\n", locctr, label, opcode, operand);
    }
    
    fprintf(int_file, "%d\t%s\t\t%s\t\t%s\n", locctr, label, opcode, operand);
    prog_len = locctr - start_add;
    printf("\nProgram length: %d\n\n", prog_len);
    fprintf(len, "%d", prog_len);
    
    fclose(src);
    fclose(optab);
    fclose(int_file);
    fclose(symtab);
    fclose(len);
}
