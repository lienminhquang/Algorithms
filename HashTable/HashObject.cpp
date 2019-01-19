#include "stdafx.h"
#include "HashObject.h"


HashObject::HashObject()
{
	_key = HashObject::getNullKey();
	_value = "";
}


HashObject::~HashObject()
{
}

std::string HashObject::getNullKey()
{
	return "NULL_KEY";
}

std::string HashObject::getDummyKey()
{
	return "DUMMY_KEY";
}

const std::string & HashObject::getKey() const
{
	return _key;
}

const std::string & HashObject::getValue() const
{
	return _value;
}

void HashObject::setKey(const std::string & key)
{
	_key = key;
}

void HashObject::setValue(const std::string & value)
{
	_value = value;
}
