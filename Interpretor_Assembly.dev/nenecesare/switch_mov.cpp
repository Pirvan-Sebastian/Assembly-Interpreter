case "ax":
                switch(commands[i+3])
                case "ax":
                  cout<<"Can not move same register"<<endl;
                    ERROR=true;
                    break;
                case "bx":
                    ax=bx;
                    break;
                case "cx":
                    ax=cx;
                    break;
                case "dx":
                    ax=dx;
                    break;
                case "eax":
                    ax=eax;
                    break;
                case "ebx":
                    ax=ebx;
                    break;
                case "ecx":
                    ax=ecx;
                    break;
                case "edx":
                    ax=edx;
                    break;
                case "rax":
                    ax=rax;
                    break;
                case "rbx":
                    ax=rbx;
                    break;
                case "rcx":
                    ax=rcx;
                    break;
                case "rdx":
                    ax=rdx;
                    break;
                default:
                    cout<<"ERROR: invalid register"<<endl;
                    ERROR=true;
                    break;
                
                 