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
    string postfix[1000]; // string array to hold postfix expression
    bool keepgoing = false; // if the user wants to continue making postfix expression calculations
    char input;
   
    do
    {
        bool quit = false; // quits loop when user enters $
        int i = 0; // increment counter for char postfix array
        int array_size = 0; // keeps track the size of the array
        cout << "Enter a postfix expression: ";
        
        while(quit == false) // loop to get user input
        {
            cin.get(input);
            if(input == '$') // checks for the stop
            {
                quit = true;
            }
            else
            {
                if(isspace(input)) // checks char element if it is white space delimiter
                {
                    i++; // increment i
                    array_size++; // increments the array size to keep track of array elements

                }
                // adds the input to postfix expression array
                else
                {
                    postfix[i] = postfix[i] + input; // catanate the string
                }
                
            }
        }
       
      
        
        int value; // user inputed value of alphabetical letter
        
        for(int j = 0; j < array_size ;j++)
        {
            // checks if the postfix index is a letter if it is then lets user assign it a valie
            if(isLetter(postfix[j]))
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
            
            // checks to see if string is digit
            else if (isNumber(postfix[j]))
            {
              // push the value of the string conver the string to a int with stoi
                s.push(stoi(postfix[j]));
                
            }
            
            else if(isOpperand(postfix[j])) // check if postfix index is an opprand if so perform the opperation
            {
                int num1 = s.top(); // assigns num1 the top of the stack
                s.pop(); // pops out top
                
                int num2 = s.top(); // assignns num2 the new top of the stack
                s.pop(); // pops out top
                
                s.push(doMath(num1,num2,postfix[j])); // does the calculations then push on top of the stack
            }
          
            
        }
        
        cout << "Final Value = " << s.top() << '\n';
        s.pop(); // pops the top of the stack
        
        
        char choice; // user choice to continue or not
        cout << "Continue(y/n)?";
        cin >> choice;
        
        // check what the user wants to do
        // if yes clears the database yand string arrathen reloops
        if(choice == 'Y' || choice == 'y')
        {
            keepgoing = true;
            expressionvalues.clear(); // clear data base
            clearStrings(postfix,array_size); // clear string arrays
            cin.ignore();
        }
        
        else if(choice =='N' || choice == 'n')
        {
            keepgoing = false;
        }
        cout <<'\n';
        
        
    }while(keepgoing == true);
    
    return 0;
}

