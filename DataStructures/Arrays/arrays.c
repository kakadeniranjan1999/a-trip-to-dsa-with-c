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
    printf("\n\n%s Operation Status : %s\n", operation, operation_status == 1 ? "SUCCESS" : "FAIL");
    print_array(array);
    printf("Total Size of array : %d Used Size of array : %d", array->total_size, array->used_size);
}

int main(){

    int tSize, uSize;
    int operation_status;
    struct SearchResult* search_result;

    int insertion_element = 60, insertion_index = 5;
    int append_ele = 50;
    int deletion_index = 0;
    int search_element = 5;

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
    printf("Total Size of array : %d Used Size of array : %d", marks.total_size, marks.used_size);

    operation_status = insert_element(&marks, insertion_index, insertion_element);
    print_result(&marks, "Insertion", operation_status);

    operation_status = append_element(&marks, append_ele);
    print_result(&marks, "Append", operation_status);

    operation_status = delete_element(&marks, deletion_index);
    print_result(&marks, "Deletion", operation_status);

    search_result = linear_search_element(&marks, search_element);
    print_result(&marks, "Linear Search", search_result->operation_status);
    printf("\nElement %d is found at index : %d", search_element, search_result->element_index);

    search_result = binary_search_element(&marks, search_element);
    print_result(&marks, "Binary Search", search_result->operation_status);
    printf("\nElement %d is found at index : %d\n", search_element, search_result->element_index);


    return 0;
}