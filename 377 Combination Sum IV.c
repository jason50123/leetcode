int combinationSum4(int* nums, int numsSize, int target){
    int *arr = nums;
    int arrsize = sizeof(nums)/sizeof(int);
    int lastelement = arr[arrsize - 1];
    int x ;

    int *dp = (int*)malloc(target*sizeof(int));

    dp[0] = 1;
    for(int i = 1; i <= target; i++){
        for(int j = 0; j < arrsize; j++){
            x = *nums;
            nums++;
            if(i>x){
                dp[i] = dp[i]+dp[i-x];
            }
        }
    }
    x = dp[lastelement];
    return x;
}