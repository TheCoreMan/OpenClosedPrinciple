#pragma once

#include "Buffer.h"


class SecretStorage
{
public:
	SecretStorage();
	virtual ~SecretStorage();
	void store(const buffer& data, const std::wstring& path) const;
	std::wstring getSecretPath() const;
private:
	const std::wstring STORAGE_FOLDER = L"c:\\SECRET\\";
};

