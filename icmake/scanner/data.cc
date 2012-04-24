#include "scanner.ih"

std::unordered_map<> Scanner::s_identifiers = 
{
    {"getch",       {&Scanner::zeroArgFunction, RSS::GETCH}},
    {"getpid",      {&Scanner::zeroArgFunction, RSS::GETPID}},
    {"gets",        {&Scanner::zeroArgFunction, RSS::GETS}},

    {"arghead",     {&Scanner::oneArgFunction,  RSS::ARG_HEAD}},
    {"arghead",     {&Scanner::oneArgFunction,  RSS::ARG_HEAD}},
    {"argtail",     {&Scanner::oneArgFunction,  RSS::ARG_TAIL}},
    {"ascii",       {&Scanner::oneArgFunction,  RSS::ASCII}},
    {"cmdtail",     {&Scanner::oneArgFunction,  RSS::CMDTAIL}},
    {"cmdhead",     {&Scanner::oneArgFunction,  RSS::CMDHEAD}},
    {"echo",        {&Scanner::oneArgFunction,  RSS::ECHO}},
    {"exists",      {&Scanner::oneArgFunction,  RSS::EXISTS}},
    {"get_base",    {&Scanner::oneArgFunction,  RSS::GET_BASE}},
    {"getenv",      {&Scanner::oneArgFunction,  RSS::GETENV}},
    {"get_ext",     {&Scanner::oneArgFunction,  RSS::GET_EXT}},
    {"get_path",    {&Scanner::oneArgFunction,  RSS::GET_PATH}},
    {"putenv",      {&Scanner::oneArgFunction,  RSS::PUTENV}},
    {"sizeof",      {&Scanner::oneArgFunction,  RSS::SIZEOF}},
    {"sizeoflist",  {&Scanner::oneArgFunction,  RSS::SIZEOF}},
    {"strlen",      {&Scanner::oneArgFunction,  RSS::STRLEN}},
    {"strlwr",      {&Scanner::oneArgFunction,  RSS::STRLWR}},
    {"strupr",      {&Scanner::oneArgFunction,  RSS::STRUPR}},

    {"change_base", {&Scanner::twoArgFunction,  RSS::CHANGE_BASE}},
    {"change_ext",  {&Scanner::twoArgFunction,  RSS::CHANGE_EXT}},
    {"change_path", {&Scanner::twoArgFunction,  RSS::CHANGE_PATH}},
    {"element",     {&Scanner::twoArgFunction,  RSS::ELEMENT}},
    {"fgets",       {&Scanner::twoArgFunction,  RSS::FGETS}},
    {"strtok",      {&Scanner::twoArgFunction,  RSS::STRTOK}},

    {"substr",      {&Scanner::threeArgFunction,  RSS::SUBSTR}},

    {"chdir",       {&Scanner::function,  RSS::CHDIR}},
    {"stat",        {&Scanner::function,  RSS::STAT}},
    {"system",      {&Scanner::function,  RSS::SYSTEM}},
    {"fprintf",     {&Scanner::function,  RSS::FPRINTF}},
    {"exec",        {&Scanner::function,  RSS::EXEC}},
    {"execute",     {&Scanner::function,  RSS::EXECUTE}},
    {"exit",        {&Scanner::function,  RSS::EXIT}},
    {"makelist",    {&Scanner::function,  RSS::MAKELIST}},
    {"printf",      {&Scanner::function,  RSS::PRINTF}},
    {"strfind",     {&Scanner::function,  RSS::STRFIND}},

    {"break",       {&Scanner::keyword,   Keyword::BREAK}},
    {"else",        {&Scanner::keyword,   Keyword::ELSE}},
    {"for",         {&Scanner::keyword,   Keyword::FOR}},
    {"if",          {&Scanner::keyword,   Keyword::IF}},
    {"return",      {&Scanner::keyword,   Keyword::RETURN}},
    {"while",       {&Scanner::keyword,   Keyword::WHILE}},

    {"int",         {&Scanner::type,      Type::INT}},
    {"void",        {&Scanner::type,      Type::VOID}},
    {"list",        {&Scanner::type,      Type::LIST}},
    {"string",      {&Scanner::type,      Type::STRING}},

    {"older",       {&Scanner::opcode,    Opcode::OLDER}},
    {"newer",       {&Scanner::opcode,    Opcode::YOUNGER}},
    {"younger",     {&Scanner::opcode,    Opcode::YOUNGER}},
}


