#ifndef INCLUDED_FILENAME_H_
#define INCLUDED_FILENAME_H_

char const *change_ext (char const *, char const *);
char const *change_base (char const *, char const *);
char const *change_path (char const *, char const *);

char const *makepath(char const *path, char const *file, char const *ext);

void        splitpath_(char const *, char *, char *, char *, char *);

#endif
