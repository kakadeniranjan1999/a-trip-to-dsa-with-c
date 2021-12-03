#ifndef A_TRIP_TO_DSA_WITH_C_ADVANCEDARRAYOPS_H
#define A_TRIP_TO_DSA_WITH_C_ADVANCEDARRAYOPS_H

int insert_element(struct MyArray *array, int index, int element){
    if (0 <= index && index < array->used_size && array->used_size < array->total_size) {
        for (int i = array->used_size - 1; i >= index; i--) {
            array->array_ptr[i + 1] = array->array_ptr[i];
        }
        array->array_ptr[index] = element;
        array->used_size++;
        return 1;
    } else return -1;
}

int append_element(struct MyArray *array, int element){
    if (array->used_size < array->total_size){
        array->array_ptr[array->used_size] = element;
        array->used_size++;
        return 1;
    } else return -1;
}

int delete_element(struct MyArray *array, int index){
    if (0 <= index && index < array->used_size) {
        for (int i = index; i < array->used_size; i++) {
            array->array_ptr[i] = array->array_ptr[i + 1];
        }
        array->used_size--;
        return 1;
    } else return -1;
}

int search_element(struct MyArray *array){

}

#endif //A_TRIP_TO_DSA_WITH_C_ADVANCEDARRAYOPS_H
