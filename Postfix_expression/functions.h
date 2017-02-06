//
//  functions used for Postfix expression
#ifndef FUNCTIONS_h
#define FUNCTIONS_h

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



#endif
