/* 	Copyright 2025 Dorian Bell Jr.
	Licensed under the Apache License, Version 2.0.
	See LICENSE and NOTICE files for full details.
*/

#pragma once
#include "../include/cpps/String.h"
#include "../include/cpps/detail/alias.h"

// Definition of the cpps::String clas

/*  Recall the std nicknames (defined in String.h)
	std::string = string
	std::string_view = view
	std::size_t = size_t
*/

// ============== Constructors & Destructor =================
namespace cpps
{
	using namespace detail::alias;

	String::String()
		: text("")
	{ }

	String::String(const String* rhs)
		: text("")
	{
		if (rhs)
		{
			text = rhs->text;
		}
	}

	String::String(const String& rhs)
		: text(rhs)
	{ }

	String::String(String&& rhs) noexcept
		: text(std::move(rhs.text))
	{ }

	String::String(const view text)
		: text(text)
	{ }

	String::String(const char* lit) noexcept
		: String(std::string_view(lit)) { }

	explicit String::String(std::string&& text) noexcept
		: text(std::move(text))
	{ }



	// =============== Operator Overloads =================
	// =============== ASSIGNMENT =================
	String& String::operator=(String&& rhs)
	{
		text = std::move(rhs);
		return *this;
	}

	String& String::operator=(const String& rhs) { }

	String& String::operator=(std::string_view rtext) { }

	String& String::operator=(char symbol) { }


	// =============== EQUIVALENCE =================
	bool String::operator == (String& rhs) const noexcept
	{
		// Check for shared occupation in memory
		if (this == std::addressof(rhs)) { return true; }
		return text == rhs.text;
	}

	bool String::operator == (std::string_view rtext) const noexcept
	{
		return text == rtext;
	}

	bool String::operator == (char symbol) const noexcept
	{
		if (text.length() == 1)
		{
			return text[0] == symbol;
		}
		return false;
	}


	// =============== NON-EQUIVALENCE =================
	bool String::operator != (String& rhs) const noexcept
	{
		return !(*this == rhs);
	}

	bool String::operator != (std::string_view rtext) const noexcept
	{
		return !(*this == rtext);
	}

	bool String::operator != (char symbol) const noexcept
	{
		return !(*this == symbol);
	}


	// =============== INDEXING =============
	char& String::operator[](size_t index)
	{
		if (index < text.length())
		{
			return text[index];
		}

		throw std::out_of_range("invalid index");
	}

	// make Nullor<char>
	char String::operator[](size_t index) const
	{

	}


	// =============== CONCAT =================
	String String::operator+(const String& rhs) const
	{
		// Call this->Std() to explictly convert String -> std::string
		string newText = this->Std();
		newText.append(rhs.text);
		return String(newText);
	}

	String String::operator+(const std::string_view rhs) const
	{
		String newString(this);
		newString.Concat(rhs);
		return newString;
	}

	String String::operator+(const char symbol) const noexcept
	{
		string newText = text + symbol;
		return String(newText);
	}


	// =============== MUTATING CONCAT =================
	String& String::operator +=(String& rhs) noexcept
	{
		text += rhs.text;
		return *this;
	}

	String& String::operator +=(std::string_view rtext) noexcept
	{
		text += rtext;
		return *this;
	}

	String& String::operator +=(char symbol) noexcept
	{
		text += symbol;
		return *this;
	}


	// =============== SELF-CONCAT =================
	String String::operator*(size_t n) const noexcept
	{
		if (n == 0) { return String(""); }

		std::string newText;
		newText.reserve(text.size() * n);

		for (size_t i = 0; i < n; ++i) {
			newText += text;
		}

		return String(newText);
	}


	String& String::operator *=(const size_t n)
	{
		if (n == 0) { text.clear(); return *this; }

		std::string original = text;
		text.reserve(original.size() * n);

		for (size_t i = 1; i < n; ++i) {
			text += original;
		}
		return *this;
	}


	// =============== Conversion Methods ===============

	String::operator std::string_view() const noexcept
	{
		return text;
	}

	std::string_view String::View() const noexcept
	{
		return text;
	}

	std::string String::Std() const noexcept
	{
		return text;
	}

	// =============== Character Queries ===============

	// TODO: make nullor<char>
	char String::At(size_t index) const noexcept
	{
		// return Nullor<char>(text[index], index < text.length());
	}

