#pragma once
#include <string>  // for std::string
#include <cstdlib> // for std::size_t

namespace cpps
{
	// Just for my convenience
	using string = std::string;
	using view = std::string_view;
	using size_t = std::size_t;

	enum class LexiCompare : int
	{
		Before = -1,
		Same = 0,
		After = 1
	};
	enum class NumCompare : int
	{
		Less = -1,
		Equal = 0,
		More = 1
	};

	/**
	 * @class String
	 * @brief A super lightweight wrapper around std::string.
	 * Offers a more ergonomic interface + convenient methods.
	 */
	class String
	{
	protected:
		std::string text;

	public:
		// =============== Constructors & Destructor =================

		/// @brief Nullary Constructor
		String();

		/// @brief Copy Constructor
		/// @param rhs the String to copy
		String(const String &rhs) noexcept;

		/// @brief Move Coonstructor
		/// @param rhs the String to move
		String(String &&rhs) noexcept;

		/**
		 * Copy Constructor II
		 *
		 * Copies from a std::string_view
		 *
		 * @param text source data
		 */
		String(const std::string_view text) noexcept;

		/**
		 * Initializing Move Constructor
		 *
		 * Moves source data from a std::string to this String
		 *
		 * @param text source data
		 */
		String(std::string &&text) noexcept;

		// =============== Operator Overloads =================

		/**
		 * Move Assignment enabled.
		 *
		 * @param rhs the String to move.
		 * @returns this String with the modification done.
		 */
		String &String::operator=(String &&rhs);

		/**
		 * Assignment from std::string enabled.
		 *
		 * @param rhs the new contents for this String.
		 * @returns
		 */
		String &String::operator=(std::string_view rhs);

		/**
		 * Overloaded + for Concatenation Operator. (I)
		 * Concatenates this String with rhs, in a new object.
		 *
		 * @param rhs a String to append onto this String
		 * @returns a new String object with the result
		 */
		String operator+(const String &rhs) const;

		/**
		 * Overloaded + for Concatenation Operator. (II)
		 * Concatenates this String with rhs, in a new object.
		 *
		 * @param rhs a std::string_view to append onto this String
		 * @returns a new String object with the result
		 */
		String operator+(const std::string_view rhs) const;

		/**
		 * Overloaded [] for char access.
		 * Returns the char at the specified index.
		 *
		 * @param index the index of the desired character
		 * @returns the char at the index
		 */
		char &operator[](size_t index);

		/**
		 * Overloaded [] for char access.
		 * Returns the char at the specified index.
		 *
		 * @param index the index of the desired character
		 * @returns a copy of the char at the index
		 */
		char operator[](size_t index) const;

		// =============== Conversion Methods ===============

		/// @brief Implicit conversion TO std::string_view
		/// @returns A std::string_view object
		operator std::string_view() const noexcept;

		/**
		 * Converts String to std::string_view.
		 *
		 * Returns the underlying text of this String as a new std::string_view.
		 *
		 * @returns A std::string_view object.
		 * @warning The std::string_view is only valid until this String is mutated
		 */
		std::string_view View() const noexcept;

		/**
		 * Converts String to std::string.
		 *
		 * @returns the text of this String, stored in a new std::string
		 */
		std::string Std() const noexcept;

		// =============== Character Queries ===============

		/**
		 * Gives the value of the char at the specified index.
		 *
		 * @param index an index within this String
		 * @return the text of this String, stored in a new std::string
		 */
		char CharAt(size_t index) const noexcept;

		/**
		 * Returns the ASCII code associated with the target char.
		 *
		 * @note Non-ASCII characters return -1.
		 * @param target the char to convert to ASCII
		 * @return an ASCII code or -1
		 */
		static constexpr int Asc(char target);

		/**
		 * Returns the ASCII code of the char at the specified index
		 * within the String.
		 *
		 * @note Non-ASCII characters return -1.
		 * @param index an index within this String
		 * @return an ASCII code or -1
		 */
		constexpr int Asc(size_t index) const;

		/**
		 * Returns the index at which the target char first appears.
		 * If the specified char is not found, it returns -1.
		 *
		 * @param target the char to find
		 * @return the first index where the target appears, or -1.
		 */
		int Find(char target) const noexcept;

		/**
		 * Returns the last index at which the target char appears.
		 * If the specified char is not found, it returns -1.
		 *
		 * @param target the char to find
		 * @return the last index where the target appears, or -1.
		 */
		int FindLast(char target) const noexcept;

		// =============== Substring Queries ===============

		/**
		 * Makes a new String from an inclusive range within this String.
		 *
		 * @note Overflow: when `end` exceeds this String's length.
		 * @note Bad range: when `start > end`.
		 *
		 * @warning Bad range returns an empty String.
		 * @warning Overflow truncates by default, but can be toggled.
		 *
		 * @param start Inclusive start index.
		 * @param end Inclusive end index.
		 * @param blankIfOverflow If true, overflow returns a blank String; otherwise, it truncates.
		 * @returns A new String object.
		 */
		String Substr(size_t start, size_t end, bool blankIfOverflow = false) const noexcept;

