#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 10
#define NAME_SIZE 10

// With Linked List
typedef struct HashTable{
    char name[NAME_SIZE];
    int age;
    struct HashTable *next;
} HashTable;

void initHashTable(HashTable **hashTable){
    int index = 0;

    while(index < TABLE_SIZE){
        (*hashTable) = NULL;
        hashTable++;
        index++;
    }
}

unsigned int hash (char *data){
    int len = strlen(data);
    unsigned int hashValue = 0;

    for(int i = 0; i < len; i++){
        hashValue += data[i];
        hashValue = (hashValue * data[i]) % TABLE_SIZE;
    }

    printf("Hash Value = [%u]\n", hashValue);

    return hashValue;
}

bool insert(HashTable **hashTable, HashTable *data){
    if(data == NULL) return false;
    int index = hash(data->name);
    data->next = *(hashTable+index);
    *(hashTable+index) = data;
    return true;
}

HashTable *find(HashTable **hashTable, char *name){
    int index = hash(name);
    HashTable *temp = *(hashTable+index);

    printf("Finding...\n");
    if(temp != NULL && !strncmp((*(hashTable+index))->name, name, NAME_SIZE)){
        return temp;
    }
    return NULL;
}

void delete(HashTable **hashTable, char *name){
    int index = hash(name);
    HashTable *temp = *(hashTable+index);
    HashTable *prev = NULL;

    printf("Deleting...\n");
    if(temp != NULL && !strncmp((*(hashTable+index))->name, name, NAME_SIZE)){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL) return;

    if(prev == NULL){
        *(hashTable+index) = temp->next;
    }
    else prev->next = temp->next;
}

void print(HashTable **hashTable){
    printf("\n%s\t%s\n", "Index", "Data");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(*hashTable == NULL){
            printf("%i\t[NULL]\n", i);
        }
        else{
            HashTable *temp = *hashTable;

            printf("%i\t", i);
            while(temp != NULL){
                printf("[%s, %d] -> ", temp->name, temp->age);
                temp = temp->next;
            }
            printf("NULL\n");
        }
        hashTable++;
    }
    printf("\n");
}

int main()
{
    HashTable *hashTable[TABLE_SIZE];
    int result = true;

    initHashTable(hashTable); 

    HashTable data1 = {.name = "James", .age = 25};
    HashTable data2 = {.name = "Nadia", .age = 24};
    HashTable data3 = {.name = "Daniel", .age = 26};
    HashTable data4 = {.name = "James", .age = 31};

    result = insert(hashTable, &data1);
    if(result == true) printf("Insert Successful\n");
    else printf("Insert Failed\n");
    result = insert(hashTable, &data2);
    if(result == true) printf("Insert Successful\n");
    else printf("Insert Failed\n");
    result = insert(hashTable, &data3);
    if(result == true) printf("Insert Successful\n");
    else printf("Insert Failed\n");
    result = insert(hashTable, &data4);
    if(result == true) printf("Insert Successful\n");
    else printf("Insert Failed\n");
        
    print(hashTable); 

    HashTable *myData = find(hashTable, "James");
    if(myData == NULL) printf("Data not found\n");
    else{
        while(myData != NULL){
            printf("Name = [%s]\n", myData->name);
            printf("Age = [%d]\n", myData->age);
            myData = myData->next;
        }

    }

    //delete(hashTable, "James"); //delete first in
    //print(hashTable); 

    getchar();

    return 0;
}

// Without Linked List
/*typedef struct {
    char name[NAME_SIZE];
    int age;
} HashTable;

void initHashTable(HashTable **hashTable){
    int index = 0;

    while(index < TABLE_SIZE){
        (*hashTable) = NULL;
        hashTable++;
        index++;
    }
}

unsigned int hash (char *data){
    int len = strlen(data);
    unsigned int hashValue = 0;

    for(int i = 0; i < len; i++){
        hashValue += data[i];
        hashValue = (hashValue * data[i]) % TABLE_SIZE;
    }

    printf("Hash Value = [%u]\n", hashValue);

    return hashValue;
}

bool insert(HashTable **hashTable, HashTable *data){
    if(data == NULL) return false;
    int index = hash(data->name);
    if(*(hashTable+index) != NULL) return false;
    *(hashTable+index) = data;
    return true;
}

HashTable *find(HashTable **hashTable, char *name){
    int index = hash(name);

    printf("Finding...\n");
    if(*(hashTable+index) != NULL && !strncmp((*(hashTable+index))->name, name, TABLE_SIZE)){
        return *(hashTable+index);
    }
    else return NULL;
}

void delete(HashTable **hashTable, char *name){
    int index = hash(name);

    printf("Deleting...\n");
    if(*(hashTable+index) != NULL && !strncmp((*(hashTable+index))->name, name, TABLE_SIZE)){
        *(hashTable+index) = NULL;
    }
}

void print(HashTable **hashTable){
    printf("\n%s\t%s\n", "Index", "Data");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(*hashTable == NULL){
            printf("%i\t[NULL]\n", i);
        }
        else{
            printf("%i\t[%s, %d]\n", i, (*hashTable)->name, (*hashTable)->age);
        }
        hashTable++;
    }
    printf("\n");
}

int main()
{
    HashTable *hashTable[TABLE_SIZE];
    int result = true;

    initHashTable(hashTable); 

    HashTable data1 = {.name = "James", .age = 25};
    HashTable data2 = {.name = "Nadia", .age = 24};
    HashTable data3 = {.name = "Daniel", .age = 26};

    result = insert(hashTable, &data1);
    if(result == true) printf("Insert Successful\n");
    else printf("Insert Failed\n");
    result = insert(hashTable, &data2);
    if(result == true) printf("Insert Successful\n");
    else printf("Insert Failed\n");
    result = insert(hashTable, &data3);
    if(result == true) printf("Insert Successful\n");
    else printf("Insert Failed\n");
        
    print(hashTable); 

    HashTable *myData = find(hashTable, "James");
    if(myData == NULL) printf("Data not found\n");
    else{
        printf("Name = [%s]\n", myData->name);
        printf("Age = [%d]\n", myData->age);

    }

    //delete(hashTable, "James");
    //print(hashTable); 

    getchar();

    return 0;
}*/