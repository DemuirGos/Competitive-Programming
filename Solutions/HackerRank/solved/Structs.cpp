#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student{
    int age;
    string first_name;
    string last_name;
    int standard;
};
void print(Student s)
{
    cout << s.age << " " << s.first_name << " " << s.last_name << " " << s.standard;
}
int main() {
    Student st;
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    print(st);
    return 0;
}

