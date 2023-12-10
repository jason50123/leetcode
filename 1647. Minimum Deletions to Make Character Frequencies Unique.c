#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

// ﹚??誹?疼
struct letter_bucket {
    char letter;
    char *characters;
    UT_hash_handle hh;
};

// ﹍て
struct letter_bucket *buckets = NULL;

// ㄧ??才??表い
void add_character_to_bucket(char c) {
    // ?ダ????
    char lowercase = tolower(c);

    // 琩т??表
    struct letter_bucket *bucket;
    HASH_FIND_INT(buckets, &lowercase, bucket);

    // 狦表ぃ??穝表
    if (bucket == NULL) {
        bucket = (struct letter_bucket *)malloc(sizeof(struct letter_bucket));
        bucket->letter = lowercase;
        bucket->characters = NULL;
        HASH_ADD_INT(buckets, letter, bucket);
    }

    // ?才睰表い
    size_t len = strlen(bucket->characters);
    bucket->characters = (char *)realloc(bucket->characters, len + 2); // +2 ノ才㎝才
    bucket->characters[len] = c;
    bucket->characters[len + 1] = '\0';
}

// ゴ?表?甧
void print_buckets() {
    struct letter_bucket *bucket, *tmp;
    HASH_ITER(hh, buckets, bucket, tmp) {
        printf("Letter %c: %s\n", bucket->letter, bucket->characters);
    }
}

int main() {
    char input_string[] = "Hello World";

    for (int i = 0; i < strlen(input_string); i++) {
        if (isalpha(input_string[i])) {
            add_character_to_bucket(input_string[i]);
        }
    }

    print_buckets();

    // ??
    struct letter_bucket *bucket, *tmp;
    HASH_ITER(hh, buckets, bucket, tmp) {
        HASH_DEL(buckets, bucket);
        free(bucket->characters);
        free(bucket);
    }

    return 0;
}
