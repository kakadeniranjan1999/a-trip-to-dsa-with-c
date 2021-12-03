#include <stdio.h>
#include "stdlib.h"

struct MyArray{
    int total_size;
    int used_size;
    int *array_ptr;
};

void create_array(struct MyArray *myArray, int tSize, int uSize){
    (*myArray).total_size = tSize;
    myArray->used_size = uSize;
    myArray->array_ptr = (int *) malloc(tSize * sizeof(int));
}

void set_value(struct MyArray *array){
    for(int i=0; i < array->used_size; i++){
        printf("Enter Element No. %d : ", i);
        scanf("%d", &array->array_ptr[i]);
    }
}

void print_array(struct MyArray *array){
    for(int i=0; i < array->used_size; i++){
        printf("%d\n", array->array_ptr[i]);
    }
}

int get_user_input(char info[]){
    int input_value;

    printf("%s", info);
    scanf("%d", &input_value);
    return input_value;
}

int main(){

    int tSize, uSize;

    tSize = get_user_input("Please Enter total size of array: ");
    uSize = get_user_input("Please Enter used size of array: ");

    struct MyArray marks;
    create_array(&marks, tSize, uSize);
    set_value(&marks);
    print_array(&marks);

    return 0;
}