#include<stdbool.h>

typedef char* NameType;
typedef int AttributeType;
typedef int SymbolTable;
typedef int Index;

SymbolTable InitializeTable(int TableSize);
bool IsIn(SymbolTable Table, NameType Name);
AttributeType Find(SymbolTable Table, NameType Name);
SymbolTable Modefy(SymbolTable Table, NameType Name, AttributeType Attr);
SymbolTable Insert(SymbolTable Table, NameType Name, AttributeType Attr);
SymbolTable Delete(SymbolTable Table, NameType Name);

Index Hash(const char *Key, int TableSize)
{
	unsigned int h = 0;
	while(*Key != '\0')
		h = (h<<5) + *Key++; //左移5位 == *32
	return h % TableSize;
}