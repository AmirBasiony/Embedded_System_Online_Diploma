#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#ifndef TURE
#define TURE    1
#endif 

#ifndef FALSE
#define FALSE    0
#endif 

typedef signed char	            sint8_t;
typedef unsigned char	        uint8_t;
typedef signed short	        sint16_t;
typedef unsigned short	        uint16_t;
typedef signed int	            sint32_t;
typedef unsigned int         	uint32_t;
typedef signed long long        sint64_t;
typedef unsigned long long  	uint64_t;



typedef volatile signed char		vint8_t;
typedef volatile unsigned char		vuint8_t;
typedef volatile signed short		vint16_t;
typedef volatile unsigned short		vuint16_t;
typedef volatile signed int	    	vint32_t;
typedef volatile unsigned int		vuint32_t;
typedef volatile signed long long	vint64_t;
typedef volatile unsigned long long	vuint64_t;


#endif	/* PLATFORM_TYPES_H_	*/