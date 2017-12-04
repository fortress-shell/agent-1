//
// Copyright (c) 2017 Intel Corporation
//
// SPDX-License-Identifier: Apache-2.0
//

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void sigdown(int signo) {
	psignal(signo, "shutting down, got signal");
	exit(0);
}

int main() {
	if (signal(SIGINT, sigdown) == SIG_ERR)
		return 1;

	if (signal(SIGTERM, sigdown) == SIG_ERR)
		return 2;

	for (;;) pause();

	fprintf(stderr, "error: infinite loop terminated\n");
	return 42;
}
