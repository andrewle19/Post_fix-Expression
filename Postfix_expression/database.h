//
//  database class
// database that stores the expression and the value to avoid inputed duplicates
#ifndef DATABASE_h
#define DATABASE_h


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


#endif /* database_h */
