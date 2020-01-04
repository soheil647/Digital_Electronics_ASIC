#ifndef _INC_STDIO
#define _INC_STDIO

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif


#ifndef _VA_LIST_DEFINED
typedef char *  va_list;
#define _VA_LIST_DEFINED
#endif

#define BUFSIZ  512

#define _NSTREAM_   512
#define _IOB_ENTRIES 20

#define EOF     (-1)


#ifndef _FILE_DEFINED
struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif

#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0


#define FILENAME_MAX    260
#define FOPEN_MAX       20
#define _SYS_OPEN       20
#define TMP_MAX         32767


#ifndef NULL
#define NULL    ((void *)0)
#endif


#ifndef _STDIO_DEFINED
extern FILE _iob[];
#endif 

#ifndef _FPOS_T_DEFINED
typedef struct fpos_t {
        unsigned int lopart;
        int          hipart;
        } fpos_t;
#define _FPOS_T_DEFINED
#endif


#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])


#define _IOREAD         0x0001
#define _IOWRT          0x0002

#define _IOFBF          0x0000
#define _IOLBF          0x0040
#define _IONBF          0x0004

#define _IOMYBUF        0x0008
#define _IOEOF          0x0010
#define _IOERR          0x0020
#define _IOSTRG         0x0040
#define _IORW           0x0080

#ifndef _STDIO_DEFINED

void  clearerr(FILE *);
int  fclose(FILE *);
int  fcloseall(void);

FILE *  fdopen(int, const char *);

int  feof(FILE *);
int  ferror(FILE *);
int  fflush(FILE *);
int  fgetc(FILE *);
int  fgetpos(FILE *, fpos_t *);
char *  fgets(char *, int, FILE *);

int  fileno(FILE *);

FILE *  fopen(const char *, const char *);
int  fprintf(FILE *, const char *, ...);
int  fputc(int, FILE *);
int  fputs(const char *, FILE *);
size_t  fread(void *, size_t, size_t, FILE *);
FILE *  freopen(const char *, const char *, FILE *);
int  fscanf(FILE *, const char *, ...);
int  fsetpos(FILE *, const fpos_t *);
int  fseek(FILE *, long, int);
long  ftell(FILE *);
size_t  fwrite(const void *, size_t, size_t, FILE *);
int  getc(FILE *);
int  getchar(void);
char *  gets(char *);
int  getw(FILE *);
void  perror(const char *);
int  printf(const char *, ...);
int  putc(int, FILE *);
int  putchar(int);
int  puts(const char *);
int  putw(int, FILE *);
int  remove(const char *);
int  rename(const char *, const char *);
void  rewind(FILE *);
int  scanf(const char *, ...);
void  setbuf(FILE *, char *);
int  setvbuf(FILE *, char *, int, size_t);
int  sprintf(char *, const char *, ...);
int  sscanf(const char *, const char *, ...);
char *  tempnam(const char *, const char *);
FILE *  tmpfile(void);
char *  tmpnam(char *);
int  ungetc(int, FILE *);
int  unlink(const char *);
int  vfprintf(FILE *, const char *, va_list);
int  vprintf(const char *, va_list);
int  vsprintf(char *, const char *, va_list);

#define _STDIO_DEFINED
#endif  /* _STDIO_DEFINED */


#define feof(_stream)     ((_stream)->_flag & _IOEOF)
#define ferror(_stream)   ((_stream)->_flag & _IOERR)
#define getc(_stream)     (--(_stream)->_cnt >= 0 \
                ? 0xff & *(_stream)->_ptr++ : _filbuf(_stream))
#define putc(_c,_stream)  (--(_stream)->_cnt >= 0 \
                ? 0xff & (*(_stream)->_ptr++ = (char)(_c)) :  _flsbuf((_c),(_stream)))
#define getchar()         getc(stdin)
#define putchar(_c)       putc((_c),stdout)

#endif  /* _INC_STDIO */
