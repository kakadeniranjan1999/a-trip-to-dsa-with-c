#ifndef A_TRIP_TO_DSA_WITH_C_ADVANCEDARRAYOPS_H
#define A_TRIP_TO_DSA_WITH_C_ADVANCEDARRAYOPS_H

struct SearchResult{
    int operation_status;
    int element_index;
};

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

struct SearchResult* linear_search_element(struct MyArray *array, int element){
    static struct SearchResult search_result = {-1, -1};
    for (int i = 0; i < array->used_size; i++) {
        if (array->array_ptr[i] == element){
            search_result = (struct SearchResult){.operation_status = 1, .element_index = i};
            return &search_result;
        }
    }
    return &search_result;
}

struct SearchResult* binary_search_element(struct MyArray *array, int element){
    int low = 0, mid, high = array->used_size - 1;
    static struct SearchResult search_result = {-1, -1};

    while(low <= high){
        mid = (high + low) / 2;
        if (array->array_ptr[mid] == element){
            search_result = (struct SearchResult){1, mid};
            return &search_result;
        }
        else if (element > array->array_ptr[mid]) {
            low = mid + 1;
        } else high = mid - 1;
    }
    return &search_result;
}

#endif //A_TRIP_TO_DSA_WITH_C_ADVANCEDARRAYOPS_H
