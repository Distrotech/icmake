#include "icmake.ih"


void read_compiled_defaults(FILE *config)
{
    char *buf = NULL;
    char *line = NULL;

    xrealloc(buf, MAX_PATH_);
    xrealloc(line, 1);
    line[0] = 0;
    
    while (true)
    {
        size_t idx;

        if (fgets(buf, MAX_PATH_, config))      /* read a line */
        {
            size_t length = cut_off_nl(buf);    /* remove final \n  */

            if 
            (
                not hasComment(&length, buf)
                &&
                line_continues(&line, buf, length)
            )
                continue;
        }

        if (!empty(line)
            check_parameters(line);

        xrealloc(line, 1);
        line[0] = 0;
    }
}
