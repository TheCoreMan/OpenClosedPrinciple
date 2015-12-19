#pragma once

#include "Buffer.h"


class FileStorage
{
public:
	FileStorage();
	virtual ~FileStorage();
	void store(const buffer& data);
private:
	const std::wstring STORAGE_FOLDER = L"c:\\storage\\";
	std::wstring getFileName();
};

