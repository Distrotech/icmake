#ifndef INCLUDED_SPAWN_H_
#define INCLUDED_SPAWN_H_

int spawnlp(int mode, char const *prog, char const *av0, ...);
int spawnvp(int mode, char const *prog, char const **argv);    
void spawn_err(char const *progname);


#endif
