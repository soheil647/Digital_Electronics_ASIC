#ifndef _INC_STRING
#define _INC_STRING

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif

#ifndef NULL
#define NULL    ((void *)0)
#endif

void *   memcpy(void *, const void *, size_t);
int      memcmp(const void *, const void *, size_t);
void *   memset(void *, int, size_t);
char *   strcpy(char *, const char *);
char *   strcat(char *, const char *);
int      strcmp(const char *, const char *);
size_t   strlen(const char *);
void *   memccpy(void *, const void *, int, unsigned int);
void *   memchr(const void *, int, size_t);
void *   memmove(void *, const void *, size_t);
char *   strchr(const char *, int);
int      strcoll(const char *, const char *);
size_t   strcspn(const char *, const char *);
char *   strdup(const char *);
char *   strerror(int);
char *   strncat(char *, const char *, size_t);
int      strncmp(const char *, const char *, size_t);
char *   strncpy(char *, const char *, size_t);
char *   strpbrk(const char *, const char *);
char *   strrchr(const char *, int);
size_t   strspn(const char *, const char *);
char *   strstr(const char *, const char *);
char *   strtok(char *, const char *);
size_t   strxfrm (char *, const char *, size_t);

#endif  /* _INC_STRING */
