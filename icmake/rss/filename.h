#ifndef INCLUDED_FILENAME_H_
#define INCLUDED_FILENAME_H_

char const *change_ext (char const *, char const *);
char const *change_base (char const *, char const *);
char const *change_path (char const *, char const *);

char const *get_ext(char const *pathname);          /* fname.c */
char const *get_base(char const *pathname);
char const *get_path (char const *pathname);


char const *makepath(char const *path, char const *file, char const *ext);

void        splitpath_(char const *, char *, char *, char *, char *);

#endif
