#ifndef INCLUDED_GENERAL_H_
#define INCLUDED_GENERAL_H_

void copyright(char const *label); 

int exists(char const *pathname);
int older(char const *lhs_path, char const *rhs_path);
int younger(char const *lhs_path, char const *rhs_path);

char const *program_name(char const *argv0);  /* make progname from argv[0] */

void error(char const *fmt, ...);

extern char const gr_version[];
extern char const gr_years[];

#endif
