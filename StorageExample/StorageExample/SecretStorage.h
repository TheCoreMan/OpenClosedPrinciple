#pragma once

#include "Buffer.h"
#include "InterfaceToStorage.h"


class SecretStorage : public InterfaceToStorage
{
public:
	SecretStorage();
	virtual ~SecretStorage();
	virtual void store(const buffer& data);
	std::wstring getSecretPath() const;
private:
	const std::wstring STORAGE_FOLDER = L"c:\\SECRET\\";
};

