#ifndef __CUSTOM_ERRORS_H__
#define __CUSTOM_ERRORS_H__

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define DEBUG       1

#ifdef DEBUG
# define DPRINTF(...) printf( __VA_ARGS__)
#else
# define DPRINTF(...)
#endif

#define err_abort(code, text)   do{                                           \
            fprintf(stderr,"%s at \"%s\":%d:%s\r\n",                       \
            text, __FILE__, __LINE__, strerror(code));                          \
            abort();                                                          \
            }while(0);

#define errno_abort(text)   do{                                           \
            fprintf(stderr, "%s at \"%s\":%d:%s\r\n",                       \
            text, __FILE__, __LINE__, strerror(errno));                          \
            abort();                                                          \
            }while(0);

#endif
