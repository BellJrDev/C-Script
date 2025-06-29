#pragma once
#include "dscpp/include/detail/Slice.h"

template <typename T>
using Pointer = T*;

template <typename T>
Slice::Slice(Pointer<T*> source, size_t start = 0, size_t end) 
	: 	data(source),
		startIndex(start),
		endIndex(end)
	{ }


public:
		// Publically accessible to create placeholder blank Slices
		Slice() {}