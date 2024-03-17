//Interpretor de Assembly in C++
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int ax,bx,cx,dx; //registrii de 16 biti
int eax,ebx,ecx,edx; //registrii de 32 biti
int rax,rbx,rcx,rdx; //registrii de 64 biti
//registrii 
unordered_map<string,int> regster = {
    {"ax",ax},{"bx",bx},{"cx",cx},{"dx",dx},
    {"eax",eax},{"ebx",ebx},{"ecx",ecx},{"edx",edx},
    {"rax",rax},{"rbx",rbx},{"rcx",rcx},{"rdx",rdx}
};

//tipuri de date
/*
unordered_map<string,vector<int>> data_type = 
{
    {string("int"),vector<int>()},
    {string(".asciz"),vector<string>()}
};
*/
int main(int argc,char *argv[]) // ./assembler input_file output_file
{
    int file_output=0; //0=consola, 1=fisier
    //test
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";
    argv[1]=const_cast<char*>(inputFile);
    argv[2]=const_cast<char*>(outputFile);
    
    //Verificare folosire corecta
    
    switch(argc)
    {
        //Error code 1: No file specified
        case 1:
            cout<<"No file specified"<<endl;
            //return 1;
            break;

        //Daca am 2 argumente, atunci scriu in fisierul de output
        case 2:
            file_output=0;
            break;
        
        //Error code 2: Too many arguments   
        case 3:
            file_output=1;
             if(file_output==1)
              {
                  freopen(argv[2],"w",stdout); //trimite output ul catre fisier
              }
            break;

        //Error code 3: Too many arguments
        default:
            cout<<"Too many arguments"<<endl;
            return 4;
    }
    


   // ifstream fin(argv[1]);
   ifstream fin("inputt.txt");
    string line;

    while(getline(fin,line)) //fin>>line
    { //test
     cout<<line<<endl;
        vector<string> commands;
        //Algoritm separare in cuvinte
        for(int i=0;i<line.size();i++)
        {
            if(line[i]==' ') //daca e spatiu, atunci adauga comanda in vector
            {
                commands.push_back(line.substr(0,i));
                line=line.substr(i+1,line.size()-i-1);
                i=0;
            }
            else if(line[i]== ',') //daca e virgula, atunci adauga comanda si virgula in vector
            {
            commands.push_back(line.substr(0,i));       
            commands.push_back(",");
            line=line.substr(i+1,line.size()-i-1);
            i=1;//sare peste spatiul de dupa virgula (',')
            }
            else if(line[i]==':') //daca e :, atunci adauga comanda si : in vector
            {
            commands.push_back(line.substr(0,i));
            commands.push_back(":");
            line=line.substr(i+1,line.size()-i-1);
            i=1;//sare peste spatiul de dupa (':')
            }
            else if(line[i]==' ' && line[i+1]==' ')//daca sunt 2 spatii,  continui pana cand nu mai urm tot spatiu (mov eax   ebx)
               continue;
             
             
        }
    //adauga ultima comanda  
    if (!line.empty()) 
    {
    commands.push_back(line);
    }

//test
    for(int i=0;i<commands.size();i++)
    {
        cout<<commands[i]<<" ";
    }
    cout<<endl;
     for(int i=0;i<commands.size();i+=3)//in teorie nu imi trebuie for ul ca oricum mereu sunt 4 comenzi maxim in assembly
     {  bool ERROR=false,is_digit=false;
         vector<int> digits;

        if(commands[i] == "mov")
    {
        if(commands[i+2]!=",") 
        {
            cout<<"ERROR: missing ',' as in mov ax, bx"<<endl;
            ERROR=true;
        }
        else
            regster[commands[i+1]]=regster[commands[i+3]];
    }
    //comenzi aritmetice
    else if(commands[i] == "add")
    {
        if(commands[i+2]!=",") 
        {
            cout<<"ERROR: missing ',' as in mov ax, bx"<<endl;
            ERROR=true;
        }
        else
             //daca e numar in loc de registru
              {
              for(int j=0;j<commands[i+1].size();j++)
                if(isdigit(commands[i+1][j])) 
                {
                    digits.push_back(commands[i+1][j]-48);
                    is_digit=true;
                }
                else //daca sunt ambii registrii
                {
                  regster.at(commands[i+3])=regster.at(commands[i+1])+regster.at(commands[i+3]);
                }

                if(is_digit==true)
                {
                    int nr=0;
                    for(int j=digits.size()-1;j>=0;j--)
                    {
                        nr=nr*10+digits[j];
                    }
                    regster.at(commands[i+3])=regster.at(commands[i+3])+nr;
                }
              }
    }
    else if(commands[i] == "sub")
    {
        if(commands[i+2]!=",") 
        {
            cout<<"ERROR: missing ',' as in mov ax, bx"<<endl;
            ERROR=true;
        }
        else
        {
            //daca e numar in loc de registru
              for(int j=0;j<commands[i+1].size();j++)
                if(isdigit(commands[i+1][j])) 
                {
                    digits.push_back(commands[i+1][j]-48);
                    is_digit=true;
                }
                else //daca sunt ambii registrii
                {
                  regster.at(commands[i+3])=regster.at(commands[i+3])-regster.at(commands[i+1]);
                }
        }
                if(is_digit==true)
                {
                    int nr=0;
                    for(int j=digits.size()-1;j>=0;j--)
                    {
                        nr=nr*10+digits[j];
                    }
                    regster.at(commands[i+3])=regster.at(commands[i+3])-nr;
                }
    }
    else if(commands[i] == "mul")
    {
        if(commands[i+2]!=",") 
        {
            cout<<"ERROR: missing ',' as in mov ax, bx"<<endl;
            ERROR=true;
        }
        else
        {
            //daca e numar in loc de registru
              for(int j=0;j<commands[i+1].size();j++)
                if(isdigit(commands[i+1][j])) 
                {
                    digits.push_back(commands[i+1][j]-48);
                    is_digit=true;
                }
                else //daca sunt ambii registrii
                {
                  regster.at(commands[i+3])=regster.at(commands[i+3])*regster.at(commands[i+1]);
                }
        }
                if(is_digit==true)
                {
                    int nr=0;
                    for(int j=digits.size()-1;j>=0;j--)
                    {
                        nr=nr*10+digits[j];
                    }
                    regster.at(commands[i+3])=regster.at(commands[i+3])*nr;
                }
    }
    else if(commands[i] == "div")
    {
        if(commands[i+2]!=",") 
        {
            cout<<"ERROR: missing ',' as in mov ax, bx"<<endl;
            ERROR=true;
        }
        else
        {
            //daca e numar in loc de registru
              for(int j=0;j<commands[i+1].size();j++)
                if(isdigit(commands[i+1][j])) 
                {
                    digits.push_back(commands[i+1][j]-48);
                    is_digit=true;
                }
                else //daca sunt ambii registrii
                {
                  regster.at(commands[i+3])=regster.at(commands[i+3])/regster.at(commands[i+1]);
                }
        }
                if(is_digit==true)
                {
                    int nr=0;
                    for(int j=digits.size()-1;j>=0;j--)
                    {
                        nr=nr*10+digits[j];
                    }
                    regster.at(commands[i+3])=regster.at(commands[i+3])/nr;
                }
    }

        
    if(ERROR==true)
    {
         return 4;
    }
       commands.clear();
    
    }
 }
 //test
    cout<<"eax="<<eax<<" ebx="<<ebx<<" ecx="<<ecx<<" edx="<<edx<<endl;
    
    
    



    return 0;
}