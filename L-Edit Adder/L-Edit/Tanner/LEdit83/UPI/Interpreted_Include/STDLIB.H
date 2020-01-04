#ifndef _INC_STDLIB
#define _INC_STDLIB

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif

#ifndef NULL
#define NULL    ((void *)0)
#endif

#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1

#ifndef _DIV_T_DEFINED
typedef struct _div_t {
        int quot;
        int rem;
} div_t;
typedef struct _ldiv_t {
        long quot;
        long rem;
} ldiv_t;
#define _DIV_T_DEFINED
#endif

#define RAND_MAX 0x7fff

void    abort(void);
int     atexit(void (*func)(void));
double  atof(const char *);
int     atoi(const char *);
long    atol(const char *);
void *  bsearch(const void *, const void *, size_t, size_t,
					 int (*compar)(const void *, const void *));
div_t   div(int, int);
void    exit(int);
char *  getenv(const char *);
ldiv_t  ldiv(long, long);
int     mblen(const char *, size_t);
void    qsort(void *, size_t, size_t, int (*compr)
				  (const void *, const void *));
int     rand(void);
void    srand(unsigned int);
double  strtod(const char *, char **);
long    strtol(const char *, char **, int);
unsigned long  strtoul(const char *, char **, int);
int     system(const char *);
char *  ecvt(double, int, int *, int *);
char *  fcvt(double, int, int *, int *);		  
char *  gcvt(double, int, char *);
int     putenv(const char *);
void    swab(char *, char *, int);
char *  itoa(int, char *, int);
char *  ltoa(long, char *, int);
char *  ultoa(unsigned long, char *, int);


#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))


#endif  /* _INC_STDLIB */
