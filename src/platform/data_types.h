/*! ----------------------------------------------------------------------------
 *  @file 	data_types.h
 *  @brief 	general type definitions
 *
 * @attention
 *
 *
 */

#ifndef _DATA_TYPES_H_
#define _DATA_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "compiler.h"

#ifndef uint8
typedef unsigned char uint8;
#endif

#ifndef uint16
typedef unsigned short uint16;
#endif

#ifndef uint32
typedef unsigned long uint32;
#endif

#ifndef int8
typedef signed char int8;
#endif

#ifndef int16
typedef signed short int16;
#endif

#ifndef int32
typedef signed long int32;
#endif

typedef uint64_t        uint64 ;

typedef int64_t         int64 ;


#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifdef __cplusplus
}
#endif

#endif /* DECA_TYPES_H_ */


