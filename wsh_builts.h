#ifndef WSH_BUILTS_H
#define WSH_BUILTS_H

struct built_s {
  char *nom;
  void (*ops)(char **args);
};  

extern struct built_s builtins[];

int wsh_builts(void);

#endif