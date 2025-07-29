#pragma once
#include <memory>
#include <concepts>


// Support smooth this[x] = RHS and LHS = this[x], using ref or val by context
namespace cpps {

	// Class Array
template <typename T> 
class Array
{
	// For this to work, I need any type T to have a default constructor I can call
	// AND I need there to be a proper destructor
	requires std::destructible && std::default_initializable<T>;

public:
	// ========== Constructors & Destructor ==========
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



	// ======== Operator Overloads ========
	/**
	 * Bracket Operator Overload.
	 * Allows client code to do assignment on Array elements (e.g. Array[0] = 5).
	 * 
	 * @see @class ElementProxy
	 * @param index Location of the element to return
	 */
	ElementProxy<T> operator[](size_t index);            
	
	/**
	 * Bracket Operator Overload. 
	 * Allows client code to retrieve the value of an Array element (e.g. int n = Array[0]).
	 * 
	 * @param index Location of the element to retireve.
	*/
	const T& operator[](size_t index) const;         

	Array<T>& operator = (const Array<T>& rhs);
	
	Array<T>& operator = (const Array<T>&& rhs);


	
	// ========== Full-Range Search ==========
	/**
	 * Verifies that the Array contains the target.
	 * 
	 * @param target The value to search for.
	 * @return The index of the first match, or -1 if not found.
	 */	
	noexcept bool Includes(const T& target) const;

	/**
	 * Searches the entire Array for the first occurrence of the target.
	 * 
	 * @param target The value to search for.
	 * @return The index of the first match, or -1 if not found.
	 */	
	noexcept int IndexOf(const T& target) const;
	
	/**
	 * Searches the entire Array for the last occurrence of the target.
	 * 
	 * @param target The value to search for.
	 * @return The index of the last match, or -1 if not found.
	 */	
	noexcept int LastIndexOf(const T& Target) const;
	



	// ========== Range Manipulation ==========
	/**
	 * Searches for the target value starting from the given position until the end.
	 * 
	 * @param target The value to search for.
	 * @param startPos The index where the search begins.
	 * @return The index of the first match, or -1 if not found.
	 */
	noexcept int FindFrom(const T& target, size_t startPos);
	
	/**
	 * Searches for the target value starting index 0 until from the given position.
	 * 
	 * @param target The value to search for.
	 * @param endPos The index where the search concludes.
	 * @return The index of the first match, or -1 if not found.
	 */
	noexcept int FindUntil(const T& target, size_t endPos) const; 

	/**
	 * Searches for the target value within the inclusive range [startPos, endPos].
	 * 
	 * @param target The value to search for.
	 * @param startPos The starting index of the search range.
	 * @param endPos The ending index of the search range.
	 * @return The index of the first match within the specified range, or -1 if not found or if the range is invalid.
	 * 
	 * @warning An invalid range will cause the function to return -1 and may generate a debug warning in development builds.
	 * @see ValidateRange() to verify the range before calling.
	 */
	noexcept int FindInRange(const T& target, size_t startPos, size_t endPos) const;

	/**
	 * Verifies whether an inclusive range [startPos, endPos] is valid for Array access.
	 * 
	 * @param startPos The starting index of the range.
	 * @param endPos The ending index of the range.
	 * @return true if startPos <= endPos and endPos < size(); otherwise false.
	 */
	noexcept bool ValidateRange(size_t startPos, size_t endPos);


	// ========== Comparisons ==========
	bool IsEquivalent(Array<T> rhs);
	bool IsEquivalent(T* rhs);
	bool IsSubarrayOf(Array<T> standard);
	bool IsSubarrayOf(T* standard);
	bool ContainsSubarray(Array<T> rhs);
	bool ContainsSubarray(T* rhs);
	bool IsPrefixOf(Array<T> standard);
	bool IsSuffixOf(Array<T> standard);



	// ========== Special Functions ==========
	/**
	 * Calls the given operation for each element within the Array.
	 * 
	 * @param operation Any callable operation compatible with std::invoke.
	 */
	template<typename Func>
	void ForEach(Func&& operation);

	/**
	 * Calls the given operation for each element within the Array.
	 * 
	 * @param operation A const callable operation, compatible with std::invoke.
	 */
	template<typename Func>
	void ForEach(Func&& operation) const;
	
	/**
	 * Generates a delimeted string representation of the Array elements. 
	 * The default delimiter is a comma ','. 
	 * 
	 * @param delim string delimiter.
	 * @return 
	 */
	std::string Join() const;
	
	/**
	 * Verifies whether an inclusive range [startPos, endPos] is valid for Array access.
	 * 
	 * @param startPos The starting index of the range.
	 * @param endPos The ending index of the range.
	 * @return true if startPos <= endPos and endPos < size(); otherwise false.
	 */
	std::string Print() const;
	
	/**
	 * Verifies whether an inclusive range [startPos, endPos] is valid for Array access.
	 * 
	 * @param startPos The starting index of the range.
	 * @param endPos The ending index of the range.
	 * @return true if startPos <= endPos and endPos < size(); otherwise false.
	 */
	std::string ToJSON() 

	/**
	 * Reverses the 
	 * 
	 * @param startPos The starting index of the range.
	 * @param endPos The ending index of the range.
	 * @return true if startPos <= endPos and endPos < size(); otherwise false.
	 */
	void Reverse();

	

	// ========== Copy & Clone ==========
	Array<T> Clone()
	T* CloneAsPrimitive(); 
	const Array<T> CloneAsReverse();
	Array<T>& Concatenate(Array<T>& suffix); 
	Slice<T> CutSlice(size_t start = 0);
	Slice<T> CutSlice(size_t start = 0, size_t end);
	

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
}

#include "include/detail/Array.ipp";