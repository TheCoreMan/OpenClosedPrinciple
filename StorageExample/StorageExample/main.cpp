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

void storeData(const buffer& data, InterfaceToStorage& storage)
{
	storage.store(data);
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

InterfaceToStorage* getCorrectStorage(ConfigurationMode::Type operatingMode) {
	switch (operatingMode)
	{
	case ConfigurationMode::REGULAR: {
										 FileStorage* storage = new FileStorage();
										 return storage;
	}
	case ConfigurationMode::SECRET: {
										SecretStorage* storage = new SecretStorage();
										return storage;
	}
	default:
		throw std::exception("Unknown operating mode.");
	}
}

int main() {
	auto dataToStore = getFileData(L"C:\\important.txt");
	
	auto operatingMode = getOperationModeFromConfiguration();
	InterfaceToStorage* correctStorage = getCorrectStorage(operatingMode);
	correctStorage->store(dataToStore);

	return 0;
}
