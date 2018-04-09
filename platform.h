/* all platform-specific includes and defines go in this file */
#ifndef PLATFORM_H
#define PLATFORM_H

#define LARGE_INT_POWER_OF_TEN 1000000000   /* the largest power of ten which fits in an int on this architecture */
#if defined(__hppa__) || defined(__sparc__)
#define ALIGN_TYPE double                   /* the default data type to use for alignment */
#else
#define ALIGN_TYPE void *                   /* the default data type to use for alignment */
#endif

#define GLOBAL_TABLE_SIZE 97                /* global variable table */
#define STRING_TABLE_SIZE 97                /* shared string table size */
#define STRING_LITERAL_TABLE_SIZE 97        /* string literal table size */
#define RESERVED_WORD_TABLE_SIZE 97         /* reserved word table size */
#define PARAMETER_MAX 16                    /* maximum number of parameters to a function */
#define LINEBUFFER_MAX 256                  /* maximum number of characters on a line */
#define LOCAL_TABLE_SIZE 11                 /* size of local variable table (can expand) */
#define STRUCT_TABLE_SIZE 11                /* size of struct/union member table (can expand) */

#define INTERACTIVE_PROMPT_START "starting picoc " PICOC_VERSION "\n"
#define INTERACTIVE_PROMPT_STATEMENT "picoc> "
#define INTERACTIVE_PROMPT_LINE "     > "

/* host platform includes */
#ifdef UNIX_HOST
#define HEAP_SIZE (128*1024)
#define USE_MALLOC_STACK                   /* stack is allocated using malloc() */
#define USE_MALLOC_HEAP                    /* heap is allocated using malloc() */
//#define NO_CALLOC
//#define NO_REALLOC
//#define DEBUG_HEAP

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <setjmp.h>
#include <math.h>

#define PICOC_MATH_LIBRARY
#define USE_READLINE
#undef BIG_ENDIAN
#if defined(__powerpc__) || defined(__hppa__) || defined(__sparc__)
# define BIG_ENDIAN
#endif
#endif


#ifdef WIN32
#define HEAP_SIZE (16*1024)
#define USE_MALLOC_STACK                   /* stack is allocated using malloc() */
#define USE_MALLOC_HEAP                    /* heap is allocated using malloc() */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <setjmp.h>
#include <math.h>
#define PICOC_MATH_LIBRARY
#undef BIG_ENDIAN
#endif


#ifdef FREERTOS_HOST
#define HEAP_SIZE (128*1024)
#define NO_CALLOC
#define NO_REALLOC
#define NO_STRING_FUNCTIONS
#define NO_FP
#undef NO_DEBUGGER
#undef DEBUG_HEAP
#undef BUILTIN_MINI_STDLIB
#include <assert.h>	// Conditionally compiled macro that compares its argument to zero
#include <complex.h> // (since C99)	Complex number arithmetic
#include <ctype.h>	// Functions to determine the type contained in character data
#include <errno.h>	// Macros reporting error conditions
#include <fenv.h> // (since C99)	Floating-point environment
#include <float.h>	// Limits of float types
#include <inttypes.h> // (since C99)	Format conversion of integer types
#include <iso646.h> // (since C95)	Alternative operator spellings
#include <limits.h>	// Sizes of basic types
#include <locale.h>	// Localization utilities
#include <math.h>	// Common mathematics functions
#include <setjmp.h>	// Nonlocal jumps
#include <signal.h>	// Signal handling
#include <stdalign.h> // (since C11)	alignas and alignof convenience macros
#include <stdarg.h>	// Variable arguments
#include <stdatomic.h> // (since C11)	Atomic types
#include <stdbool.h> // (since C99)	Boolean type
#include <stddef.h>	// Common macro definitions
#include <stdint.h> // (since C99)	Fixed-width integer types
#include <stdio.h>	// Input/output
#include <stdlib.h>	// General utilities: memory management, program utilities, string conversions, random numbers
#include <stdnoreturn.h> // (since C11)	noreturn convenience macros
#include <string.h>	// String handling
#include <tgmath.h> // (since C99)	Type-generic math (macros wrapping math.h and complex.h)
#include <time.h>	// Time/date utilities
#include <uchar.h> // (since C11)	UTF-16 and UTF-32 character utilities
#include <wchar.h> // (since C95)	Extended multibyte and wide character utilities
#include <wctype.h> // (since C95)	Functions to determine the type contained in wide character data
#undef PICOC_MATH_LIBRARY
//#define BUILTIN_MINI_STDLIB
#undef BIG_ENDIAN
#endif




#endif /* PLATFORM_H */
