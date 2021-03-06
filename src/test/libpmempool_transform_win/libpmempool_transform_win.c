// SPDX-License-Identifier: BSD-3-Clause
/* Copyright 2016-2018, Intel Corporation */

/*
 * libpmempool_transform_win -- a unittest for libpmempool transform.
 *
 */

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "unittest.h"

int
wmain(int argc, wchar_t *argv[])
{
	STARTW(argc, argv, "libpmempool_transform_win");
	if (argc != 4)
		UT_FATAL("usage: %s poolset_in poolset_out flags",
			ut_toUTF8(argv[0]));

	int ret = pmempool_transformW(argv[1], argv[2],
			(unsigned)wcstoul(argv[3], NULL, 0));

	if (ret)
		UT_OUT("result: %d, errno: %d", ret, errno);
	else
		UT_OUT("result: 0");

	DONEW(NULL);
}
