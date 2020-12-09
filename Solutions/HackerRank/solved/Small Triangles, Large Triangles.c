
double getvol(triangle t) {
  double p = (t.a + t.b + t.c) / 2.0;
  return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}
void swap(triangle* t1,triangle* t2){
    triangle temp= *t1;*t1=*t2;*t2=temp;
}
void sort_by_area(triangle* tr, int n) {
	for(int i=0;i<n-1;i++){
       int min_loc=i; 
       int j;
       for(j=i+1;j<n;j++){
           if(getvol(tr[min_loc])>=getvol(tr[j])) {
               min_loc=j;
           }
       }
       swap(tr+i,tr+min_loc);
    }
}

