
/*
 * SerialLine DataStructure for test v0.1.1
 *
 * Written by Jin kim 2021 @ Robit
 *
 * Change code below and struct.c to fit user'needs.
 *
 * -- !!DISCLAIMERS!! --
 * 1. WRITE IN STANDARD C. IT WON'T BE COMPATIBLE WITH SLAVE SERIAL_LINE LIBRARY(WRITTEN IN C) OTHERWISE.
 * 2. DEFINE STRUCT FOR EACH SLAVE TYPE(motor driver, manipulator etc). DEFINE A MASTER STRUCT THAT HAS SLAVE STRUCTS DEDICATED TO EACH HARDWARD/SIMULATED SLAVE.
 * 3. ENCAPSULATE EVERY VARIABLE INTO A STRUCT. 'STRAY' ONES MIGHT BE HARD TO SPECIFY THEIR ADDRESSES.
 */

#ifndef _DATA_STRUCTURE_H_
#define _DATA_STRUCTURE_H_

#ifdef __cplusplus
extern "C" {
namespace scue {
#else
#include "stdbool.h"
#endif

/*
 * SLAVE STRUCTS
 */

typedef struct _Slave1
{
	int a,b,c;
	int test; 
}Slave1;

typedef struct _Slave2
{
	int d,e,f;
}Slave2;

typedef struct _Manipulator
{
	float targetAngle[6];
}Manipulator;

typedef struct _MasterTweak
{
	bool initTrigger;
}MasterTweak;

/*
 * MASTER STRUCT
 */

typedef struct _Master
{
	Slave1 slave1;
	Slave2 slave2;
	Manipulator manipulator;
	MasterTweak masterTweak;
}Master;

/*
 * INIT FUNCTIONS
 * Implement them in "struct.c".
 */

void initSlave1(Slave1 *s);
void initSlave2(Slave2 *s);
void initManipulator(Manipulator *s);
void initMasterTweak(MasterTweak *s);
void initMaster(Master *s);

#ifdef __cplusplus
}//namespace scue
}//extern "C"
#endif
#endif
