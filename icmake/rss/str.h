#ifndef INCLUDED_STR_H_
#define INCLUDED_STR_H_

char     *strlwr_(char *src);
char     *strupr_(char *src);
char     *xstrdup(char const *src);
char     *xstrcat (char *dest, char const *src);
void     *xrealloc (void *, size_t);

#endif
