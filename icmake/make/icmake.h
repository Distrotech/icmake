#include "../rss/rss.h"

#include "../tmp/INSTALL.im"


typedef enum
{
    f_preprocessor  =   (1 << 0),
    f_compiler      =   (1 << 1),
    f_quiet         =   (1 << 2),
    f_redirected    =   (1 << 3),
    f_blunt         =   (1 << 4),
    f_icmake        =   (1 << 5),
    f_tmpbim        =   (1 << 6)
} FLAGS_;

extern char
    version[],
    release[],
    cant_read[],
    r[],
    rb[];

extern char *g_temporary;
extern char *g_config_name;
extern char *g_source_name;
extern char *g_dest_name;
extern FILE *fdest;
extern FLAGS_ g_flags;
extern int errors;

int     compile_test (void);           /* test if compilation is needed */
int     options (char **, int*);       /* process flags */
void    abnormal_exit (int);           /* abnormal eop */
void    about(void);                   /* about icmake */
void    cleanup (void);                /* cleanup temp. info */
void    quote_blanks(char **);         /* quote arguments with blanks */

char const *homedir();           /* return NULL or ptr to the homedir */
void        usage(char const *prog);
size_t      cut_off_nl(char *buf);
bool        has_comment(size_t *length; char *buf);
bool        line_continues(char **line, char *buf, size_t length);
bool        empty(char *line);
char       *value_of(char *value);



