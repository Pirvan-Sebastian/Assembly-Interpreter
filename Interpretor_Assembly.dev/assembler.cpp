//Interpretor de Assembly in C++
#include <bits/stdc++.h>

using namespace std;

int ax,bx,cx,dx; //registrii de 16 biti
int eax,ebx,ecx,edx; //registrii de 32 biti
int rax,rbx,rcx,rdx; //registrii de 64 biti
//registrii 
unordered_map<string,int> register; 
{"ax",ax},{"bx",bx},{"cx",cx},{"dx",dx},
{"eax",eax},{"ebx",ebx},{"ecx",ecx},{"edx",edx},
{"rax",rax},{"rbx",rbx},{"rcx",rcx},{"rdx",rdx}; 

//tipuri de date
unordered_map<string,int> data_type;
{"int",vector<int> integer},{".asciz",vector<string> asciz};


int main(int argc,char *argv[]) // ./assembler input_file output_file
{
    int file_output=0; //0=consola, 1=fisier
    
    //Verificare folosire corecta
    switch(argc)
    {
        //Error code 1: No file specified
        case 1:
            cout<<"No file specified"<<endl;
            return 1;
            break;

        //Daca am 2 argumente, atunci scriu in fisierul de output
        case 2:
            file_output=1;
             if(file_output==1)
              {
                  freopen(argv[2],"w",stdout); //trimite output ul catre fisier
              }
            break;
        
        //Error code 2: Too many arguments   
        case 3:
            return 3;

        //Error code 3: Too many arguments
        default:
            cout<<"Too many arguments"<<endl;
            return 4;
    }


    ifstream fin(argv[1]);
    string line;

    while(getline(fin,line)) //fin>>line
    {
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
    commands.push_back(line); //adauga ultima comanda

    for(int i=0;i<commands.size();i+=3)//in teorie nu imi trebuie for ul ca oricum mereu sunt 4 comenzi maxim in assembly
    {  bool ERROR=false,is_digit=false;
         vector<int> digits;
       
        switch(commands[i])
        {  
            //comenzi basic
            case "mov":
              if(commands[i+2]!=",") 
              {
                cout<<"ERROR: missing ',' as in mov ax, bx"<<endl;
                 ERROR=true;
              }
              else
               register[commands[i+1]]=register[commands[i+3]];
                break;
            //comenzi aritmetice
            case "add":
            if(commands[i+2]!=",") 
              {
                cout<<"ERROR: missing ',' as in add ax, bx"<<endl;
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
                  register[commands[i+3]]=register[commands[i+1]]+register[commands[i+3]];
                }

                if(is_digit==true)
                {
                    int nr=0;
                    for(int j=digits.size()-1;j>=0;j--)
                    {
                        nr=nr*10+digits[j];
                    }
                    register[commands[i+3]]=register[commands[i+3]]+nr;
                }
              }
                break;

            case "sub":
            if(commands[i+2]!=",") 
              {
                cout<<"ERROR: missing ',' as in sub ax, bx"<<endl;
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
                  register[commands[i+3]]=register[commands[i+3]]-register[commands[i+1]];
                }

                if(is_digit==true)
                {
                    int nr=0;
                    for(int j=digits.size()-1;j>=0;j--)
                    {
                        nr=nr*10+digits[j];
                    }
                    register[commands[i+3]]=register[commands[i+3]]-nr;
                }
               }
                break;

            case "mul":
            if(commands[i+2]!=",") 
              {
                cout<<"ERROR: missing ',' as in mul ax, bx"<<endl;
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
                  register[commands[i+3]]=register[commands[i+3]]*register[commands[i+1]];
                }

                if(is_digit==true)
                {
                    int nr=0;
                    for(int j=digits.size()-1;j>=0;j--)
                    {
                        nr=nr*10+digits[j];
                    }
                    register[commands[i+3]]=register[commands[i+3]]*nr;
                }
               }
                break;

            case "div":
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
                  register[commands[i+3]]=register[commands[i+3]]/register[commands[i+1]];
                }

                if(is_digit==true)
                {
                    int nr=0;
                    for(int j=digits.size()-1;j>=0;j--)
                    {
                        nr=nr*10+digits[j];
                    }
                    register[commands[i+3]]=register[commands[i+3]]/nr;
                }
               }
                break;

            //comenzi if
            case "cmp":
                
                break;
            case "je":
                cout<<"je"<<endl;
                break;
            case "jg":
                cout<<"jg"<<endl;
                break;
            case "jge":
                cout<<"jge"<<endl;
                break;
            case "jl":
                cout<<"jl"<<endl;
                break;
            case "jle":
                cout<<"jle"<<endl;
                break;
            case "jne":
                cout<<"jne"<<endl;
                break;
            case "push":
                cout<<"push"<<endl;
                break;
            case "pop":
                cout<<"pop"<<endl;
                break;
            case "lea":
                cout<<"lea"<<endl;
                break;
            //comenzi for+jump
            case "jmp":
                cout<<"jmp"<<endl;
                break;
            case "loop":
                cout<<"loop"<<endl;
                break;
            //initializari 
            case "int":
                cout<<"int"<<endl;
                break;
            default:
                cout<<"ERROR: command not found"<<endl;
                ERROR=true;
                break;
    }
    if(ERROR==true)
    {
         return 4;
    }
       commands.clear();
    
    }
    



    return 0;
}