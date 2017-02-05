//Postfix_expression
//Author: Andrew Le
//andrewle19@csu.fullerton.edu
//1/28/17

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// database that stores the expression and the value to avoid inputed duplicates
class database
{
private:
    char expression[50]; // each element of expression
    int value[50]; // value for each expression char associated to expression index
    int size;
public:
    
    // default contructor
    database()
    {
        size = 0;
    }
    
    
    
    // checks the database to see if expression element is already used
    // INPUT: postfix expression element
    bool check_for_duplicates(char express)
    {
        for(int i = 0; i < size; i++)
        {
            if(expression[i] == express) // checks to see if expression element is in database
            {
                return true;
            }
        }
        return false;
    }
    
    
    // Clears the database and resets database
    // makes all the expression = ' ' and values to 0 makes size to 0
    void clear()
    {
        for(int i = 0; i < size; i++)
        {
            expression[i] = ' ';
            value[i] = 0;
        }
        size = 0;
    }

    
    // gets the value for a duplicate expression element
    // INPUT: postfix expression element
    // OUTPUT: value for the duplicate of the expression element
    int getDvalue(char express)
    {
        for(int i = 0; i < size; i++)
        {
            if(expression[i] == express) // checks to see if expression element is in database
            {
                return value[i];
            }
        }
        return 0;
    }
    
    // Inserts into the class
    // INPUT: express- character in postfix expression, a_value-value associated to it
    // OUTPUT: NONE
    void Insert(char express,int a_value)
    {
        expression[size] = express;
        value[size] = a_value;
        size++;
    }
    

  
    
};

// performs the opperand on the top 2 numbers of the stack, used if isOpperand == true
// input: num1-top number in the stack, num2 - second number in stack, opperand - opperand to execute
// returns; int calculation of the two numbers depending on the opperands
int doMath(int num1,int num2,char opperand)
{
    if(opperand == '+')
    {
        return num2+num1;
    }
    else if(opperand == '-')
    {
        return num2-num1;
    }
    else if(opperand == '*')
    {
        return num2*num1;
    }
    else if(opperand == '/')
    {
        return num2/num1;
    }
    else // impossible if input were correct
    {
        return 0;
    }
}

// check if char is opperand
// input: char array index
// return: true/false
bool isOpperand(char c)
{
    // check if c is an opprand
    if(c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}



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
        }
    }
    
    
    // int size = (int)strlen(postfix); // size of the string
    int value; // user inputed value of alphabetical letter
    
    for(int j = 0; j < 1000 ;j++)
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
