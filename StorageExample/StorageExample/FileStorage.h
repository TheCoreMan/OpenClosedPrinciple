#pragma once

#include "Buffer.h"


class FileStorage
{
public:
	FileStorage();
	virtual ~FileStorage();
	void store(const buffer& data, const std::wstring& path) const;
	std::wstring getFilePath() const;
private:
	const std::wstring STORAGE_FOLDER = L"c:\\storage\\";
};

