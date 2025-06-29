
#pragma once

#include <memory>
#include <concepts>


class Int
{
private:
	int* data = nullptr;

public:
	Int() : data(0) {}
	Int(int number) : data(new int(number)) {}
}




template <typename T> 
class Array
{
	// For this to work, I need any type T to have a default constructor I can call
	// AND I need there to be a proper destructor
	requires std::destructible && std::default_initializable<T>;
public:
	/**
	* Initializing constructor I

	* @param	capacity number of elements the Array can hold
	*/
	Array(size_t capacity);

	/**
	* Initializing constructor II
	* 
	* @param	capacity - number of elements the Array can hold
	* @param	source - data to deep copy into this Array
	*/
	Array(size_t capacity, T* source);

	/// Copy constructor
	Array(const Array<T>& rhs);

	/// Move constructor
	Array(const Array<T>&& rhs);
	
	/// Destructor
	~Array();

	/**
	 * Bracket Operator Overload.
	 * Allows client code to do assignment on Array elements (e.g. Array[0] = 5).
	 * 
	 * @see @class ElementProxy
	 * @param index Location of the element to return
	 */
	ElementProxy<T> operator[](size_t index);             // non-const
	
	/**
	 * Bracket Operator Overload. 
	 * Allows client code to retrieve the value of an Array element (e.g. int n = Array[0]).
	 * 
	 * @param index Location of the element to retireve.
	*/
	const T& operator[](size_t index) const;         

	
	Array<T>& operator = (const Array<T>& rhs);
	Array<T>& operator = (const Array<T>&& rhs);
	bool operator != (const Array<T>& rhs) const;

	bool IsEquivalent(Array<T> rhs);
	bool IsEquivalent(T* rhs);
	bool IsSubarrayOf(Array<T> standard);
	bool IsSubarrayOf(T* standard);
	bool Includes(T target);


	bool ContainsSubarray(Array<T> rhs);
	bool ContainsSubarray(T* rhs);
	bool IsPrefixOf(Array<T> standard);
	bool IsSuffixOf(Array<T> standard);
	int FirstIndexOf(T target) const;
	int LastIndexOf(T target) const;
	int IndexOf(T target) const;

	Array<T>& Concatenate(Array<T>& suffix); 

	std::string Join() const;
	std::string ToString() const;

	
	T* DeepCopy_AsPrimitive();
	Array<T> DeepCopy();
	void Reverse();
	Array<T> ReverseClone();
	Slice<T> TakeSlice(size_t start = 0);
	Slice<T> TakeSlice(size_t start = 0, size_t end);
	Slice<T> CreateSlice(Pointer<T*> source, size_t start = 0, size_t end);
	
	Iterator<Array,T> Iterator();

protected:
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
	};

private:
	using Unique = std::unique_ptr<T>;
	Unique<T[]> data = undefined;
	size_t length;
	
};

#include "include/detail/Array.ipp";