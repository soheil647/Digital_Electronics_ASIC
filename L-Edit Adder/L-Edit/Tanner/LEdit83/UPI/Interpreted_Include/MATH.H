#ifndef _INC_MATH
#define _INC_MATH

#ifndef _EXCEPTION_DEFINED
struct _exception {
        int type;       /* exception type - see below */
        char *name;     /* name of function where error occured */
        double arg1;    /* first argument to function */
        double arg2;    /* second argument (if any) to function */
        double retval;  /* value to be returned by function */
        } ;
#define _EXCEPTION_DEFINED
#endif

#define _DOMAIN     1   /* argument domain error */
#define _SING       2   /* argument singularity */
#define _OVERFLOW   3   /* overflow range error */
#define _UNDERFLOW  4   /* underflow range error */
#define _TLOSS      5   /* total loss of precision */
#define _PLOSS      6   /* partial loss of precision */

#define EDOM        33
#define ERANGE      34


extern double _HUGE;
#define HUGE_VAL _HUGE


int      abs(int);
double   acos(double);
double   asin(double);
double   atan(double);
double   atan2(double, double);
double   cos(double);
double   cosh(double);
double   exp(double);
double   fabs(double);
double   fmod(double, double);
long     labs(long);
double   log(double);
double   log10(double);
double   pow(double, double);
double   sin(double);
double   sinh(double);
double   tan(double);
double   tanh(double);
double   sqrt(double);

double   atof(const char *);
double   ceil(double);
double   floor(double);
double   frexp(double, int *);
double   hypot(double, double);
double   j0(double);
double   j1(double);
double   jn(int, double);
double   ldexp(double, int);
int      matherr(struct _exception *);
double   modf(double, double *);
double   y0(double);
double   y1(double);
double   yn(int, double);

#define acosl(x)    ((long double)acos((double)(x)))
#define asinl(x)    ((long double)asin((double)(x)))
#define atanl(x)    ((long double)atan((double)(x)))
#define atan2l(x,y) ((long double)atan2((double)(x), (double)(y)))
#define ceill(x)    ((long double)ceil((double)(x)))
#define cosl(x)     ((long double)cos((double)(x)))
#define coshl(x)    ((long double)cosh((double)(x)))
#define expl(x)     ((long double)exp((double)(x)))
#define fabsl(x)    ((long double)fabs((double)(x)))
#define floorl(x)   ((long double)floor((double)(x)))
#define fmodl(x,y)  ((long double)fmod((double)(x), (double)(y)))
#define frexpl(x,y) ((long double)frexp((double)(x), (y)))
#define ldexpl(x,y) ((long double)ldexp((double)(x), (y)))
#define logl(x)     ((long double)log((double)(x)))
#define log10l(x)   ((long double)log10((double)(x)))
#define modfl(x,y)  ((long double)modf((double)(x), (double *)(y)))
#define powl(x,y)   ((long double)pow((double)(x), (double)(y)))
#define sinl(x)     ((long double)sin((double)(x)))
#define sinhl(x)    ((long double)sinh((double)(x)))
#define sqrtl(x)    ((long double)sqrt((double)(x)))
#define tanl(x)     ((long double)tan((double)(x)))
#define tanhl(x)    ((long double)tanh((double)(x)))

#endif  /* _INC_MATH */

