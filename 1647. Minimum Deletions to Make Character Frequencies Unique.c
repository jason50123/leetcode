#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

// �w?���ƪ�?�u?��
struct letter_bucket {
    char letter;
    char *characters;
    UT_hash_handle hh;
};

// ��l�ƫ��ƪ�
struct letter_bucket *buckets = NULL;

// ��?�G?�r�ũ�J??����
void add_character_to_bucket(char c) {
    // ?�r��???�p?
    char lowercase = tolower(c);

    // �d��??����
    struct letter_bucket *bucket;
    HASH_FIND_INT(buckets, &lowercase, bucket);

    // �p�G���s�b�A?�ؤ@?�s��
    if (bucket == NULL) {
        bucket = (struct letter_bucket *)malloc(sizeof(struct letter_bucket));
        bucket->letter = lowercase;
        bucket->characters = NULL;
        HASH_ADD_INT(buckets, letter, bucket);
    }

    // ?�r�ŲK�[���
    size_t len = strlen(bucket->characters);
    bucket->characters = (char *)realloc(bucket->characters, len + 2); // +2 �Τ_�r�ũM�Ŧr��
    bucket->characters[len] = c;
    bucket->characters[len + 1] = '\0';
}

// ���L�U?��?�e
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

    // ?��?�s
    struct letter_bucket *bucket, *tmp;
    HASH_ITER(hh, buckets, bucket, tmp) {
        HASH_DEL(buckets, bucket);
        free(bucket->characters);
        free(bucket);
    }

    return 0;
}
