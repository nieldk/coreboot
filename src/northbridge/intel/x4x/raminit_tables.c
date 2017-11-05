/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2017 Arthur Heymans <arthur@aheymans.xyz>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <arch/io.h>
#include <stdint.h>
#include "x4x.h"

const struct dll_setting default_ddr2_667_ctrl[7] = {
	/* tap  pi db  delay coarse*/
	{13, 0, 1, 0, 0, 0}, /* clkset0 */
	{4,  1, 0, 0, 0, 0}, /* ctrl0 */
	{13, 0, 1, 0, 0, 0}, /* clkset1 */
	{4,  5, 0, 0, 0, 0}, /* cmd */
	{4,  1, 0, 0, 0, 0}, /* ctrl1 */
	{4,  1, 0, 0, 0, 0}, /* ctrl2 */
	{4,  1, 0, 0, 0, 0}, /* ctrl3 */
};

const struct dll_setting default_ddr2_667_dqs[TOTAL_BYTELANES] = {
	{1,  5, 1, 1, 1, 0},
	{1,  6, 1, 1, 1, 0},
	{2,  0, 1, 1, 1, 0},
	{2,  1, 1, 1, 1, 0},
	{2,  1, 1, 1, 1, 0},
	{14, 6, 1, 0, 0, 0},
	{14, 3, 1, 0, 0, 0},
	{14, 0, 1, 0, 0, 0},
};

const struct dll_setting default_ddr2_667_dq[TOTAL_BYTELANES] = {
	{9,  0, 0, 0, 1, 0},
	{9,  1, 0, 0, 1, 0},
	{9,  2, 0, 0, 1, 0},
	{9,  2, 0, 0, 1, 0},
	{9,  1, 0, 0, 1, 0},
	{6,  4, 0, 0, 1, 0},
	{6,  2, 0, 0, 1, 0},
	{5,  4, 0, 0, 1, 0}
};

const struct dll_setting default_ddr2_800_ctrl[7] = {
	/* tap  pi db  delay coarse */
	{11, 5, 1, 0, 0, 0},
	{0,  5, 1, 1, 0, 0},
	{11, 5, 1, 0, 0, 0},
	{1,  4, 1, 1, 0, 0},
	{0,  5, 1, 1, 0, 0},
	{0,  5, 1, 1, 0, 0},
	{0,  5, 1, 1, 0, 0},
};

const struct dll_setting default_ddr2_800_dqs[TOTAL_BYTELANES] = {
	{2,  5, 1, 1, 1, 0},
	{2,  6, 1, 1, 1, 0},
	{3,  0, 1, 1, 1, 0},
	{3,  0, 1, 1, 1, 0},
	{3,  3, 1, 1, 1, 0},
	{2,  0, 1, 1, 1, 0},
	{1,  3, 1, 1, 1, 0},
	{0,  3, 1, 1, 1, 0},
};

const struct dll_setting default_ddr2_800_dq[TOTAL_BYTELANES] = {
	{9,  3, 0, 0, 1, 0},
	{9,  4, 0, 0, 1, 0},
	{9,  5, 0, 0, 1, 0},
	{9,  6, 0, 0, 1, 0},
	{10, 0, 0, 0, 1, 0},
	{8,  1, 0, 0, 1, 0},
	{7,  5, 0, 0, 1, 0},
	{6,  2, 0, 0, 1, 0}
};

const struct dll_setting default_ddr3_800_ctrl[2][7] = {
	{ /* 1N */
		/* tap  pi db(2)  delay coarse */
		{8, 2, 0, 0, 0, 0},
		{8, 4, 0, 0, 0, 0},
		{9, 5, 0, 0, 0, 0},
		{6, 1, 0, 0, 0, 0},
		{8, 4, 0, 0, 0, 0},
		{10, 0, 0, 0, 0, 0},
		{10, 0, 0, 0, 0, 0}, },
	{ /* 2N */
		{2, 2, 1, 1, 0, 0},
		{2, 4, 1, 1, 0, 0},
		{3, 5, 0, 0, 0, 0},
		{3, 2, 1, 1, 0, 0},
		{2, 4, 1, 1, 0, 0},
		{3, 6, 0, 0, 0, 0},
		{3, 6, 0, 0, 0, 0}, }
};

