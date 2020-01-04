#ifndef _INC_MALLOC
#define _INC_MALLOC

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif

void * calloc(size_t, size_t);
void   free(void *);
void * malloc(size_t);
void * realloc(void *, size_t);

#endif  /* _INC_MALLOC */
