#ifndef __SYMTAB_H___
#define __SYMTAB_H___

enum StdType { TypeReal, TypeInt, TypeString, TypeChar, TypeArray, TypeNull};
enum dataType { Variable, Function, Procedure, Array};

struct SymTableEntry {
    char name[100];
    enum StdType type;
    enum dataType dtype;
    int scope;
    int Seq;
   	int Arraysize[10];
    int Arrayinit[10];
   	int Arraydim;
    struct Parameters* Pptr;
    int Par_set;
    char funtail[20];
    int par_flag;
   	int argnum;
};
struct Arrayinfo{
    int Arraysize[10];
    int Arrayinit[10];
    int Arraydim;
};
struct Parameters{
    enum StdType type;
    enum dataType dtype;
    int Parnum;
    struct Arrayinfo* Aptr;
    struct Parameters* next;
    char *name;
};
struct SymTable {
    int scope;
    int size;
    int status;
    char name[100];
    struct SymTableEntry entries[100];
};
union Array {
    int* intArray;
    float* realArray;
    char* stringArray;
};
extern struct SymTable SymbolTable;
extern struct SymTable* ScopeStack[100];
extern void CloseScope();
extern struct SymTableEntry* findSymbol(char *s);
extern struct nodeType* nthChild(int n, struct nodeType *node);

#include "node.h"
void semanticCheck(struct nodeType* node);
void OpenScope();
void CloseScope();
void printTable();

#endif
