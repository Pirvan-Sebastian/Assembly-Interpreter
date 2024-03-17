else if(commands[i] == "cmp")
    {
        if(commands[i+2]!=",") 
        {
            cout<<"ERROR: missing ',' as in mov ax, bx"<<endl;
            ERROR=true;
        }
        else
        {
            if(register[commands[i+1]]==register[commands[i+3]])
            {
                cout<<"Equal"<<endl;
            }
            else if(register[commands[i+1]]>register[commands[i+3]])
            {
                cout<<"Greater"<<endl;
            }
            else
            {
                cout<<"Less"<<endl;
            }
        }
    }
    else if(commands[i] == "jmp")
    {
        if(commands[i+1][0]=='$')
        {
            int nr=0;
            for(int j=1;j<commands[i+1].size();j++)
            {
                nr=nr*10+commands[i+1][j]-48;
            }
            i=nr-1;
        }
        else
        {
            cout<<"ERROR: missing '$' as in jmp $10"<<endl;
            ERROR=true;
        }
    }
    else if(commands[i] == "je")
    {
        if(commands[i+1][0]=='$')
        {
            int nr=0;
            for(int j=1;j<commands[i+1].size();j++)
            {
                nr=nr*10+commands[i+1][j]-48;
            }
            if(register[commands[i+3]]==register[commands[i+1]])
            {
                i=nr-1;
            }
        }
        else
        {
            cout<<"ERROR: missing '$' as in jmp $10"<<endl;
            ERROR=true;
        }
    }
    else if(commands[i] == "jne")
    {
        if(commands[i+1][0]=='$')
        {
            int nr=0;
            for(int j=1;j<commands[i+1].size();j++)
            {
                nr=nr*10+commands[i+1][j]-48;
            }
            if(register[commands[i+3]]!=register[commands[i+1]])
            {
                i=nr-1;
            }
        }
        else
        {
            cout<<"ERROR: missing '$' as in jmp $10"<<endl;
            ERROR=true;
        }
    }
    else if(commands[i] == "jg")