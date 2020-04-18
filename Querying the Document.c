
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text) {
    char**** d=(char****)malloc(sizeof(char***));
    d[0]=(char***)malloc(sizeof(char**));
    d[0][0]=(char**)malloc(sizeof(char*));
    d[0][0][0]=(char*)malloc(sizeof(char));
    int p=1,s=1,w=1,j=1;
    for(int i=0;i<strlen(text);i++){
        char a = text[i];
        if(text[i]=='\n'){
            w=s=j=1;
            d=(char****)realloc(d,++p*sizeof(char***));
            d[p-1]=(char***)malloc(sizeof(char**));
            d[p-1][s-1]=(char**)malloc(sizeof(char*));
            d[p-1][s-1][w-1]=(char*)malloc(sizeof(char));
        }
        else if(text[i]=='.'){
            d[p-1][s-1][w-1][j-1]='\0';
            w=j=1;s++;
            d[p-1]=(char***)realloc(d[p-1],s*sizeof(char**));
            d[p-1][s-1]=(char**)malloc(sizeof(char*));
            d[p-1][s-1][w-1]=(char*)malloc(sizeof(char));
            
        }
        else if(text[i]==' '){
            d[p-1][s-1][w-1][j-1]='\0';
            j=1;w++;
            d[p-1][s-1]=(char**)realloc(d[p-1][s-1],w*sizeof(char*));
            d[p-1][s-1][w-1]=(char*)malloc(sizeof(char));
            
        }
        else {
            d[p-1][s-1][w-1]=(char*)realloc(d[p-1][s-1][w-1],j*sizeof(char));
            d[p-1][s-1][w-1][j-1]=text[i];
            j++;
        }
    }
    return d;
}


