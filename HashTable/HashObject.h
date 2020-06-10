#pragma once
#include <string>


class HashObject
{
public:
	HashObject();
	~HashObject();

	static std::string getNullKey();
	static std::string getDummyKey();

	const std::string& getKey() const;
	const std::string& getValue() const;

	void setKey(const std::string& key);
	void setValue(const std::string& value);

private:
	std::string _key;
	std::string _value;
};

