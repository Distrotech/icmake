#ifndef INCLUDED_COMMANDS_
#define INCLUDED_COMMANDS_

class Options;

class Commands
{
    Options &d_opt;

    public:
        Commands();
        int process();
    private:
        void preProcess();
};
        
#endif
