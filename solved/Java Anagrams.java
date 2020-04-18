

    static boolean isAnagram(String a, String b) {
        a=a.toLowerCase();b=b.toLowerCase();
        int[] bool= new int[26];
        for(int i=0;i<26;i++)
            bool[i]=0;
        for(int i=0;i<a.length();i++)
            bool[a.charAt(i)-97]++;
        for(int i=0;i<b.length();i++)
            if(bool[b.charAt(i)-97]==0)
                return false;
            else
                bool[b.charAt(i)-97]--;
        for(int i:bool)
            if(i>0) return false;
        return true;
    }

