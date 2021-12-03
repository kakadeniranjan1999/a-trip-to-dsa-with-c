#ifndef A_TRIP_TO_DSA_WITH_C_BASICARRAYOPS_H
#define A_TRIP_TO_DSA_WITH_C_BASICARRAYOPS_H

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
        printf("%d  ", array->array_ptr[i]);
    }
    printf("\n");
}

#endif //A_TRIP_TO_DSA_WITH_C_BASICARRAYOPS_H
