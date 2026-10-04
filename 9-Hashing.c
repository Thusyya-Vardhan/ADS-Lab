#include <stdio.h>
#include <stdlib.h>

int table[10];

int hash(int key)
{
    return key % 10;
}

int probe(int prevHash, int i)
{
    return (prevHash + i) % 10;
}

void insert(int key)
{
    int hashvalue = hash(key);
    if (table[hashvalue] == __INT_MAX__)
    {
        table[hashvalue] = key;
    }
    else
    {
        int i = 1;
        int index = probe(hashvalue, i);
        while (index != hashvalue)
        {
            if (table[index] == __INT_MAX__)
            {
                table[index] = key;
                break;
            }

            i++;
            index = probe(hashvalue, i);
        }
        if (index == hashvalue)
        {
            printf("%d Cannot be inserted!!!");
        }
    }
}

int search(int key){
    int hashvalue = hash(key);
    if(table[hashvalue] == key){
        printf("Key Found\n");
        return hashvalue;
    }else{
        int i =1;
        int index = probe(hashvalue, i);
        while(index != hashvalue){
            if(table[index] == key){
                printf("Key Found\n");
                return index;
            }
            i++;
            index = probe(hashvalue,i);
        }
        if(index == hashvalue){
            printf("Key Not Found\n");
            return -1;
        }
    }
}

void delete(int key){
    int index = search(key);
    if(index != -1){
        table[index] = __INT_MAX__;
    }
}

void update(int oldKey, int newKey)
{
    int index = search(oldKey);

    if(index != -1)
    {
        table[index] = newKey;
    }else{
        printf("Value to be updated not found");
    }
}

void display(){
    for(int i =0 ;i < 10; i++){
        if(table[i] != __INT_MAX__){
            printf("%d ", table[i]);
        }else{
            printf("EMPTY ");
        }
    }
    printf("\n");
}

int main(){

    for(int i=0; i<10;i ++){
        table[i] = __INT_MAX__;
    }

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    printf("After Insertion: ");
    display();
    search(40);
    delete(50);
    delete(30);
    printf("After Deletion: ");
    display();
    update(10,5);
    printf("After Updation:");
    display();


    return 0;
}