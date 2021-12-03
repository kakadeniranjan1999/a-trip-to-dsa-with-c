#include "stdio.h"
#include "stdlib.h"
#include "headers/ArrayAbstract.h"
#include "headers/BasicArrayOps.h"
#include "headers/AdvancedArrayOps.h"

int get_user_input(char info[]){
    int input_value;

    printf("%s", info);
    scanf("%d", &input_value);
    return input_value;
}

void print_result(struct MyArray *array, char operation[], int operation_status){
    printf("%s Operation Status : %s\n", operation, operation_status == 1 ? "SUCCESS" : "FAIL");
    print_array(array);
    printf("Total Size of array : %d Used Size of array : %d\n\n", array->total_size, array->used_size);
}

int main(){

    int tSize, uSize;
    int operation_status;

    tSize = get_user_input("Please Enter total size of array: ");
    uSize = get_user_input("Please Enter used size of array: ");
    if (uSize > tSize){
        printf("Please enter integer value <= %d !!!", tSize);
        return 0;
    }

    struct MyArray marks;
    create_array(&marks, tSize, uSize);
    set_value(&marks);
    print_array(&marks);
    printf("Total Size of array : %d Used Size of array : %d\n\n", marks.total_size, marks.used_size);

    operation_status = insert_element(&marks, 5, 60);
    print_result(&marks, "Insertion", operation_status);

    operation_status = append_element(&marks, 50);
    print_result(&marks, "Append", operation_status);

    operation_status = delete_element(&marks, 0);
    print_result(&marks, "Deletion", operation_status);

    search_element(&marks);

    return 0;
}