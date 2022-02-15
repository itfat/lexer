#include<fstream>
#include<iostream>
#include <cstring>
#include<vector>

using namespace std;



bool isKeyword(char buffer[])
{
	const char *keywords[7] = {"else","float","for","if","int","while", "string"};
	int i, flag = 0;
	
	for(i = 0; i < 7; ++i){
		if(strcmp(keywords[i], buffer) == 0)
        {
			flag = 1;
			break;
		}
	}
	
	return flag;
}
bool isArop(char word)
{
    int flag = 0;
    char symbols_punct[] = {'+','-','*','/'};
    for(int x= 0; x< 4; ++x)
    {
   		if(word==symbols_punct[x])
           {
               flag = 1;
               break;
           }
   			
   	}
    return flag;
}
bool isRelop(char word)
{
    int flag = 0;
    char symbols_punct[] = {'<','>','!','='};
    for(int x= 0; x< 4; ++x)
    {
   		if(word==symbols_punct[x])
           {
               flag = 1;
               break;
           }
   			
   	}
    return flag;
}
bool isSymbolPunct(char word)
{
    int flag = 0;
    char symbols_punct[] = {';','(',')','{', '}','.','&','|'};
    for(int x= 0; x< 8; ++x)
    {
   		if(word==symbols_punct[x])
           {
               flag = 1;
               break;
           }
   			
   	}
    return flag;
}
bool doubleSymbol(char buffer[])
{
    int flag = 0;
    const char *double_symbol[3] = {"<=",">=","=="};
    for(int i=0; i<3;++i)
    {
        if(strcmp(double_symbol[i],buffer)==0)
        {
            flag =1;
            break;
        }
    }
    return flag;
}

int main()
{
    char buffer[15], buffer1[15], buffer2[15];
    memset(&buffer[0], '\0', sizeof(buffer));
    memset(&buffer1[0], '\0', sizeof(buffer1));
    memset(&buffer2[0], '\0', sizeof(buffer2));
    vector<std::string> identifier;
    vector<std::string> number;
    char word;
    ifstream fin("program.txt");
    if(!fin.is_open())
    {
        cout<<"Error while opening the file"<<endl;
    }
    int k,j,l=0;
    int count1 = 0;
    int count2=0;
    while (!fin.eof())
    {
        word  = fin.get();

        if(isArop(word)==1)
        {
            cout<<"< arop , "<<word<<" >"<<endl;
        }
        else if(isSymbolPunct(word)==1)
        {
            cout<<"< SMPN , "<<word<<" >"<<endl;
        }
    
        if(isRelop(word)==1)
        {
            buffer2[k++] = word;
        }
        else if((word == ' ' || word == '\n' || isdigit(word)|| isalpha(word) || isSymbolPunct(word)==1 || isArop(word)==1) && (k!= 0 ))
        {
            k = 0;
            if(doubleSymbol(buffer2)==1)
            {
                cout<<"< relop_double , "<<buffer2<<" >"<<endl;
            }
            else
            {
                cout<<"< relop , "<<buffer2<<" >"<<endl;
            }
            memset(&buffer2[0], '\0', sizeof(buffer2));
        }
       
        if(isalpha(word))
        {        
            buffer[j++] = word;
   		}
   		else if((isSymbolPunct(word)==1 || word == ' ' || word == '\n'|| isRelop(word)==1 || isArop(word)==1) && (j != 0))
        {
            j = 0; 
                            
            if(isKeyword(buffer) == 1)
                cout<<"<"<<buffer<<" , >"<<endl;
            else
                {
                cout<<"< id , "<<count2<< ">"<<endl;
                count2++;
                identifier.push_back(buffer);
                }
            memset(&buffer[0], '\0', sizeof(buffer));
   					
   		} 
        if(isdigit(word) && (j!=0))
        {
            buffer[j++] = word;
        }
           
        else if(isdigit(word))
        {
            buffer1[l++] = word;
            
   		}
   		else if((isSymbolPunct(word)==1 || word == ' ' || word == '\n' || isRelop(word)==1 || isArop(word)==1) && (l != 0))
        {  
        
            l = 0;
            cout<<"< num , "<<count1<<" >"<<endl;
            count1++;
            number.push_back(buffer1);  
        
            memset(&buffer1[0], '\0', sizeof(buffer1));              
        } 
        if(isalpha(word) && (l!=0))
        {
            cout<<"Lexical Error: "<<word<<" after "<<buffer1<<endl; 
            l=0;
            memset(&buffer1[0], '\0', sizeof(buffer1)); 
        }  

    }
    cout<<"Identifier Table"<<endl;
    for (int i = 0; i < identifier.size(); i++)
		cout << i<<"\t\t"<<identifier[i] << endl;  

    cout<<"Number Table"<<endl;
    for (int i = 0; i < number.size(); i++)
		cout << i<<"\t\t"<<number[i] << endl;  

    
}