
struct document get_document(char* text) {
    struct document d;
    int p_count=1,s_count=1,w_count=1;
    int prev=0;
    for(int i=0;i<strlen(text);i++){
        d.data=realloc(d.data,p_count*sizeof(struct paragraph));
        d.data[p_count].data=realloc(d.data[p_count].data,s_count*sizeof(struct sentence));
        d.data[p_count].data[s_count].data=realloc(d.data[p_count].data[s_count].data,w_count*sizeof(struct word));
        if(text[i]=='\n'){
            d.data[p_count].sentence_count=s_count;
            p_count++;w_count=s_count=1;i++;
        }
        if(text[i]=='.'){
            d.data[p_count].data[s_count].word_count=w_count;
            s_count++;w_count=1;i++;
        }
        if(text[i]==' '){
            d.data[p_count].data[s_count].data[w_count].data=malloc((i-prev+1)*sizeof(char));
            for(int j=prev;j<i;j++) d.data[p_count].data[s_count].data[w_count].data[j-prev]=text[j];
            w_count++;i++;
        }
        s_count+=text[i]=='.';w_count+=text[i]==' ';p_count+=text[i]=='\n';
    }
    return d;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}

