

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = s.substring(0,k);
        String largest = "";
        for(int i=0;i+k<=s.length();i++){
            String temp=s.substring(i,k+i);
            if(temp.compareTo(smallest)<0) smallest=temp;
            if(temp.compareTo(largest)>0) largest=temp;
        }
        return smallest + "\n" + largest;
    }