const struct dll_setting default_ddr3_800_dqs[2][TOTAL_BYTELANES] = {
	{ /* 1N */
		{12, 0, 1, 0, 0, 0},
		{1, 1, 1, 1, 1, 0},
		{2, 4, 1, 1, 1, 0},
		{3, 5, 0, 0, 1, 0},
		{4, 3, 0, 0, 1, 0},
		{5, 2, 0, 0, 1, 0},
		{6, 1, 0, 0, 1, 0},
		{6, 4, 0, 0, 1, 0}, },
	{ /* 2N */
		{5, 6, 0, 0, 0, 0},
		{8, 0, 0, 0, 0, 0},
		{9, 4, 0, 0, 0, 0},
		{10, 4, 1, 0, 0, 0},
		{11, 3, 1, 0, 0, 0},
		{12, 1, 1, 0, 0, 0},
		{0, 1, 1, 1, 1, 0},
		{0, 3, 1, 1, 1, 0}, }
};

const struct dll_setting default_ddr3_800_dq[2][TOTAL_BYTELANES] = {
	{ /* 1N */
		{4, 1, 0, 0, 1, 0},
		{6, 4, 0, 0, 1, 0},
		{8, 1, 0, 0, 1, 0},
		{8, 6, 0, 0, 1, 0},
		{9, 5, 0, 0, 1, 0},
		{10, 2, 0, 0, 1, 0},
		{10, 6, 1, 0, 1, 0},
		{11, 4, 1, 0, 1, 0} },
	{ /* 2N */
		{11, 0, 1, 0, 0, 0},
		{0, 3, 1, 1, 1, 0},
		{2, 1, 1, 1, 1, 0},
		{2, 5, 1, 1, 1, 0},
		{3, 5, 0, 0, 1, 0},
		{4, 2, 0, 0, 1, 0},
		{4, 6, 0, 0, 1, 0},
		{5, 4, 0, 0, 1, 0}, }
};

const struct dll_setting default_ddr3_1067_ctrl[2][7] = {
	{ /* 1N */
		{8, 5, 0, 0, 0, 0},
		{7, 6, 0, 0, 0, 0},
		{10, 2, 1, 0, 0, 0},
		{4, 4, 0, 0, 0, 0},
		{7, 6, 0, 0, 0, 0},
		{9, 2, 1, 0, 0, 0},
		{9, 2, 1, 0, 0, 0}, },
	{ /* 2N */
		{1, 5, 1, 1, 0, 0},
		{0, 6, 1, 1, 0, 0},
		{3, 2, 0, 0, 0, 0},
		{2, 6, 1, 1, 0, 0},
		{0, 6, 1, 1, 0, 0},
		{2, 2, 1, 1, 0, 0},
		{2, 2, 1, 1, 0, 0}, }
};

const struct dll_setting default_ddr3_1067_dqs[2][TOTAL_BYTELANES] = {
	{ /* 1N */
		{2, 5, 1, 1, 1, 0},
		{5, 1, 0, 0, 1, 0},
		{6, 6, 0, 0, 1, 0},
		{8, 0, 0, 0, 1, 0},
		{8, 6, 0, 0, 1, 0},
		{9, 6, 1, 0, 1, 0},
		{10, 6, 1, 0, 1, 0},
		{0, 1, 1, 1, 0, 1}, },
	{ /* 2N */
		{6, 4, 0, 0, 0, 0},
		{9, 1, 1, 0, 0, 0},
		{10, 6, 1, 0, 0, 0},
		{1, 0, 1, 1, 1, 0},
		{1, 6, 1, 1, 1, 0},
		{2, 5, 1, 1, 1, 0},
		{3, 5, 0, 0, 1, 0},
		{4, 1, 0, 0, 1, 0},
	}
};

