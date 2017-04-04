#pragma once

#include"Split.h"

#if defined(UNICODE) || defined(_UNICODE)
#define Split(input, delim) SplitA(input,delim);
#else
#define Split(input, delim) SplitW(input,delim);
#endif

