
int  sum (int count,...) {
    int m=0;int i;va_list args;
    va_start(args,count);
    for(i=0;i<count;i++)
    {
        m+=va_arg(args, int);
    }
    va_end(args);
    return m;
}

int min(int count,...) {
    int m=MAX_ELEMENT;int i;va_list args;
    va_start(args,count);
    for(i=0;i<count;i++)
    {
        int n=va_arg(args, int);
        if(m>n) m=n;
    }
    va_end(args);
    return m;
}

int max(int count,...) {
    int m=MIN_ELEMENT;int i;va_list args;
    va_start(args,count);
    for(i=0;i<count;i++)
    {
        int n=va_arg(args, int);
        if(m<n) m=n;
    }
    va_end(args);
    return m;
}

