#include <iostream>
#include <sstream>
using namespace std;

class Student{
    private:
        int age;
        int standard;
        string fname;
        string lname;
    public:
        void set_age(int a){
            age=a;
        }
        void set_standard(int s){
            standard=s;
        } 
        void set_first_name(string fn){
            fname=fn;
        }
        void set_last_name(string ln){
            lname=ln;
        }
        int get_age(){
            return age;
        }
        int get_standard(){
            return standard;
        } 
        string get_first_name(){
            return fname;
        }
        string get_last_name(){
            return lname;
        }
        string to_string(){
            return std::to_string(age) + "," + fname + "," + lname + "," + std::to_string(standard);
        }

};
int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}

