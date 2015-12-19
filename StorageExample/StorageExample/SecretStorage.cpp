#include "SecretStorage.h"

#include <fstream>
#include <random>
#include <string>
#include <time.h>
#include <Windows.h>


SecretStorage::SecretStorage()
{
	auto retVal = ::CreateDirectoryW(
		STORAGE_FOLDER.data(),	// Create the directory in this path.
		NULL);					// Security attribs (NULL == default).

	if (0 != retVal) {
		auto lastError = ::GetLastError();
		if (ERROR_ALREADY_EXISTS != lastError) {
			throw std::exception("Failed to create storage directory. Error: {0}", retVal);
		}
	}
}


SecretStorage::~SecretStorage()
{
}

std::wstring SecretStorage::getSecretPath() const
{
	return std::wstring(this->STORAGE_FOLDER + std::to_wstring(rand()) + L".storageSecret");
}

void SecretStorage::store(const buffer& data, const std::wstring& path) const
{
	std::wofstream output;
	output.open(path);
	output << data[0];
	output.close();
}
