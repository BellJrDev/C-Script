/* 	Copyright 2025 Dorian Bell Jr.
	Licensed under the Apache License, Version 2.0.
	See LICENSE and NOTICE files for full details.
*/

#pragma once
#include "../String.h"

namespace cpps
{
	/*  Recall the std nicknames (defined in String.h)
		std::string = string
		std::string_view = view
		std::size_t = size_t
	*/

	// ============== Constructors & Destructor =================
	String::String()
		: text("")
	{ }

	String::String(const String& rhs)
		: text(rhs)
	{ }

	String::String(String&& rhs) noexcept
		: text(std::move(rhs.text))
	{ }

	String::String(const view text)
		: text(text)
	{ }

	String::String(std::string&& text) noexcept
		: text(std::move(text))
	{ }
	// =============== Operator Overloads =================
	String& String::operator=(String&& rhs)
	{ }

	String String::operator+(const String& rhs) const
	{ }

	String String::operator+(const std::string_view rhs) const
	{ }

	char& String::operator[](size_t index)
	{ }

	char String::operator[](size_t index) const
	{ }

	// =============== Conversion Methods ===============

	String::operator std::string_view() const noexcept
	{ }

	std::string_view String::View() const noexcept
	{ }

	std::string String::Std() const noexcept
	{ }

	// =============== Character Queries ===============

	char String::CharAt(size_t index) const noexcept
	{ }

	constexpr int String::Asc(size_t index) const noexcept
	{ }

	int String::Find(char target) const noexcept
	{ }

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

	void String::Concat(view newSuffix) noexcept
	{ }

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
	{ }

	void String::PadEnd(size_t n, char pad = ' ')
	{ }

	bool constexpr String::Includes(char x) const
	{ }

	bool constexpr String::StartsWith(std::string_view prefix) const
	{ }

	bool constexpr String::EndsWith(std::string_view suffix) const
	{ }

	// =============== Static Methods ===============

	constexpr int String::Asc(char target)
	{ }
};