	constexpr int String::Asc(size_t index) const noexcept
	{
		return static_cast<int>(text[index]);
	}

	int String::Find(char target) const noexcept
	{
		for (size_t i : text)
		{

		}
	}

	int String::FindLast(char target) const noexcept
	{ }

	// =============== Substring Queries ===============

	String String::Substr(size_t start, size_t end, bool blankIfOverflow = false) const noexcept
	{ }

	String String::Segment(size_t start, size_t length, bool blankIfOverflow = false) const noexcept
	{ }

	String String::Prefix(size_t length, bool blankIfOverflow = false) const noexcept
	{ }

	String String::Suffix(size_t length, bool blankIfOverflow = false) const noexcept
	{ }



	// =============== Full-String Methods ===============

	String String::New() const noexcept
	{ }

	void String::Reverse() noexcept
	{ }


	void String::Concat(const String& rhs) const noexcept
	{ }

	void String::Concat(std::string_view rtext) const noexcept
	{ }

	void String::Concat(char symbol) const noexcept
	{ }


	void String::Append(const String& rhs) noexcept
	{ }

	void String::Append(std::string_view rtext) noexcept
	{ }

	void String::Append(char symbol) noexcept
	{ }


	void String::Prepend(const String& rhs) noexcept
	{ }

	void String::Prepend(std::string_view rtext) noexcept
	{ }

	void String::Prepend(char symbol) noexcept
	{ }



	// =============== MUTATING CONCAT =================
	String& String::operator +=(String& rhs) noexcept
	{
		text += rhs.text;
		return *this;
	}

	String& String::operator +=(std::string_view rtext) noexcept
	{
		text += rtext;
		return *this;
	}

	String& String::operator +=(char symbol) noexcept
	{
		text += symbol;
		return *this;
	}


	LexiCompare String::Compare(view rhs)
	{ }

	void String::Repeat(size_t n)
	{ }

	// =============== String Formatting ===============
	void String::Camel() noexcept
	{ }

	void String::Snake() noexcept
	{ }

	void String::Pascal() noexcept
	{ }

	void String::ApplyCase() noexcept
	{ }

	void String::ToLower() noexcept
	{ }

	void String::ToUpper() noexcept
	{ }

	void String::Trim() noexcept
	{ }

	void String::TrimStart() noexcept
	{ }

	void String::TrimEnd() noexcept
	{ }

	void String::PadStart(size_t n, char pad = ' ')
	{
		if (text.length() < n)
		{
			text.insert(0, n - text.length(), pad);
		}
	}

	void String::PadEnd(size_t n, char pad = ' ')
	{
		if (text.length() < n)
		{
			text.append(n - text.length(), pad);
		}
	}

	bool constexpr String::Includes(char target) const
	{
		for (char i : text)
		{
			if (i == target)
			{
				return true;
			}
		}
		return false;
	}

	bool constexpr String::StartsWith(std::string_view prefix) const
	{
		// This String must be >= its prefix
		if (text.length() < prefix.length()) { return false; }

		size_t myIndex, yourIndex = 0;

		// Since prefix is no longer than this, we can use it to bound the loop
		for (myIndex, yourIndex; yourIndex < prefix.length(); ++myIndex, ++yourIndex)
		{
			if (text[myIndex] != prefix[yourIndex])
			{
				return false;
			}
		}
		return true;
	}

	bool constexpr String::EndsWith(std::string_view suffix) const
	{
		// This String must be >= its suffix
		if (text.length() < suffix.length()) { return false; }

		// It's wise to iterate backwards in this case. (Source: trust me bro)
		size_t myIndex = text.length() - 1;
		size_t yourIndex = suffix.length() - 1;

		// Since suffix is no longer than this, we can use it to bound the loop
		for (myIndex, yourIndex; yourIndex >= 0; --myIndex, --yourIndex)
		{
			if (text[myIndex] != suffix[yourIndex])
			{
				return false;
			}
		}
		return true;
	}


	// =============== Deprecated Methods for STL Compatibility ===============
	std::string::iterator String::begin() { return text.begin(); }
	std::string::iterator String::end() { return text.end(); }

	const std::string::const_iterator String::begin() const { return text.begin(); }
	const std::string::const_iterator String::end() const { return text.end(); }


	// =============== Static Methods ===============
	constexpr int String::Asc(char target)
	{
		return static_cast<int>(target);
	}


}
