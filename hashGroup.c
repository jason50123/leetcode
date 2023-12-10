#include<stdio.h>
#include<stdlib.h>
#include "uthash/src/uthash.h"

struct bucket {
    int id;            /* we'll use this field as the key */
    int position;
    UT_hash_handle hh; /* makes this structure hashable */
};

struct bucket *users = NULL;

void add_user(struct bucket *s) {
    HASH_ADD_INT( users, id, s );
}

struct bucket *find_user(int user_id) {
    struct bucket *s;
    HASH_FIND_INT(users, &user_id, s);
    return s;
}

int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
    for(int i = 0; i < groupSizesSize; i++){
        
        adduser(*(groupSizes+i));
    }
    
    for(int i = 0; i < )
}

int main() {
    int groupSizes[] = { 1,1,5,1,5, 3,5,5, 3,5,3,1,3,3,3};
    int groupSizesSize = sizeof(groupSizes) / sizeof(groupSizes[0]);
    int returnSize;
    int* returnColumnSizes;
    int** result = groupThePeople(groupSizes, groupSizesSize, &returnSize, &returnColumnSizes);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("Group %d: ", i + 1);
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]); // Free memory for each group
    }

    free(result); // Free memory for the result array
    free(returnColumnSizes); // Free memory for returnColumnSizes

    return 0;
}

