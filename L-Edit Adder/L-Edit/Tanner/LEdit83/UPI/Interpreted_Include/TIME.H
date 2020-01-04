#ifndef _INC_TIME
#define _INC_TIME

#ifndef _TIME_T_DEFINED
typedef long time_t;   
#define _TIME_T_DEFINED
#endif

#ifndef _CLOCK_T_DEFINED
typedef long clock_t;
#define _CLOCK_T_DEFINED
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif


#ifndef NULL
#define NULL    ((void *)0)
#endif


#ifndef _TM_DEFINED
struct tm {
        int tm_sec; 
        int tm_min; 
        int tm_hour;
        int tm_mday;
        int tm_mon; 
        int tm_year;
        int tm_wday;
        int tm_yday;
        int tm_isdst;
        };
#define _TM_DEFINED
#endif

#define CLOCKS_PER_SEC  1000
extern char * tzname[2];


 char * asctime(const struct tm *);
 char * ctime(const time_t *);
 clock_t  clock(void);
 double  difftime(time_t, time_t);
 struct tm *  gmtime(const time_t *);
 struct tm *  localtime(const time_t *);
 time_t  mktime(struct tm *);
 size_t  strftime(char *, size_t, const char *,
        const struct tm *);
 time_t  time(time_t *);
 void  tzset(void);

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif


#define CLK_TCK  CLOCKS_PER_SEC

 extern int daylight;
 extern long timezone;
 extern char * tzname[2];

 void  tzset(void);

#endif  /* _INC_TIME */
