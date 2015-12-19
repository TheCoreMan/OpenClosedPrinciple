#include <iostream>
#include <fstream>

#include "Buffer.h"
#include "FileStorage.h"


buffer getFileData(const std::wstring& path) {
	std::streampos size;

	std::ifstream file(path, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		size = file.tellg();
		auto buf = buffer(size.operator+(1), '\0');		

		file.seekg(0, std::ios::beg);
		file.read(buf.data(), size);
		file.close();
		return buf;
	}
	throw std::exception("Unable to open file.");
}

void storeData(const buffer& data, const FileStorage& storage)
{
	auto storageFilePath = storage.getFilePath();
	storage.store(data, storageFilePath);
}

int main() {
	auto dataToStore = getFileData(L"C:\\important.txt");
	FileStorage storage;

	storeData(dataToStore, storage)

	return 0;
}
