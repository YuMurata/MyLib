#pragma once

#include"Split.h"

#if defined(UNICODE) || defined(_UNICODE)
#define Split SplitA;
#else
#define Split SplitW;
#endif

