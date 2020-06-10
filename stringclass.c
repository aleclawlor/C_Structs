#include "stringclass.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct string{
    char *contents;
    int length;
};

String String_new(char *a){

    String newString;
    newString = malloc(sizeof(struct string));
    newString -> contents = a;
    newString -> length = strlen(a);

    return newString;
}

String String_copy(String s){

    String stringCopy;
    stringCopy = malloc(sizeof(struct string));
    stringCopy -> contents = s -> contents;
    stringCopy -> length = s -> length;

    return stringCopy;
}

int String_length(String s){
    return s -> length;
}

String String_concat(String s1, String s2){

    char * str1 = s1 -> contents;
    char * str2 = s2 -> contents;

    int s1Length = s1 -> length;
    int s2Length = s2 -> length;

    char * concatenated = (char *) malloc(s1Length + s2Length); 

    int i;
    i = 0;
    while(i < s1Length){
        *(concatenated + i) = str1[i];
        i ++;
    }

    i = 0;
    while(i < s2Length){
        *(concatenated + s1Length + i) = str2[i];
        i ++;
    }

    printf("Concatenated: %s\n", concatenated);


    String newString;
    newString = malloc(sizeof(struct string));
    newString -> contents = concatenated;
    newString -> length = s1Length + s2Length;

    return(newString);
}

int String_compare(String s1, String s2){

    char * str1 = s1 -> contents;
    char * str2 = s2 -> contents;

    int compare = strcmp(str1, str2);
    return compare;

}

char *String_tochararray(String s){

    int size = s -> length;
    char * contents = s -> contents;
    int i;

    printf("String contents in tochararray: %s\n", contents);

    return(contents);


}

void String_free(String s){
    free(s);
}