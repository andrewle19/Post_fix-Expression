//Postfix_expression
//Author: Andrew Le
//andrewle19@csu.fullerton.edu
//1/28/17

#include <iostream>
#include <string>
#include <stack>
#include "database.h"
#include "functions.h"
using namespace std;


int main() {
    
    
    
    stack<int> s; // intialize stack s
    database expressionvalues; // database to store expression values
    char postfix[1000]; // postfix expression
    char input; // user input
    bool keepgoing = false; // if the user wants to continue making postfix expression calculations
    
    do
    {
        bool quit = false; // quits loop when user enters $
        int i = 0; // increment counter for char postfix array
        int array_size = 0; // keeps track the size of the array
        
        cout << "Enter a postfix expression: ";
        while(quit == false) // loop to get user input
        {
            cin >> input; // gets user input
            if(input == '$') // checks for the stop
            {
                quit = true;
            }
            else
            {
                postfix[i] = input;
                i++; // increment i
                array_size++; // increments the array size
            }
        }
        
        
       
        int value; // user inputed value of alphabetical letter
        
        for(int j = 0; j < array_size ;j++)
        {
            
            // checks if the postfix index is a letter if it is then lets user assign it a valie
            if(isalpha(postfix[j]))
            {
                // checks if the postfix index is a duplicate if false then
                if(expressionvalues.check_for_duplicates(postfix[j]) == false)
                {
                    cout << "Enter the value of " << postfix[j] << ":";
                    cin >> value;
                    expressionvalues.Insert(postfix[j],value); // insert element and value into database
                    s.push(value); // pushs the value to the top of the stack
                }
               
                // if it is a duplicate
                else
                {
                    // push duplicate value to top of stack
                    s.push(expressionvalues.getDvalue(postfix[j]));
                }
               
                
            }
            
            if(isOpperand(postfix[j])) // check if postfix index is an opprand if so perform the opperation
            {
                int num1 = s.top(); // assigns num1 the top of the stack
                s.pop(); // pops out top
                
                int num2 = s.top(); // assignns num2 the new top of the stack
                s.pop(); // pops out top
                
                s.push(doMath(num1,num2,postfix[j])); // does the calculations then push on top of the stack
           
            }
        }
        
        cout << "Final Value=" << s.top() << '\n';
        s.pop();
        
        char choice; // user choice to continue or not
        cout << "Continue(y/n)?";
        cin >> choice;
        
        // check what the user wants to do
        if(choice == 'Y' || choice == 'y') // if yes clears the database then reloops
        {
            keepgoing = true;
            expressionvalues.clear();
        }
        
        else if(choice =='N' || choice == 'n')
        {
            keepgoing = false;
        }
        cout <<'\n';
        
    }while(keepgoing == true);
    
    return 0;
}

