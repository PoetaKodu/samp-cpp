#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Safety/Destructible.hpp>

namespace samp_cpp
{

template <typename T>
struct Unique
{
public:
	static_assert(std::is_default_constructible_v<T>, 	"Underlying type has to be default constructible."); 
	static_assert(std::is_move_constructible_v<T>, 		"Underlying type has to be move constructible."); 
	static_assert(has_destroy_method<T>::value, 		"Underlying type has to implement \"destroy\" method."); 

	Unique() = default;
	Unique(T value_)
		:
		_hasValue(true),
		_value(std::move(value_))
	{
	}

	~Unique() {
		if (_hasValue)
			_value.destroy();
	}

	// Deleted copy constructor
	Unique(Unique<T> const& other_) = delete;
	// Deleted copy assignment operator
	Unique operator=(Unique<T> const& other_) = delete;

	Unique(Unique<T>&& other_)
		:
		_hasValue(other_._hasValue),
		_value(other_._hasValue)
	{
		other_._hasValue = false;
	}

	Unique& operator=(Unique<T>&& other_)
	{
		if(this == &other_)
			return *this;

		std::swap(other_._hasValue, _hasValue);
		std::swap(other_._value, _value);
		return *this;
	}

	Unique& operator=(T other_)
	{
		if(_hasValue && _value == other_)
			return *this;

		if(_hasValue)
			_value.destroy();

		_hasValue = true;
		_value = std::move(other_);
		return *this;
	}

	bool reset()
	{
		if (!_hasValue)
			return false;
			
		_hasValue = false;

		_value.destroy();
		return true;
	}

	T& value() { return _value; }
	T const& value() const { return _value; }

	T& operator*() { return _value; }
	T const& operator*() const { return _value; }

	T* operator->() { return &_value; }
	T const* operator->() const { return &_value; }

	bool hasValue() const {
		return _hasValue;
	}
private:
	bool _hasValue = false;
	T _value;
};

}