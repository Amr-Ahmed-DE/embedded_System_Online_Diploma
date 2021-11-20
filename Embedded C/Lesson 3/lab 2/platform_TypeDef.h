/* created By Amr Ahmed*/

#ifndef PLATFORM_TYPEDEF_H_
#define PLATFORM_TYPEDEF_H_

#include<stdbool.h>
#include<stdint.h>

#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE                CPU_TYPE_32
#define CPU_BIT_ORDER           MSB_FIRST
#define CPU_BYTE_ORDER          HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE                   (boolean)false 
#endif

#ifndef TRUE
#define TRUE                    (boolean)true
#endif

typedef _Bool                   boolean;

 /* Signed*/

typedef signed char             sint8;
typedef signed short int        sint16;
typedef signed int              sint32;
typedef long long int           sint64;

/*Unsigned*/

typedef unsigned char           uint8;
typedef unsigned short int      uint16;
typedef unsigned int            uint32;
typedef unsigned long long int  uint64;

/*Volatile*/

typedef volatile signed char         vint8_t;
typedef volatile unsigned char       vuint8_t;

typedef volatile signed short int    vint16_t;
typedef volatile unsigned short int  vuint16_t;

typedef volatile signed int          vint32_t;
typedef volatile unsigned int        vuint32_t;

typedef volatile signed long long    vint64_t;
typedef volatile unsigned long long  vuint64_t;


#endif /* PLATFORM_TYPEDEF_H_ */
