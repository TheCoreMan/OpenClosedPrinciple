#include <iostream>
#include <fstream>
#include <vector>


typedef std::vector<char> buffer;

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

void store(const buffer& data) {
	std::cout << data.data() << std::endl;
}

int main() {
	auto dataToStore = getFileData(L"C:\\important.txt");
	store(dataToStore);

	return 0;
}