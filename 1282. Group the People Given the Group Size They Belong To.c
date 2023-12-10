#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
    int** array;
    int counter = 1;
    int arrayfullCounter = 0;
    int arrayindex = 0;
    bool flag = false;
    *returnSize = 0;
    array = (int**)malloc(sizeof(int*)*groupSizesSize);    
    *returnColumnSizes = (int*)malloc(sizeof(int)*groupSizesSize);
    
    for(int i = 0; i < groupSizesSize; i++){ 
        array[i] = (int*)malloc(groupSizesSize * sizeof(int));
    }

    arrayindex = 0;
    
    for(int i = 0; i < groupSizesSize; i++){ 
        flag = false;
        for(int j = 0; j < groupSizesSize; j++){
            
            if(groupSizes[j] == counter && arrayfullCounter < counter){
                array[arrayindex][arrayfullCounter] = j;
                arrayfullCounter ++;
                flag = true;
            }else if(groupSizes[j] == counter && arrayfullCounter == counter){
                (*returnColumnSizes)[arrayindex] = counter;
                arrayindex++;
                arrayfullCounter = 0;
                array[arrayindex][arrayfullCounter] = j;
                arrayfullCounter ++;
            }
        }
        if(flag != false){
        (*returnColumnSizes)[arrayindex] = arrayfullCounter;
        arrayfullCounter = 0;
        arrayindex++;
        counter++;
        }else{
            counter++;
        }

        
    }
    
    *returnSize = arrayindex ;
    return array;
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