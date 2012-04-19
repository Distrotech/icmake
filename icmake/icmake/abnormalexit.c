/*
                            A B N O R M A L . C
*/

#include "icmake.ih"

void abnormal_exit(int x)
{
    ++g_errors;
    error("Abnormal ending");
}
