#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SymTable SymbolTable;
struct SymTable* ScopeStack[100];
int level=0;
int curlevel=0;
int error=0;


void OpenScope(){

    struct SymTable* newTable=calloc(1,sizeof(struct SymTable));
    newTable->status=1;
    
    level++;
    ScopeStack[level]=newTable;
    newTable->scope=level;
}
void CloseScope(){
   

    struct SymTable* temp=ScopeStack[level];
    temp->status=0;
}

struct SymTableEntry* findSymbol(char *s) {
    struct SymTable* temp;
    for(int j=level; j>=0; j--){
        if(ScopeStack[j]->status == 1){
            temp=ScopeStack[j];
            for(int i=0; i<temp->size; i++) {
                if(strcmp(s, temp->entries[i].name) == 0) {
                    return &temp->entries[i];
                }
            }
        } 
    }
    return 0;
}

struct SymTableEntry* addVariable(struct SymTableEntry entry,int line_no) {
    struct SymTableEntry* temp=findSymbol(entry.name);   
    if(temp != 0 && strcmp(entry.name,temp->name)==0 ) {
        if(temp->scope==entry.scope)
        {
            printf("line:%d Error: duplicate declaration of variable %s\n",line_no,entry.name);
            error=1;
            return;
        }
        
        
    }
    struct SymTable* Table=ScopeStack[entry.scope];
    //printf("1\n");
    int index = Table->size;
    //int index = entry.scope;
    //printf("index %d\n",index );
    entry.Seq=Table->size;
    //printf("2\n");
    for(int i=0;i<20;i++) entry.funtail[i]='\0';
    //printf("3\n");
    Table->size++;
    //printf("4\n");
    Table->entries[index]=entry;
    //printf("5\n");
    return &Table->entries[index];
}

struct nodeType* nthChild(int n, struct nodeType *node) {
    if(node->child == NULL) return NULL;
    struct nodeType *child = node->child;
    for(int i=1; i<n; i++) {
        child = child->rsibling;
       // printf("%d type:%d\n",i+1,child->nodeType );
    }
    return child;
}

