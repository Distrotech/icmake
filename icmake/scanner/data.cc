#include "scanner.ih"

unordered_map<string, pair<int, int>> Scanner::s_token = 
{
    {"int",     {'i',                       Parser::VAR_TYPE}},
    {"list",    {'l',                       Parser::VAR_TYPE}},
    {"string",  {'s',                       Parser::VAR_TYPE}},

    {"exit",    {'e',                       Parser::LEAVE}},
    {"return",  {'r',                       Parser::LEAVE}},

    {"==",      {Token::EQUAL,              Parser::EQUALITY}},
    {"!=",      {Token::UNEQUAL,            Parser::EQUALITY}},

    {"<=",      {Token::SMALLER_EQUAL,      Parser::COMPARISON}},
    {">=",      {Token::GREATER_EQUAL,      Parser::COMPARISON}},
    {"<",       {'<',                       Parser::COMPARISON}},
    {">",       {'>',                       Parser::COMPARISON}},
    {"newer",   {Token::YOUNGER,            Parser::COMPARISON}},
    {"younger", {Token::YOUNGER,            Parser::COMPARISON}},
    {"older",   {Token::OLDER,              Parser::COMPARISON}},

    {">>",      {Token::SHR,                Parser::SHIFT}},
    {"<<",      {Token::SHL,                Parser::SHIFT}},

    {"+",       {'+',                       Parser::ADD}},
    {"-",       {'-',                       Parser::ADD}},

    {"%",       {'*',                       Parser::MUL}},
    {"/",       {'/',                       Parser::MUL}},
    {"%",       {'%',                       Parser::MUL}},

    {"++",      {'+',                       Parser::INC}}, 
    {"--",      {'-',                       Parser::DEC}}, 

    {"!",       {'!',                       Parser::UNOP}}, 
    {"~",       {Token::BNOT,               Parser::UNOP}}, 

    {"/=",      {'/',                       '='}},
    {"-=",      {'-',                       '='}},
    {"*=",      {'*',                       '='}},
    {"%=",      {'%',                       '='}},
    {"+=",      {'+',                       '='}},
    {"&=",      {'&',                       '='}},
    {"|=",      {'|',                       '='}},
    {"^=",      {'^',                       '='}},
    {"<<=",     {'<',                       '='}},
    {">>=",     {'>',                       '='}},
    {"=",       {'=',                       '='}},

    {"||",      {'|',                       Parser::OR}}, 
    {"&&",      {'&',                       Parser::AND}}, 

    {"OFF",         {0,                     Parser::NUMBER}},
    {"ON",          {0,                     Parser::NUMBER}},

    {"O_ALL",       {0,                     Parser::NUMBER}},
    {"O_DIR",       {0,                     Parser::NUMBER}},
    {"O_FILE",      {0,                     Parser::NUMBER}},
    {"O_SUBDIR",    {0,                     Parser::NUMBER}},

    {"P_CHECK",     {0,                     Parser::NUMBER}},
    {"P_NOCHECK",   {0,                     Parser::NUMBER}},

    {"S_IEXEC",     {0,                     Parser::NUMBER}},
    {"S_IFCHR",     {0,                     Parser::NUMBER}},
    {"S_IFDIR",     {0,                     Parser::NUMBER}},
    {"S_IFREG",     {0,                     Parser::NUMBER}},
    {"S_IREAD",     {0,                     Parser::NUMBER}},
    {"S_IWRITE",    {0,                     Parser::NUMBER}}
};

unordered_map<string, int> Scanner::s_identifiers = 
{
    {"getch",       Token::GETCH},
    {"getpid",      Token::GETPID},
    {"gets",        Token::GETS},
                                            
    {"arghead",     Token::ARG_HEAD},
    {"arghead",     Token::ARG_HEAD},
    {"argtail",     Token::ARG_TAIL},
    {"ascii",       Token::ASCII},
    {"cmdtail",     Token::CMDTAIL},
    {"cmdhead",     Token::CMDHEAD},
                                            
    {"echo",        Token::ECHO},
    {"exists",      Token::EXISTS},
    {"get_base",    Token::GET_BASE},
    {"getenv",      Token::GETENV},
    {"get_ext",     Token::GET_EXT},
    {"get_path",    Token::GET_PATH},
    {"putenv",      Token::PUTENV},
    {"sizeof",      Token::SIZEOF},
    {"strlen",      Token::STRLEN},
    {"strlwr",      Token::STRLWR},
    {"strupr",      Token::STRUPR},

    {"change_base", Token::CHANGE_BASE},
    {"change_ext",  Token::CHANGE_EXT},
    {"change_path", Token::CHANGE_PATH},
    {"element",     Token::ELEMENT},
    {"fgets",       Token::FGETS},
    {"strtok",      Token::STRTOK},

    {"substr",      Token::SUBSTR},

    {"chdir",       Token::CHDIR},
    {"stat",        Token::STAT},
    {"system",      Token::SYSTEM},

    {"fprintf",     Token::FPRINTF},

    {"exec",        Token::EXEC},
    {"execute",     Token::EXECUTE},

    {"makelist",    Token::MAKELIST},
    {"printf",      Token::PRINTF},
    {"strfind",     Token::STRFIND},
};
