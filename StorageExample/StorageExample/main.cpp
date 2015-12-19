#include <iostream>
#include <fstream>

#include "Buffer.h"
#include "FileStorage.h"
#include "SecretStorage.h"


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

namespace ConfigurationMode {
	enum Type {
		REGULAR,
		SECRET,
		COMMUNICATION
	};
}


ConfigurationMode::Type getOperationModeFromConfiguration() {
	// imagine this is from a configuration...
	return ConfigurationMode::REGULAR;
}

int main() {
	auto dataToStore = getFileData(L"C:\\important.txt");
	
	
	auto operatingMode = getOperationModeFromConfiguration();
	switch (operatingMode)
	{
	case ConfigurationMode::REGULAR: {
										 FileStorage storage;
										 storeData(dataToStore, storage);
										 break; 
	}
		// Oh no, now we need the secret storage :(
		// Well, let's just... Copy and paste?
		// Ugh, smells horrible ...
	case ConfigurationMode::SECRET: {
										SecretStorage storage;
										// Oh no! This doesn't compile! What, should I copy this function too?
										// There must be a better way...
										storeData(dataToStore, storage);
	}
	default:
		break;
	}
	

	return 0;
}
