#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "stdint.h"

#define PROGRAM_MASTER 0

#define PROGRAM_TEST_SERVO_LEFT_HAND 1
#define PROGRAM_TEST_SERVO_LEFT_WRIST 2
#define PROGRAM_TEST_SERVO_RIGHT_HAND 3
#define PROGRAM_TEST_SERVO_RIGHT_WRIST 4
#define PROGRAM_TEST_SERVO_NONLINEAR 5

#define MAIN_PROGRAM PROGRAM_TEST_SERVO_NONLINEAR

/*============================================================================*/
/* MACROS     Overflow protection                                             */
/*============================================================================*/
#define CLIP_VALUE(x, min, max) ((x) < (min) ? (min) :      \
                                 (x) > (max) ? (max) : (x))

typedef enum {LEFT_HAND,LEFT_WRIST,RIGHT_HAND,RIGHT_WRIST}type_servo;

#endif