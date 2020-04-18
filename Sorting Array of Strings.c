
int lexicographic_sort(const char* a, const char* b) {
    for(int i=0;i<strlen(a) && i<strlen(b);i++)
    {
        if(a[i]!=b[i]) return a[i]<b[i];
    }
    return strlen(a)<strlen(b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return lexicographic_sort(b,a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int* p_a=calloc(28,sizeof(int));int* p_b=calloc(28,sizeof(int));
    for(int i=0;i<strlen(a);i++){
        p_a[a[i]-'a']++;
    }
    for(int i=0;i<strlen(b);i++){
        p_b[b[i]-'a']++;
    }
    int c_a=0,c_b=0;
    for(int i=0;i<28;i++){
        c_a+=(p_a[i]>0);c_b+=(p_b[i]>0);
    }
    return (c_a!=c_b)?c_a<c_b:lexicographic_sort(a,b);
}

int sort_by_length(const char* a, const char* b) {
    return (strlen(a)!=strlen(b))?strlen(a)<strlen(b):lexicographic_sort(a,b);
}
void string_sort(char** arr, const int len,int (*cmp_func)(const char* a, const char* b)) {
    int i, j, min;   
    for (i = 0; i < len-1; i++)  
    {  
        min = i;  
        for (j = i+1; j < len; j++)  
        if (cmp_func(arr[j],arr[min]))
            min = j;  
        char* t=arr[i];arr[i]=arr[min];arr[min]=t;
    }  
}
