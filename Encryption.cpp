#include <cmath>
#include<iostream>
#include <string>
#include<vector>
using namespace std;

int main()
{
    string s;int total=0;
    getline(cin,s);
    for (int i = 0; s[i]; i++) 
        if (s[i] != ' ') 
            s[total++] = s[i];
    s[total] = '\0';int row,col;
    if((int)sqrt(total)*((int)sqrt(total)+1)>=total) 
    {
        if((int)sqrt(total)*(int)sqrt(total)==total)
           row=col=sqrt(total);
        else
         {   row=sqrt(total);col=row+1;}
    }
    else 
    {
        row=col=sqrt(total)+1;
    }
    //cout << s << " " << total << " " << row << " " << col << endl;
    {
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<row;j++)
            {
                if((int)sqrt(total)*((int)sqrt(total)+1)>=total) 
                {
                    
                    if((int)sqrt(total)*(int)sqrt(total)==total)
                    {if(i+j*(row)>=total) break;cout << s[i+j*(row)];}
                    else
                    {if(i+j*(row+1)>=total) break;cout << s[i+j*(row+1)];}
                }
                else
                {
                    if(i+j*(row)>=total) break;
                    cout << s[i+j*(row)];
                    
                }
            }
            cout << " ";
        }
    }
}
