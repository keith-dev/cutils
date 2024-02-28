/**
	@file ustring.h
	@author s22h
	@date 27 Feb 2020
	@brief A unicode-aware string
	@version 0.1.0
 */

#pragma once

#include <cstddef>
#include <memory>

namespace s22h::cutils {

class ustring {
	std::size_t size_{};	// the byte size of the buffer - 1 (excluding the NUL character)
	std::size_t length_{};	// the number of unicode characters (runes)
	std::shared_ptr<uint8_t> buffer_;	// NUL-terminated byte buffer

public:
	ustring() = default;
	~ustring() = default;

	ustring(const char *chars);
	ustring& operator=(const char *chars);

	ustring(const ustring& str) = default;
	ustring& operator=(const ustring& str) = default;

	ustring(ustring&& other);
	ustring& operator=(ustring&& other);

	bool operator==(const ustring& other) const;

	std::size_t size() const { return length_; }
	std::size_t buffer_size() const { return size_; }
	const uint8_t* c_str() const { return buffer_.get(); }
};

}  // namespace s22h::cutils
