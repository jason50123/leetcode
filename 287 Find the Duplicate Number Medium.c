#include<stdlib.h>


int findDuplicate(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
            if(nums[i] == nums[j]){
                return nums[i];
            }
        }
    }
}
