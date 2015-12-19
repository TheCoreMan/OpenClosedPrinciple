#pragma once

#include "InterfaceToStorage.h"


class FileStorage : public InterfaceToStorage
{
public:
	FileStorage();
	virtual ~FileStorage();
	virtual void store(const buffer& data);
	std::wstring getFilePath() const;
private:
	const std::wstring STORAGE_FOLDER = L"c:\\storage\\";
};

