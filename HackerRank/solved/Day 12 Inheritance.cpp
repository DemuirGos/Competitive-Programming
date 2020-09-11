

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        Student(string fname,string lname,int id,vector<int> scores):Person(fname,lname,id)
        {
            this->testScores=scores;
        }
        char calculate()
        {
            float x=0;
            for(auto i:this->testScores)
                x+=i;
            x/=this->testScores.size();
            if(x>=90) return 'O';
            else if(x<90 && x>=80) return 'E';
            else if(x<80 && x>=70) return 'A';
            else if(x<70 && x>=55) return 'P';
            else if(x<55 && x>=40) return 'D';
            else return 'T';
        }
};