void semanticCheck(struct nodeType *node) {
    //printf("semanticCheck\n");
    //printf("test:%d\n", node->nodeType);
    switch(node->nodeType) {
        case NODE_prog:{
            struct SymTableEntry entry;
            strcpy(entry.name,"writeln");
            entry.type=TypeNull;
            entry.dtype=Procedure;
            entry.scope=0;
            entry.Pptr=NULL;
            addVariable(entry,0);

            
            struct nodeType *child=nthChild(1,node);
            while(child->child != NULL){
                semanticCheck(child);
                child=nthChild(1,child);
            }

            child=nthChild(2,node);
            //printf("child: %d/n", child->nodeType);
            semanticCheck(child);
            child=nthChild(3,node);
            semanticCheck(child);
            return;
            
        }
        
        case NODE_declarations: {
            
            //printf("NODE DECLARATIONS\n");
            struct SymTableEntry entry;
            entry.par_flag=0;
            entry.Arraydim=0;
            struct nodeType *typeNode = nthChild(3, node);
            //printf("2\n");
            if(typeNode == NULL) break;
           
            enum StdType valueType;
            enum dataType dtype=Variable;

            if(typeNode->nodeType == NODE_TYPE_INT){
                valueType = TypeInt;
            }
            else if(typeNode->nodeType == NODE_TYPE_REAL){
                valueType = TypeReal;
            }
            else if(typeNode->nodeType == NODE_TYPE_STRING){
                valueType = TypeString;
            }
            else if(typeNode->nodeType == NODE_TYPE_CHAR){
                valueType = TypeChar;
            }
            else{
                dtype=Array;
                do{
                    int Arrayinit;
                    int Arrayend;
                    struct nodeType *type;
                    type=(struct nodeType*)malloc(sizeof(struct nodeType));
                    type=nthChild(1, typeNode);
                    Arrayinit=type->iValue;
                    type=nthChild(2, typeNode);
                    Arrayend=type->iValue;
                    //printf("------------%d %d\n", Arrayinit, Arrayend);
                    entry.Arraydim++;
                    type = nthChild(3, typeNode);

                    if(type->nodeType == NODE_TYPE_INT){
                        
                        entry.Arrayinit[entry.Arraydim-1]=Arrayinit;
                        entry.Arraysize[entry.Arraydim-1]=Arrayend;

                        valueType = TypeInt;
                    }
                    else if(type->nodeType == NODE_TYPE_REAL){
                        entry.Arrayinit[entry.Arraydim-1]=Arrayinit;
                        entry.Arraysize[entry.Arraydim-1]=Arrayend;

                        valueType = TypeReal;
                    }
                    else if(type->nodeType == NODE_TYPE_STRING){
                        entry.Arrayinit[entry.Arraydim-1]=Arrayinit;
                        entry.Arraysize[entry.Arraydim-1]=Arrayend;

                        valueType = TypeString;
                    }
                    else if(type->nodeType == NODE_TYPE_CHAR){
                        entry.Arrayinit[entry.Arraydim-1]=Arrayinit;
                        entry.Arraysize[entry.Arraydim-1]=Arrayend;

                        valueType = TypeChar;
                    }
                    else{
                        entry.Arrayinit[entry.Arraydim-1]=Arrayinit;
                        entry.Arraysize[entry.Arraydim-1]=Arrayend;

                        valueType = TypeArray;
                        typeNode=type;
                    }
                }while(valueType == TypeArray);

            }
            struct nodeType *idList = (struct nodeType*)malloc(sizeof(struct nodeType));
            idList = nthChild(2, node);
            struct nodeType *idNode = (struct nodeType*)malloc(sizeof(struct nodeType));
            idNode = idList->child;
            
            
            do {
                //entry.name=idNode->string;
                strcpy(entry.name,idNode->string);
                entry.dtype=dtype;
                entry.type=valueType;
                entry.scope=level;
                
                addVariable(entry,idNode->lineno);

                //printf("parent %d\n",idNode->parent->nodeType);
                idNode = idNode->rsibling;
                //printf("%s\n",idNode->string);
            } while(idNode != idList->child);

            return;
           
        }
        
        case NODE_subprogram_declaration:{
            OpenScope();
            //printf("subprogram decl\n");
            curlevel++;
            struct nodeType *child=(struct nodeType*)malloc(sizeof(struct nodeType));
            child = nthChild(1,node);
            semanticCheck(child);

            child = nthChild(2,node);
            while(child->child != NULL){
                semanticCheck(child);
                child=nthChild(1,child);
            }

            child=nthChild(3,node);
            semanticCheck(child);
            return;
        }
        case NODE_subprogram_head:{
            
            //printf("subprog head start\n");
            struct nodeType *idNode = (struct nodeType*)malloc(sizeof(struct nodeType));
            idNode = nthChild(1, node);
            enum StdType valueType;
            if(idNode->nodeType == NODE_FUNCTION){
                struct nodeType *typeNode = nthChild(3, node);
                //printf("FUNCTION RETURN TYPE===%d\n",typeNode->nodeType);
                if(typeNode->nodeType == NODE_TYPE_INT)
                    valueType = TypeInt;
                else if(typeNode->nodeType == NODE_TYPE_REAL)
                    valueType = TypeReal;
                else if(typeNode->nodeType == NODE_TYPE_STRING)
                    valueType = TypeString;
                else if(typeNode->nodeType == NODE_TYPE_CHAR)
                    valueType = TypeChar;
                else 
                    valueType = TypeArray;
            }
            else valueType= TypeNull;

           
            struct SymTableEntry entry;
            entry.Pptr=NULL;
            entry.par_flag=0;
            
           
            struct nodeType *argNode = (struct nodeType*)malloc(sizeof(struct nodeType));
            argNode = nthChild(2, node);
            int Par_set=0;
            if(argNode->nodeType == NODE_parameter_list){
                enum StdType valuetype;
                enum dataType dtype=Variable;
                int first=1;
                entry.Pptr=(struct Parameters*)calloc(1,sizeof(struct Parameters));
                struct Parameters* Curptr=(struct Parameters*)calloc(1,sizeof(struct Parameters));
                Curptr = entry.Pptr;
                do{
                    if(!first){
                        Curptr->next=(struct Parameters*)calloc(1,sizeof(struct Parameters));
                        Curptr=Curptr->next;
                    }
                    
                    
                    struct nodeType *typenode = (struct nodeType*)malloc(sizeof(struct nodeType));
                    typenode = nthChild(2, argNode);
                    if(typenode->nodeType == NODE_TYPE_INT){
                        valuetype = TypeInt;
                        
                    }
                    else if(typenode->nodeType == NODE_TYPE_REAL){
                        valuetype = TypeReal;
                        
                    }
                    else if(typenode->nodeType == NODE_TYPE_STRING){
                        valuetype = TypeString;
                       
                    }
                    else if(typenode->nodeType == NODE_TYPE_CHAR){
                        valuetype = TypeChar;
                    }
                    else{ 
                        //printf("test:%d\n",typenode->nodeType );
                        Curptr->Aptr=(struct Arrayinfo*)calloc(1,sizeof(struct Arrayinfo));
                        Curptr->Aptr->Arraydim=0;
                        dtype=Array;
                        do{
                            int Arrayinit;
                            int Arrayend;
                            struct nodeType *type = (struct nodeType*)malloc(sizeof(struct nodeType));;
                            type=nthChild(1, typenode);
                            Arrayinit=type->iValue;
                            type=nthChild(2, typenode);
                            Arrayend=type->iValue;
                            //printf("---------%d %d\n",Arrayinit,Arrayend);
                            Curptr->Aptr->Arraydim++;
                            type = nthChild(3, typenode);

                            if(type->nodeType == NODE_TYPE_INT){
                                Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1]=Arrayinit;
                                Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]=Arrayend;
                                
                                valuetype = TypeInt;
                            }
                            else if(type->nodeType == NODE_TYPE_REAL){
                                Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1]=Arrayinit;
                                Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]=Arrayend;
                                valuetype = TypeReal;
                            }
                            else if(type->nodeType == NODE_TYPE_STRING){
                                Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1]=Arrayinit;
                                Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]=Arrayend;
                                valuetype = TypeString;
                            }
                            else if(type->nodeType == NODE_TYPE_CHAR){
                                Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1]=Arrayinit;
                                Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]=Arrayend;
                                valuetype = TypeChar;
                            }
                            else{
                                Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1]=Arrayinit;
                                Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]=Arrayend;
                                valuetype = TypeArray;
                                typenode=type;
                            }
                        }while(valuetype == TypeArray);
                    }      
                    struct nodeType *idList = (struct nodeType*)malloc(sizeof(struct nodeType));
                    idList = nthChild(1, argNode);
                    struct nodeType *idnode = (struct nodeType*)malloc(sizeof(struct nodeType));
                    idnode = idList->child;
                    struct SymTableEntry argument;
                    int count=0;
                    char* name=(char*)malloc(sizeof(char)*100);
                    //name="";
                    do {
                        count++;
                        strcpy(argument.name,idnode->string);
                        strcat(name,argument.name);
                        if(idNode == idList->child)
                        {
                            strcat(name,",");
                        }
                        argument.dtype=dtype;
                        argument.type=valuetype;
                        argument.scope=level;
                        argument.par_flag=1;
                        argument.Pptr = (struct Parameters*)calloc(1,sizeof(struct Parameters));
                        argument.Pptr = Curptr;
                       
                        addVariable(argument,idnode->lineno);
                        idnode = idnode->rsibling;
                        
                    } while(idnode != idList->child);
                    
                    Curptr->type=valuetype;
                    Curptr->dtype=dtype;
                    Curptr->Parnum=count;
                    
                    //printf("%d %d",Curptr->Aptr->Arrayinit[Curptr->Aptr->Arraydim-1],Curptr->Aptr->Arraysize[Curptr->Aptr->Arraydim-1]);
                    Curptr->name = name;
                    
                    first=0;
                   
                    argNode=nthChild(3,argNode);
                    Par_set++;
                    //entry.Pptr = Curptr;
                }while(argNode->nodeType == NODE_parameter_list);
                

            }
            entry.Par_set=Par_set;
            strcpy(entry.name,idNode->string);
            strcpy(ScopeStack[level]->name,idNode->string);
            entry.type=valueType;
            entry.scope=level;
            entry.dtype=Variable;
            if(idNode->nodeType == NODE_FUNCTION) {
                entry.dtype=Function;
                entry.scope=0;
                addVariable(entry,idNode->lineno);
            }    
            else if(idNode->nodeType == NODE_PROCEDURE){
                entry.dtype=Procedure;
                entry.scope=0;
                addVariable(entry,idNode->lineno);
            }    
            return;
        }
        case NODE_END:{
            if(curlevel != 0) CloseScope();
            curlevel--;
            return;
        }
        case NODE_procedure_statement:{
            struct nodeType *idNode = (struct nodeType*)malloc(sizeof(struct nodeType));
            idNode=nthChild(1, node);
            struct SymTableEntry* entry=(struct SymTableEntry*)calloc(1,sizeof(struct SymTableEntry));
            entry=findSymbol(idNode->string);
            struct nodeType *argNode = (struct nodeType*)malloc(sizeof(struct nodeType));
            argNode=nthChild(2, node);
            if(!strcmp(idNode->string,"writeln")){
                semanticCheck(argNode);
                return;
            }
            struct Parameters* Curptr=(struct Parameters*)calloc(1,sizeof(struct Parameters));
            Curptr=entry->Pptr;

            if(entry->Pptr != NULL){
                if(argNode == NULL){
                    printf("line:%d Error:Function/Procedure:%s no arguments received\n",idNode->lineno,idNode->string);
                    error=1;
                    return;
                }
                int count=Curptr->Parnum;
                while(argNode != NULL && argNode != node->child) {
                    semanticCheck(argNode);
                    if(count == 0){
                        Curptr=Curptr->next;
                        if(Curptr == NULL){
                            printf("line:%d Error:Too many Arguments\n",idNode->lineno);
                            error=1;
                            return;
                        } 
                        count=Curptr->Parnum;
                    }
                    if(argNode->nodeType == NODE_ID){
                        if(Curptr->type != argNode->valueType){
                            printf("line:%d Error:Wrong argument \n",idNode->lineno);
                            error=1;
                            return;
                        }
                    }
                    else{
                        if(Curptr->type != argNode->valueType){
                            printf("line:%d Error:Wrong argument \n",idNode->lineno);
                            error=1;
                            return;
                        }
                    }

                    argNode=argNode->child;
                    count--;
                }   

            }
           
            return;
        }
        case NODE_parameter_list:{
            
            break;
        }
             
       
        case NODE_ID: {
            struct SymTableEntry *entry = (struct SymTableEntry*)calloc(1,sizeof(struct SymTableEntry));
            entry = findSymbol(node->string);
            if(entry == 0) {
                printf("line:%d Error: undeclared variable1 %s\n",node->lineno,node->string);
                return;
            }
            if(!strcmp(entry->name,ScopeStack[entry->scope]->name)){
                for(int i=0;i<ScopeStack[0]->size;i++){
                    if(!strcmp(ScopeStack[0]->entries[i].name,entry->name)){
                        
                        node->dtype = ScopeStack[0]->entries[i].dtype;
                        node->valueType = ScopeStack[0]->entries[i].type;
                        entry=&ScopeStack[0]->entries[i];
                        
                    }
                }
            }
           // printf("HERE3???\n");
            if(entry->dtype == Function){
              //  printf("HERE4???\n");
                struct nodeType *argNode = (struct nodeType*)malloc(sizeof(struct nodeType));
                argNode = nthChild(1, node);
                if(!strcmp(node->string,"writeln")){
                    semanticCheck(argNode);
                    return;
                }
                
                struct Parameters* Curptr = (struct Parameters*)calloc(1,sizeof(struct Parameters));
                Curptr = entry->Pptr;

                if(entry->Pptr != NULL){
                    if(argNode == NULL){
                        printf("line:%d Error:Function/Procedure:%s requires arguments\n",node->lineno,node->string);
                        error=1;
                        return;
                    }
                    int count=Curptr->Parnum;
                    //printf("COUNT: %d\n",count);
                    //struct SymTableEntry* temp;
                    //while(argNode != NULL ) {
                    for(int i=0;i<entry->Par_set;i++){
                        //printf("COUNT1: %d\n",count);
                        while(argNode != NULL){
                            //printf("COUNT2: %d\n",count);
                        //check whether argument exists
                        //printf("lineno:%d count:%d name:%s\n",node->lineno,count,node->string );
                        //printf("1argNode: %s \n", argNode->string);
                        //printf("argNode value: %d \n", argNode->valueType);
                        //printf("argNode nodetype: %d \n", argNode->nodeType);
                        semanticCheck(argNode);
                        //printf("here\n");
                        if(count == 0){
                            Curptr=Curptr->next;
                            if(Curptr == NULL){
                                printf("line:%d Error:Wrong argument number\n",node->lineno);
                                error=1;
                                //printf("what?\n");
                                return;
                                //exit(0);
                            } 
                            count=Curptr->Parnum;
                        }
                        //printf("here2\n");
                        if(argNode->nodeType == NODE_ID){//ID
                            if(Curptr->type != argNode->valueType){
                                printf("line:%d Error:Wrong argument \n",node->lineno);
                                error=1;
                                return;
                                //exit(0);
                            }
                        }
                        else{//expression
                            if(Curptr->type != argNode->valueType ){
                                printf("line:%d Error:Wrong argument \n",node->lineno);
                                error=1;
                                return;
                                //exit(0);
                            }
                        }
                        if(argNode->child!=NULL)
                        {
                             argNode=argNode->child;
                            //printf("argNode: %s \n", argNode->string);
                            //printf("argNode value: %d \n", argNode->valueType);
                            //printf("argNode nodetype: %d \n", argNode->nodeType);
                        }
                        if(argNode->nodeType==20){
                            argNode=argNode->child;
                        }
                        count--;
                        
                        } 
                    }   
                }
            }
            //printf("HERE5???\n");
            if(entry->dtype == Array){
                struct nodeType *argNode = nthChild(1, node);
                struct nodeType *tailNode = nthChild(2, argNode);
                argNode= nthChild(1,argNode);
                int count=0;
                while(tailNode != NULL){
                    semanticCheck(argNode);
                    if(count > entry->Arraydim-1){
                        printf("line:%d Error: Array dim out of bounds\n",node->lineno);
                        error=1;
                        return;
                    }
                    if(argNode->nodeType == NODE_NUM){
                        
                        if(!(argNode->iValue <= entry->Arraysize[count] && argNode->iValue >= entry->Arrayinit[count])){
                            printf("line:%d Error: Array index out of bounds\n",node->lineno);
                            error=1;
                            return;
                        }
                    }

                    argNode = nthChild(1, tailNode);
                    tailNode = nthChild(2,tailNode);
                    count++;
                }   
            }
            //printf("HERE6???\n");
            node->entry = entry;
            node->valueType = entry->type;
            node->dtype=entry->dtype;
            //printf("HERE7???\n");
            return;
        }    
        case NODE_SYM_REF: {
            struct SymTableEntry *entry = findSymbol(node->string);
            if(entry == 0) {
                printf("line:%d Error: undeclared variable2 %s\n",node->lineno, node->string);
                error=1;
                return;
            }
            if(entry->dtype == Procedure || entry->dtype == Function){
                printf("line:%d Error: LHS is a function or procedure!\n",node->lineno);
                error=1;
            }
            if(entry->dtype == Array){
                struct nodeType *argNode = nthChild(1, node);
                struct nodeType *tailNode = nthChild(2, argNode);
                
                argNode=nthChild(1,argNode);
                int count=0;
                while(tailNode != NULL){
                    semanticCheck(argNode);
                    if(count > entry->Arraydim-1){
                        //printf("count:%d\n",count );
                        printf("line:%d Error: Array(%s) dim out of bound\n",node->lineno,entry->name);
                        error=1;
                        return;
                    }
                    if(argNode->nodeType == NODE_NUM){
                        
                        if(!(argNode->iValue <= entry->Arraysize[count] && argNode->iValue >= entry->Arrayinit[count])){
                            printf("line:%d Error: Array index out of bound\n",node->lineno);
                            error=1;
                            return;
                        }
                    }
                    argNode = nthChild(1, tailNode);
                    tailNode= nthChild(2, tailNode);
                    count++;
                }   
            }
            
            node->entry = entry;
            node->valueType = entry->type;
            node->dtype=entry->dtype;

            return;
        }

        case NODE_NUM: {
            if(node->valueValid == VALUE_I_VALID) node->valueType = TypeInt;     
            else node->valueType = TypeReal;   
            //printf("before return\n");   
           //printf("num:%d\n",node->iValue );  
            //printf("before return\n");   
            return;
        }
        case NODE_String: {
            node->valueType = TypeString;        
            return;
        }
        case NODE_Char: {
            node->valueType = TypeChar;        
            return;
        }

        
        case NODE_OP:
        case NODE_ASSIGNMENT: {
            
            //printf("assignment\n");
            struct nodeType *child1 = nthChild(1, node);
            struct nodeType *child2 = nthChild(2, node);
            semanticCheck(child1);
            semanticCheck(child2);
            //printf("assignment2\n");
            //printf("child1's type:%d child2's type:%d\n",child1->valueType,child2->valueType );
            //printf("child1's nodetype:%d child2's nodetype:%d\n",child1->nodeType,child2->nodeType );
            if(child2->dtype == Procedure){
                printf("line:%d Error: Procedure has no return type!\n",node->lineno);
                error=1;
                return;
            }
            
               //printf("CHILD1 TYPE====%d\n",child1->nodeType);
               //printf("CHILD1 VALTYPE====%d\n",child1->valueType);
               //printf("CHILD2 TYPE====%d\n",child2->nodeType);
               //printf("CHILD2 VALTYPE====%d\n",child2->valueType);
               struct nodeType* child3 = nthChild(1,child2);
               if (child3!=NULL) 
               {
                   //printf("CHILD3 TYPE====%d\n",child3->nodeType);
               }
               //printf("assignment3\n");
            if(child1->valueType != child2->valueType) {
                if(child2->nodeType==25) 
                {
                    node->valueType = child1->valueType;
                    return;
                }
                if(node->nodeType == NODE_OP)
                    printf("line:%d Error: type mismatch for operator\n",node->lineno);
                else
                    printf("line:%d Error: type mismatch for assignment\n",node->lineno);
                //printf("1:%s 2:%s type:%d\n",child1->string,child2->string,child2->nodeType );
                error=1;
                return;
            }
           // printf("assignment4\n");
            node->valueType = child1->valueType;
            
            return;
        }
        default:{
    
        }
    }
    struct nodeType *child = node->child;
    if(child != 0) {
        do {
            semanticCheck(child);
            child = child->rsibling;
        } while(child != node->child);
    }
}

