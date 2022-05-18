#ifndef _MAIN_H_
#define _MAIN_H_

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t read_textfile(const char *filename, size_t letters);
int hsh_env(char **args, char __attribute__((__unused__)) **start);

#endif
