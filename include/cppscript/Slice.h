#pragma once

template <typename T>
class Slice {
public:
	using value_type = T;
    using pointer = T*;
    using reference = T&;
    using const_reference = const T&;
    using iterator = T*;
    using const_iterator = const T*;

	// Publically accessible to create placeholder blank Slices
	Slice();
	Slice(T* source, size_t start = 0, size_t end); // Will update this to support various source containers
	~Slice();


	Length() const;
	IsEmpty() const;
	Data() const;
	Start() const;
	End() const;
	operator[].

	void Reslice();
	void Travserse(Iterator<Slice> iter); 

You might want to add const_iterator versions of begin() and end() if not already there.

private:
	T* data = undefined;
	size_t length = 0;
	size_t startIndex = 0;
	size_t endIndex = 0;

	void Clear();
};