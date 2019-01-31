#include "./stack.h"

int main(){
    int maxDepth=0,depth=0,i,len,line=0;
    Stack<char> s;
    string str;
    ofstream fd;
    fd = open("stack.h");
    while(getline(fd,str)!=EOF){
        if(str.length()>0)
            len++;
        len=str.length();
        for(i=0;i<len;i++){
            if(str[i]=='{' || str[i]=='[' || str[i]=='('){
                s.push(str[i]);
                depth++;
                if(depth>maxDepth)
                    maxDepth=depth;
            }
            if(str[i]=='}' || str[i]==']' || str[i]==')'){
                if(s.peek()=='{' && str[i]=='}'){
                    s.pop();
                    depth--;
                }
                else if(s.peek()=='[' && str[i]==']'){
                    s.pop();
                    depth--;
                }
                else if(s.peek()=='(' && str[i]==')'){
                    s.pop();
                    depth--;
                }
                else{
                    cout << "Bracket Missing in line number: " << line << endl;
                }
            }
        }
    }
    return 0;
}
