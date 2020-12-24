
function fact(a) {
    if (a == 0) {
        return 1;
    }
    return a * fact(a - 1);
}
function factorial(a){
    return fact(a);
}
