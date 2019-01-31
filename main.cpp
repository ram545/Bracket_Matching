#include "./stack.h"

int main(){
    int maxDepth=0,depth=0,i,len,line=0,pair=0;
    bool emptycheck;
    Stack<char> s;
    string str;
    fstream fd("test.txt",ios::in | ios::out);
    while(fd){
        getline(fd,str);
        line++;
        len=str.length();
        for(i=0;i<len;i++){
            if(str[i]=='{' || str[i]=='[' || str[i]=='('){
                s.push(str[i]);
                depth++;
                if(depth>maxDepth)
                    maxDepth=depth;
            }
            else if(str[i]=='}' || str[i]==']' || str[i]==')'){
                if(s.peek()=='{' && str[i]=='}'){
                    s.pop();
                    depth--;
                    pair++;
                }
                else if(s.peek()=='[' && str[i]==']'){
                    s.pop();
                    depth--;
                    pair++;
                }
                else if(s.peek()=='(' && str[i]==')'){
                    s.pop();
                    depth--;
                    pair++;
                }
                else{
                    cout << "Bracket Missing in line number " << line << " at index: " << i << str[i] << endl;
                }
            }
        }
    }
    cout << "Depth: " << maxDepth << "  " << "No of pairs: " << pair << endl;
    return 0;
}
