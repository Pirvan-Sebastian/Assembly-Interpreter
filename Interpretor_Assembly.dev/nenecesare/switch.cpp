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