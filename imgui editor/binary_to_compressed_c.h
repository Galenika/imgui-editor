#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned int stb_uint;
typedef unsigned char stb_uchar;
stb_uint stb_compress(stb_uchar* out, stb_uchar* in, stb_uint len);

bool binary_to_compressed_c(const char* filename, const char* symbol, bool use_base85_encoding, bool use_compression);