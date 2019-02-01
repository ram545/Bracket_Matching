/**********************************************************************
* FILENAME:        main.cpp
*
* DESCRIPTION/PURPOSE:
* Write a program to parse the input source file (.c or .cpp).
* In this file, there would be brackets.  Brackets could be [] or () or {}. Brackets could be nested.
*
* 1. Detect if there are any missing matching brackets.
* 2. If bracket is missing, indicate the line number.
* 3. Find out the total number of pairs
* 4. Find out the maximum depth.
*
*
* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/01/2019
* SUBMISSION DATE: 02/01/2019
*
* Design:
* 1. Input file is read line by line.
* 2. If char is (,{ or [ push into stack.
* 3. If char is ),} or ] and their corresponding value is on top of stack pop stack or else return error.
* 4. If stack is empty at the end print success else return error.
* 5. for depth, the number of elements in stack is calculated for every iteration and max is returned.
*
**********************************************************************/
#include "./stack.h"

int main(){
    int maxDepth=0,depth=0,i,len,line=0,pair=0;
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
                if(s.isEmpty()){
                    cout << "Bracket " << str[i]  << " Missing in line number " << line << " at index: " << i << endl;
                    return 0;
                }
                else{
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
                        cout << "Bracket " << str[i]  << " Missing in line number " << line << " at index: " << i << endl;
                        return 0;
                    }
                }
            }
        }
    }
    if(s.isEmpty()){
        cout << "No Missing Brackets" << endl;
        cout << "Depth: " << maxDepth << "  " << "No of pairs: " << pair << endl;
    }
    else
        cout << "Bracket " << s.peek()  << " Missing in line number " << line << " at index: " << i << str[i] << endl;
    return 0;
}
