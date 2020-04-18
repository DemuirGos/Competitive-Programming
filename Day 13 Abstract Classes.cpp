
class MyBook : public Book{
    protected:
        int price;
    public:
        MyBook(string t,string a,int p):Book(t,a)
        {
            this->price=p;
        }
        void display()
        {
            cout << "Title: " << this->title << endl;
            cout << "Author: " << this->author << endl;
            cout << "Price: " << this->price;
        }

};
