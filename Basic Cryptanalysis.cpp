#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
//j,q,x

int main() {
    map<char,char> m;
    {
        m['l']='s';m['h']='k';m['s']='r';m['f']='a';m['y']='n';m['d']='b';
        m['z']='m';m['j']='o';m['o']='l';m['t']='i';m['p']='u';m['g']='c';
        m['r']='d';m['e']='e';m['v']='h';m['q']='g';m['m']='p';m['c']='t';
        m['a']='w';m['b']='z';m['w']='f';m['n']='v';m['x']='y';
                m['i']='j';m['k']='q';m['u']='x';m[' ']=' ';
    }
    char* inpt;
    inpt=(char*)malloc(170000*sizeof(char));
    scanf("%[^\n]",inpt);
    for(int i=0;i<170000;i++)
    {
        cout << m[inpt[i]];
    }
    return 0;
}
