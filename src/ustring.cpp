/**
	@file ustring.c
	@author s22h
	@date 27 Feb 2020
	@brief A unicode-aware string
	@version 0.1.0
 */

#include "ustring.h"
#include "unicode.h"

namespace s22h::cutils {

ustring::ustring(const char *chars) {
	length_ = utf8_strlen((uint8_t*) chars, &size_);
	buffer_ = std::make_shared<uint8_t>(size_ + 1);
	buffer_.get()[size_] = 0;
	memcpy(buffer_.get(), chars, size_);
}

ustring& ustring::operator=(const char *chars) {
	length_ = utf8_strlen((uint8_t*) chars, &size_);
	buffer_ = std::make_shared<uint8_t>(size_ + 1);
	buffer_.get()[size_] = 0;
	memcpy(buffer_.get(), chars, size_);

	return *this;
}

ustring::ustring(ustring&& other) {
	length_ = other.length_;
	size_ = other.size_;
	buffer_ = other.buffer_;

	other.length_ = other.size_ = 0;
	other.buffer_.reset();
}

ustring& ustring::operator=(ustring&& other) {
	if (this != &other) {
		length_ = other.length_;
		size_ = other.size_;
		buffer_ = std::make_shared<uint8_t>(size_ + 1);

		other.length_ = other.size_ = 0;
		other.buffer_.reset();
	}

	return *this;
}

bool ustring::operator==(const ustring& other) const {
	return
		length_ == other.length_ &&
		size_ == other.size_ &&
		((buffer_.get() && other.buffer_.get() && memcmp(buffer_.get(), other.buffer_.get(), size_) == 0) ||
		 (!buffer_.get() && !other.buffer_.get()));
}

}  // namespace s22h::cutils
