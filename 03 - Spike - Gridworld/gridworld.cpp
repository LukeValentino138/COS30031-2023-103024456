#include <iostream>

std::string mapArray[5][5]=
{
  {"#","#","#","#","#"},
  {"#","D"," ", "G","#"},
  {"#"," "," "," ","#"},
  {"#"," ","S", " ","#"},
  {"#","#","#","#","#"}  
};


void outputMap()
{
for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << mapArray[i][j];
        }
        std::cout << std::endl; // Move to next line after row is done
    }
}


int main()
{
    outputMap();
 
   return 0;
}



