//
//  functions used for Postfix expression
#ifndef FUNCTIONS_h
#define FUNCTIONS_h

// performs the opperand on the top 2 numbers of the stack, used if isOpperand == true
// input: num1-top number in the stack, num2 - second number in stack, opperand - opperand to execute
// returns; int calculation of the two numbers depending on the opperands
int doMath(int num1,int num2,string opperand)
{
    if(opperand == "+")
    {
        return num2+num1;
    }
    else if(opperand == "-")
    {
        return num2-num1;
    }
    else if(opperand == "*")
    {
        return num2*num1;
    }
    else if(opperand == "/")
    {
        return num2/num1;
    }
    else // impossible if input were correct
    {
        return 0;
    }
}

// checks if the string is a composed of letters
// input: string express- postfix epression element
// returns: True/False

bool isLetter(string express)
{
    bool isletter = true;
    
    for(int i = 0; i < express.length(); i++)
    {
        if(isalpha(express[i]) == false)
        {
            isletter = false;
        }
    }
    return isletter;
}
// checks if the string is a composed of numbers
// input: string express- postfix epression element
// returns: True/False

bool isNumber(string express)
{
    bool isNum = true;
    
    for(int i = 0; i < express.length(); i++)
    {
        if(isdigit(express[i]) == false)
        {
            isNum = false;
        }
    }
    return isNum;
}

// check if string is opperand
// input: string array index
// return: true/false
bool isOpperand(string c)
{
    // check if c is an opprand
    if(c == "+" || c == "-" || c == "*" || c == "/")
    {
        return true;
    }
    else
    {
        return false;
    }
}




#endif
