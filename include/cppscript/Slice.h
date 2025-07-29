#pragma once

namespace cpps {

// Class Slice<T>
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
	//void Travserse(Iterator<Slice> iter); ... Ignoreing advice to use plain iterators. I don't like them.

private:
	T* data = undefined;
	size_t length = 0;
	size_t startIndex = 0;
	size_t endIndex = 0;

	void Clear();
};
}


/**
 * @class Iterator
 *
 * Pure virtual (interface) for all class-specific derived iterators
 */

/**
template <typename T>
class Iterator
{
public:
	virtual bool IsDone(void) = 0;
	virtual void Advance(void) = 0;
	virtual T Current() = 0;
};
*/