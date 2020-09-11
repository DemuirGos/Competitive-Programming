#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    stack<char> stuck;
    queue<char> tail;
    public:
    void enqueueCharacter(char ch){
        tail.push(ch);
    }
    void pushCharacter(char ch){
        stuck.push(ch);
    }
    char popCharacter(){
        char c=stuck.top();
        stuck.pop();
        return c;
    }
    char dequeueCharacter(){
        char c=tail.front();
        tail.pop();
        return c;
    }
};

