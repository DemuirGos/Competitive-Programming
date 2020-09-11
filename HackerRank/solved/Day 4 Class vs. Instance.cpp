

class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initAge){
        if(initAge>=0)
            age=initAge;
        else
        {
            age=0;cout << "Age is not valid, setting age to 0.\n";
        }

    }

    void Person::amIOld(){
        if(age>=18)
            cout << "You are old.\n";
        else if(age<13)
            cout << "You are young.\n";
        else
            cout << "You are a teenager.\n";
    }

    void Person::yearPasses(){
        age++;
    }

