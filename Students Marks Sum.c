

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
    int total=0;
    int c=(gender=='b'?0:1);
    for(int i=c;i<number_of_students;i+=2)
        total+=marks[i];
    return total;
}

