#include "options.ih"

void Options::setOptions()
{
    string value;

    d_infile = 
        d_execute ?
            d_file.fileName(d_arg[0], d_preProcess ? "pim" : "bim")
        :
            d_file.fileName(d_arg[0], "im");

    d_outfile = 
        d_arg.beyondDashes() > 1 ?
            d_arg[1]
        :
            d_file.fileName(d_infile, 
                            d_execute && d_preProcess ? "pim" : "bim");
}
