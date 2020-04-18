
class BadLengthException{
    public:
    int n;
    BadLengthException(int m){
        n=m;
    }
    int what(){
        return n;
    }
};