		/**
		 * Makes a new String from a segment of this String.
		 *
		 * Similar to Prefix/Suffix, but with a variable start index.
		 *
		 * @warning Overflow truncates by default, but can be toggled.
		 *
		 * @param start Inclusive start index.
		 * @param length Number of characters in the desired segment.
		 * @param blankIfOverflow If true, overflow returns a blank String; otherwise, it truncates.
		 * @returns A new String object.
		 */
		String Segment(size_t start, size_t length, bool blankIfOverflow = false) const noexcept;

		/**
		 * Makes a new String containing the prefix of this String.
		 *
		 * @warning Overflow truncates by default, but can be toggled.
		 *
		 * @param length Number of characters in the desired prefix.
		 * @param blankIfOverflow If true, overflow returns a blank String; otherwise, it truncates.
		 * @returns A new String object.
		 */
		String Prefix(size_t length, bool blankIfOverflow = false) const noexcept;

		/**
		 * Makes a new String containing the suffix of this String.
		 *
		 * @warning Overflow truncates by default, but can be toggled.
		 *
		 * @param length Number of characters in the desired suffix.
		 * @param blankIfOverflow If true, overflow returns a blank String; otherwise, it truncates.
		 * @returns A new String object.
		 */
		String Suffix(size_t length, bool blankIfOverflow = false) const noexcept;

		// =============== Full-String Methods ===============

		/**
		 * Creates a new stack-allocated String (deep copy).
		 *
		 * @note
		 * Use this to apply transformations (e.g., casing or reversing)
		 * without modifying the original instance.
		 * @note
		 * Mutating methods affect the returned copy -- not the original.
		 * @note
		 * Example : String.New().Reverse().Camel();
		 *
		 * @returns A new, independent copy of this String.
		 */
		String New() const noexcept;

		/**
		 * Reverses the order of characters within this String.
		 *
		 * @note
		 * Example : "dorian" --> "nairod"
		 */
		void Reverse() noexcept;

		/**
		 * Appends the provided String onto this one.
		 *
		 * @param newSuffix the text to append to this String
		 */
		void Concat(view newSuffix) noexcept;

		/**
		 * Does a lexical compare between this String and rhs.
		 * This String is either lexically before, after, or the same as rhs.
		 *
		 * @note The comparison is relative to THIS String.
		 * @note "abc" --> "cba"
		 * @return 1 = comes after, 0 = same, -1 = comes before
		 */
		LexiCompare Compare(view rhs);

		/**
		 * Self-Appends this String n times.
		 *
		 * @note Example : String("Segfault").Repeat(2) --> "SegfaultSegfault"
		 */
		void Repeat(size_t n);

		// =============== String Formatting ===============
		/**
		 * Attempts to convert this String into camelCase formatting.
		 * @note Example : "some phrase" --> "somePhrase"
		 */
		void Camel() noexcept;

		/**
		 * Attempts to convert this String into snake_case formatting.
		 *
		 * @note Example : "some phrase" --> "some_phrase"
		 */
		void Snake() noexcept;

		/**
		 * Attempts to convert this String into PascalCase formatting.
		 *
		 * @note Example : "some phrase" --> "SomePhrase"
		 */
		void Pascal() noexcept;

		/**
		 * Attempts to apply the specified case scheme to this String.
		 *
		 * @note Options : Camel | Pascal | Snake | Upper | Lower
		 * @note Example : some phrase --> somePhrase
		 */
		void ApplyCase() noexcept;

		// Maybe add a static void overload taking std::string_view param?

		/**
		 * Makes the alphabetical characters in this String lowercase.
		 *
		 */
		void ToLower() noexcept;

		/**
		 * Makes the alphabetical characters in this String uppercase.
		 *
		 */
		void ToUpper() noexcept;

		/**
		 * Removes leading and trailing spaces from this String.
		 *
		 * @note Example : "  hello word  " --> "hello world"
		 */
		void Trim() noexcept;

		/**
		 * Removes leading spaces from this String.
		 *
		 * @note Example : "  hello world  " --> "hello world  "
		 */
		void TrimStart() noexcept;

		/**
		 * Removes trailing spaces from this String.
		 *
		 * @note Example : "  hello world  " --> "  hello world"
		 */
		void TrimEnd() noexcept;

		/**
		 * Pads the start of this String with n instances of the pad char.
		 *
		 * @param n the number of pad characters to prepend to this String.
		 * @param pad the character to pad this String with.
		 */
		void PadStart(size_t n, char pad = ' ');

		/**
		 * Pads the end of this String with n instances of the pad char.
		 *
		 * @param n the number of pad characters to append to this String.
		 * @param pad the character to pad this String with.
		 */
		void PadEnd(size_t n, char pad = ' ');

		/**
		 * Determines if the target char exists within this String.
		 *
		 * @param target the character to look for
		 * @returns true if the target exists in this String.
		 */
		bool constexpr Includes(char x) const;

		/**
		 * Determines if this String begins with the given prefix.
		 *
		 * @note Example : "Hel" is a valid prefix of "Hello World!".
		 *
		 * @param prefix The potential prefix of the String
		 * @returns true if this String begins with the same chars as prefix.
		 */
		bool constexpr StartsWith(std::string_view prefix) const;

		/**
		 *  Determines if this String ends with the given suffix.
		 *
		 * @note Example: "ld!" is a valid suffix of "Hello World!".
		 */
		bool constexpr EndsWith(std::string_view suffix) const; //(simple boundary checks)

		/*
			Future: Match, Search, Replace
		*/
	};
}