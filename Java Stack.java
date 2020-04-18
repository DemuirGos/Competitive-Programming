import java.util.*;
class Solution{
	public static void main(String []argh)
	{
		Scanner sc = new Scanner(System.in);
		
		while (sc.hasNext()) {
			String input=sc.next();
            char[] c={'{','(','[','}',')',']'};
            int[] v={0,0,0};boolean b=true;
            for(int i=0;i<input.length() && b;i++)
            {
                for(int j=0;j<3;j++)
                    if(input.charAt(i)==c[j])
                        v[j%3]++;
                for(int j=3;j<6;j++)
                    if(input.charAt(i)==c[j]){
                            if(v[j%3]==0){
                                b=false;
                            }
                            v[j%3]--;
                        }
            } 
            for(int i=0;i<3 && b;i++)
                if(v[i]!=0)
                {
                    b=false;
                }
            if(b) System.out.println("true");
            else System.out.println("false");
		}
		
	}
}



