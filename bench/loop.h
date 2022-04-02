#pragma once
#include <immintrin.h>

#ifdef __AVX2__
#else
    #warning AVX not supported! This code will not compile
#endif

#include <array>
#include <iostream>
#include "timer.h"