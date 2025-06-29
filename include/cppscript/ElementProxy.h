#pragma once

#include <memory>
#include <concepts>
class Array;

template <typename T>
class ElementProxy
{
private:
	T* ref; // Owned by Array class. ElementProxy owns no memory of its own.

	ElementProxy() = delete;

public:
	/**
	 * Initializing constructor
	 * 
	 * @param realElement A pointer to the real data being proxied
	 */
	ElementProxy(T* realElement) : ref(realElement) {}

	/**
	 * Assignment Operator Overload.
	 * Allows an ElementProxy<T> to be treated as a T during assignment, by
	 * setting the value of ref equal to T.
	 * 
	 * @param index Location of the element to return
	 */
	ElementProxy<T>& operator = (const T& rhs)
	{
		*ref = rhs;
		return *this;
	}

	/**
	 * Assignment Operator Overload.
	 * Updates the reference value (ref) of this ElementProxy using another ElementProxy<T>
	 * instead of using a raw T object.
	 * 
	 * @param rhs An ElementProxy<T> object
	 * @warning This is VALUE assignment -- not POINTER assignment.
	 * 				The ref for this ElementProxy still refers to the original memory address.
	 */
	ElementProxy<T>& operator = (const ElementProxy<T>& rhs)
	{
		if (this != &rhs)
		{
			*ref = *(rhs.ref);
		}
		
		return *this;
	}


	operator T&() const noexcept // Implicit Conversion to const T
	{
		return *ref;
	}

	friend class Array;
};