const struct dll_setting default_ddr3_1067_dq[2][TOTAL_BYTELANES] = {
	{ /* 1N */
		{6, 5, 0, 0, 1, 0},
		{9, 3, 1, 0, 1, 0},
		{0, 2, 1, 1, 0, 1},
		{1, 0, 1, 1, 0, 1},
		{2, 0, 1, 1, 0, 1},
		{2, 5, 1, 1, 0, 1},
		{3, 2, 0, 0, 0, 1},
		{4, 1, 0, 0, 0, 1}, },
	{ /* 2N */
		{10, 5, 1, 0, 0, 0},
		{2, 3, 1, 1, 1, 0},
		{4, 1, 0, 0, 1, 0},
		{5, 0, 0, 0, 1, 0},
		{6, 0, 0, 0, 1, 0},
		{6, 5, 0, 0, 1, 0},
		{7, 2, 0, 0, 1, 0},
		{8, 1, 0, 0, 1, 0},
	}
};

const struct dll_setting default_ddr3_1333_ctrl[2][7] = {
	{ /* 1N */
		{8, 5, 0, 0, 0, 0},
		{9, 0, 1, 0, 0, 0},
		{10, 2, 1, 0, 0, 0},
		{0, 0, 1, 1, 0, 0},
		{9, 0, 1, 0, 0, 0},
		{10, 4, 1, 0, 0, 0},
		{10, 4, 1, 0, 0, 0}, },
	{ /* 2N */
		{1, 6, 1, 1, 0, 0},
		{2, 2, 1, 1, 0, 0},
		{4, 2, 0, 0, 0, 0},
		{3, 1, 1, 1, 0, 0},
		{2, 2, 1, 1, 0, 0},
		{4, 5, 0, 0, 0, 0},
		{4, 5, 0, 0, 0, 0}, }
};

const struct dll_setting default_ddr3_1333_dqs[2][TOTAL_BYTELANES] = {
	{ /* 1N */
		{2, 4, 1, 1, 1, 0},
		{5, 1, 0, 0, 1, 0},
		{6, 6, 0, 0, 1, 0},
		{8, 0, 0, 0, 1, 0},
		{8, 6, 0, 0, 1, 0},
		{9, 5, 1, 0, 1, 0},
		{10, 6, 1, 0, 1, 0},
		{0, 1, 1, 1, 0, 1}, },
	{ /* 2N */
		{10, 4, 0, 0, 0, 0},
		{0, 3, 1, 1, 1, 0},
		{3, 2, 1, 1, 1, 0},
		{5, 0, 0, 0, 1, 0},
		{6, 1, 0, 0, 1, 0},
		{7, 4, 0, 0, 1, 0},
		{9, 2, 0, 0, 1, 0},
		{9, 6, 0, 0, 1, 0}, }
};

const struct dll_setting default_ddr3_1333_dq[2][TOTAL_BYTELANES] = {
	{ /* 1N */
		{6, 5, 0, 0, 1, 0},
		{9, 3, 1, 0, 1, 0},
		{0, 2, 1, 1, 0, 1},
		{1, 0, 1, 1, 0, 1},
		{2, 0, 1, 1, 0, 1},
		{2, 5, 1, 1, 0, 1},
		{3, 2, 0, 0, 0, 1},
		{4, 1, 0, 0, 0, 1}, },
	{ /* 2N */
		{1, 3, 1, 1, 1, 0},
		{5, 6, 0, 0, 1, 0},
		{8, 5, 0, 0, 1, 0},
		{10, 2, 0, 0, 1, 0},
		{11, 1, 0, 0, 1, 0},
		{12, 3, 1, 0, 1, 0},
		{13, 6, 1, 0, 1, 0},
		{0, 3, 1, 1, 0, 1}, }
};
