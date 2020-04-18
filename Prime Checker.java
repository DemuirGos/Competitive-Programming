
import static java.lang.System.in;
class Prime{
    boolean is_p(int n){
        if(n==1 || n==0 ||n%2==0) return n==2;
        for(int i=3;i<=Math.sqrt(n);i+=2){
            if(n%i==0) return false;
        }
        return true;
    }
    void checkPrime(int...numbers){
        for(int i:numbers){
            if(is_p(i)){
                System.out.print(i+" ");
            }
        }
        System.out.println();
    }
    
}
