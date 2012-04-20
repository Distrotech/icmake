int preprocess()
{
    loadsym();

    if (!(imdir = getenv("IM")) )
        imdir = ".";

    if (!(outfile = fopen(g_source_name, "w")) )
        error("cannot open input file %s", g_source_name);

    pushfile(g_source_name);
    construct_active();

    while (filesp >= 0)
        process(lexer());
}