void printTable()
{
  struct SymTable* temp;
  temp =calloc(1,sizeof(struct SymTable));
  for(int j=0; j<=level; j++)
  {
    //printf("LEVEL==%d\n",j);
        //if(ScopeStack[j]->size > 0){
            if(j!=0)
            {
                printf("********************************\n"
                        "*       Open    Scope !       *\n"
                        "********************************\n");
            }
            temp=ScopeStack[j];
            //printf("scopestack %s \n", temp->name);
            //printf("size %d\n", temp->size);
            struct SymTableEntry tempEntry;
            for(int i=0; i<temp->size; i++) {
                tempEntry=temp->entries[i];
                if(strcmp(tempEntry.name,"writeln")!=0)
                {
                    printf("------------------------------------------------------------------------------\n");
                    printf("Name:%s\t\t|",tempEntry.name);
                    printf("Scope:%d |",tempEntry.scope);
                    printf("Type:");
                    if(tempEntry.dtype == 0)
                    {
                        switch (tempEntry.type)
                        {
                            case 0:
                                printf("real       |");
                                break;
                            case 1:
                                printf("integer    |");
                                break;
                            case 2:
                                printf("string     |");
                                break;
                            case 4:
                                printf("array     |");
                                break;
                            case 5:
                                printf("NULL      |");
                            break;
                        }
                    }
                    else
                    {
                        switch (tempEntry.dtype)
                        {
                            case 1:
                                printf("Function    |");
                                break;
                            case 2:
                                printf("Procedure   |");
                                break;
                            case 3:
                                printf("Array        |");
                                break;                  
                        }
                    }
                    printf("Return: ");
                    if(tempEntry.dtype==1)
                    {
                        switch (tempEntry.type)
                        {
                        case 0: printf("real");
                            break;
                        case 1: printf("int");
                            break;
                        case 2: printf("string");
                            break;    
                        }
                        
                    } else printf("   ");
                    printf(" |");   
                        printf("Parameter: (");
                    if(tempEntry.dtype==1 || tempEntry.dtype==2)
                    {
                        struct Parameters* tempP = tempEntry.Pptr;
                        for(int k=0;k<tempEntry.Par_set;k++)
                        {
                            //printf("1");
                            printf("%c",tempP->name[k]);
                            if(tempP->next!=NULL) printf(",");
                            //tempP = tempP->next;
                        }
                    }
                        printf(")\t\t|");
                        printf("Dim:");
                    if(tempEntry.dtype == 3)
                    {
                        struct Parameters* Curptr=tempEntry.Pptr;
                        if(tempEntry.par_flag)
                        {
                            printf("%d    ",Curptr->Aptr->Arraydim);
                        }
                        //else printf("%d",tempEntry.Arraydim);
                        //printf("%d    ",temp->entries[i].Pptr->Aptr->Arraydim);
                        //printf("%d    ",++tempEntry.Arraydim);
                    }  else printf("     ");
                        printf("|");
                        printf("Array Range: ");
                    if(tempEntry.dtype == 3)
                    {
                        printf("(");
                        struct Arrayinfo* tempPtr = tempEntry.Pptr->Aptr;
                        if(tempEntry.par_flag)
                        {
                          printf("%d,%d)",tempPtr->Arrayinit[tempPtr->Arraydim-1],tempPtr->Arraysize[tempPtr->Arraydim-1]); //? 5
                        } else printf("%d,%d)",tempEntry.Arrayinit[tempEntry.Arraydim-1],tempEntry.Arraysize[tempEntry.Arraydim-1]);
                    } 
                    printf("\n");
                }
             }
             if(j!=0)
            {
                printf("********************************\n"
                        "*       Close    Scope !       *\n"
                        "********************************\n");
            }
                
        }
        if(error!=1)
        {
            printf("********************************\n"
                   "*      No semantic error!      *\n"
                   "********************************\n");
        }
        
}
