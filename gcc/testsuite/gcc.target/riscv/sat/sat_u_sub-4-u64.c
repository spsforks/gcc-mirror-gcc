/* { dg-do compile } */
/* { dg-options "-march=rv64gc -mabi=lp64d -fdump-tree-optimized -fno-schedule-insns -fno-schedule-insns2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "sat_arith.h"

/*
** sat_u_sub_uint64_t_fmt_4:
** sub\s+[atx][0-9]+,\s*a0,\s*a1
** sltu\s+[atx][0-9]+,\s*a0,\s*a1
** addi\s+a0,\s*[atx][0-9]+,\s*-1
** and\s+a0,\s*[atx][0-9]+,\s*[atx][0-9]+
** ret
*/
DEF_SAT_U_SUB_FMT_4(uint64_t)

/* { dg-final { scan-tree-dump-times ".SAT_SUB " 1 "optimized" } } */
