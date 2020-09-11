
    Difference(vector<int> v){
        elements=v;
    }
    void computeDifference(){
        vector<int> t=elements;
        sort(t.begin(),t.end());
        maximumDifference=t[t.size()-1]-t[0];
    }
