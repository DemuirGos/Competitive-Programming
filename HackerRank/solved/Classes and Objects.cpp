
class Student{
    private :
        int* scores=(int*)malloc(5*sizeof(int));;
        int total_score=0;
    public:
        void input(){
            for(int i=0;i<5;i++) {
                cin >> scores[i];total_score+=scores[i];
            }
        }
        int calculateTotalScore(){
            return total_score;
        }
};
