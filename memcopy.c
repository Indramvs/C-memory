#include "stdio.h"
#include "conio.h"

void* my_memcopy(void* to, void* from, int size){ //paramerts of type void pointers due to generalization
    char* dest = (char*)to;     //cast to char* for byte wise copying
    const char* src = (char*)from;
    for(int i=0;i<size;i++){
        dest[i]=src[i];
    }
    return dest;
}

int main(){
    int arr1[] = {1,2,3,4};
    int arr2[5] = {};
    my_memcopy(arr2, arr1, sizeof(arr1));
      for (int i = 0; i < sizeof(arr1) / sizeof(int); i++) {
        printf("%d ", arr2[i]);
    }
    char str1[] = {'a','b','c','d'};
    char str2[5] = {};
    printf("\n");
    my_memcopy(str2, str1, sizeof(str1));
      for (int i = 0; i < sizeof(str1) / sizeof(char); i++) {
        printf("%c ", str2[i]);
    }
    return -1;
}