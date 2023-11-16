#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int value;
} SymbolEntry
typedef struct {
    SymbolEntry entries[MAX_SYMBOLS];
    int count;
} SymbolTable;

void initSymbolTable(SymbolTable* table) {
    table->count = 0;
}

void insertSymbol(SymbolTable* table, const char* name, int value) {
    if (table->count < MAX_SYMBOLS) {
        strcpy(table->entries[table->count].name, name);
        table->entries[table->count].value = value;
        table->count++;
        printf("Inserted: %s = %d\n", name, value);
    } else {
        printf("Symbol table is full, cannot insert: %s = %d\n", name, value);
    }
}

int lookupSymbol(SymbolTable* table, const char* name) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->entries[i].name, name) == 0) {
            return table->entries[i].value;
        }
    }
    return -1; // Symbol not found
}

void updateSymbol(SymbolTable* table, const char* name, int value) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->entries[i].name, name) == 0) {
            table->entries[i].value = value;
            printf("Updated: %s = %d\n", name, value);
            return;
        }
    }
    printf("Symbol not found for update: %s\n", name);
}

void deleteSymbol(SymbolTable* table, const char* name) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->entries[i].name, name) == 0) {
            printf("Deleted: %s = %d\n", table->entries[i].name, table->entries[i].value);
            table->entries[i] = table->entries[table->count - 1];
            table->count--;
            return;
        }
    }
    printf("Symbol not found for delete: %s\n", name);
}
void printSymbolTable(SymbolTable* table) {
    printf("Symbol Table:\n");
    for (int i = 0; i < table->count; i++) {
        printf("%s = %d\n", table->entries[i].name, table->entries[i].value);
    }
}

int main() {
    SymbolTable symbolTable;
    initSymbolTable(&symbolTable);

    insertSymbol(&symbolTable, "x", 42);
    insertSymbol(&symbolTable, "y", 73);

    int value = lookupSymbol(&symbolTable, "x");
    if (value != -1) {
        printf("Lookup result: x = %d\n", value);
    } else {
        printf("Symbol not found during lookup\n");
    }

    updateSymbol(&symbolTable, "x", 99);
    deleteSymbol(&symbolTable, "y");

    printSymbolTable(&symbolTable);

    return 0;
}
