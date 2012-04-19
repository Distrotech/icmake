#ifndef INCLUDED_FILENAME_H_
#define INCLUDED_FILENAME_H_

#include "typedefs.h"

char const *change_ext(char const *, char const *);
char const *change_base(char const *, char const *);
char const *change_path(char const *, char const *);

char const *get_ext(char const *pathname);
char const *get_base(char const *pathname);
char const *get_path(char const *pathname);

void splitpath(char const *path, char *dir, char *fname, char *ext);
char *makepath(char const *dir, char const *fname, char const *ext);

char *try_source_im(char const *source);

BIN_HEADER_ *read_header(FILE *file, size_t major_version_nr);


#endif
