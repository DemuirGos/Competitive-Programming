#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    int hour;
    hour = stoi(s.substr(0,2));
     if(s[8]=='P' ||s[8]=='p')
     {
        if(hour == 12)
        {
            return s.substr(0,8);
        }
        hour+=12;
        string ss;
        ss=to_string(hour);
        ss+=s.substr(2,6);
     return ss;
     }
     else 
     {
         if(hour == 12)
         {
            string ss = "00";
            ss+=s.substr(2,6);
            return ss;
         }
         return s.substr(0,8);
     }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
