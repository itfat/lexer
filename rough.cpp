#include<fstream>
#include<iostream>
#include<cctype>
#include <cstring>
#include<typeinfo>
#include<vector>

using namespace std;



int isKeyword(char buffer[]){
	const char *keywords[23] = {"break","case","char","const","continue","default", "switch",
							"do","double","else","float","for","if","int","long","return","short",
							"sizeof","struct","void","while","main", "print"};
	int i, flag = 0;
	
	for(i = 0; i < 23; ++i){
		if(strcmp(keywords[i], buffer) == 0)
        {
			flag = 1;
			break;
		}
	}
	
	return flag;
}
int isSymbolPunct(char word)
{
    int flag = 0;
    char symbols_punct[] = {'<','>','!','+','-','*','/','%','=',';','(',')','{', '}','.'};
    for(int x= 0; x< 15; ++x)
    {
   		if(word==symbols_punct[x])
           {
               flag = 1;
               break;
           }
   			
   	}
    return flag;
}
int doubleSymbol(char buffer[])
{
    int flag = 0;
    const char *double_symbol[12] = {"++","--","<=",">=","==","!=","+=","-=","*=","/=","%=","^="};
    for(int i=0; i<12;++i)
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
    std::vector<std::string> identifier;
    std::vector<std::string> number;
    char word;
    ifstream fin("program.txt");
    if(!fin.is_open())
    {
        cout<<"Error while opening the file"<<endl;
    }
    int i,k,j,l=0;
    while (!fin.eof())
    {
        word  = fin.get();
    
        if(isSymbolPunct(word)==1)
        {
            buffer2[k++] = word;
            // cout<<"buffer2: "<<buffer2<<endl;
        }
        else if((word == ' ' || word == '\n' || isdigit(word)|| isalpha(word)) && (k!= 0 ))
        {
            k = 0;
            if(doubleSymbol(buffer2)==1)
            {
                cout<<"<"<<buffer2<<", Double Symbol>"<<endl;
            }
            else
            {
                cout<<"<"<<buffer2<<", Symbol/Punctuation>"<<endl;
            }
            memset(&buffer2[0], '\0', sizeof(buffer2));
        }
       
        if(isalpha(word))
        {        
            buffer[j++] = word;
            // cout<<"buffer: "<<buffer<<endl;
   		}
   		else if((isSymbolPunct(word)==1 || word == ' ' || word == '\n' || isdigit(word)) && (j != 0))
        {
            j = 0;
            
                            
            if(isKeyword(buffer) == 1)
                cout<<"<"<<buffer<<", keyword>"<<endl;
            else
                {
                cout<<"<"<<buffer<<", identifier>"<<endl;
                identifier.push_back(buffer);
                }
            memset(&buffer[0], '\0', sizeof(buffer));
   					
   		} 
           
        else if(isdigit(word))
        {
            buffer1[l++] = word;
            // cout<<"buffer: "<<buffer1<<endl;
   		}
   		else if((isSymbolPunct(word)==1 || word == ' ' || word == '\n') && (l != 0))
        {  
        
            // buffer1[l] = '\0';
            l = 0;
            cout<<"<"<<buffer1<<", number>"<<endl;
            number.push_back(buffer1);  
        
            memset(&buffer1[0], '\0', sizeof(buffer1));              
        } 
        if(isalpha(word) && (l!=0))
        {
            cout<<"Error: "<<word<<" after "<<buffer1<<endl; 
            l=0;
            memset(&buffer1[0], '\0', sizeof(buffer1)); 
        }
        

    }
    cout<<"Identifier Table"<<endl;
    for (int i = 0; i < identifier.size(); i++)
		std::cout << i<<"\t\t"<<identifier[i] << endl;  

    cout<<"Number Table"<<endl;
    for (int i = 0; i < number.size(); i++)
		std::cout << i<<"\t\t"<<number[i] << endl;  

    
}