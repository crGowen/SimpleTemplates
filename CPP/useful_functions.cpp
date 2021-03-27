// EXCEPTION CATCHING required for these, these are simple-as-possible starting points

void ReadFile(char const * const path, bool binary, std::shared_ptr<char> & bufferContent, size_t & bufferSize) {
	auto mode = std::ios::in;
	if (binary) mode = std::ios::binary;
	std::ifstream iFile;

	iFile.open(path, mode);
	iFile.seekg(0, std::ios_base::end);
	bufferSize = iFile.tellg();
	bufferContent = std::make_shared<char>(bufferSize);
	iFile.seekg(0, std::ios_base::beg);
	iFile.read(bufferContent.get(), bufferSize);
	iFile.close();
}

void WriteFile(char const* const path, bool binary, std::shared_ptr<char>& bufferContent, size_t bufferSize) {
	auto mode = std::ios::out;
	if (binary) mode = std::ios::binary;
	std::ofstream oFile;
	oFile.open(path, mode);
	oFile.write(bufferContent.get(), bufferSize);
	oFile.close();
}

void Split(std::vector<std::string> & result, const std::string& input, const std::string& splitter) {

    size_t previousPos = 0;
    size_t sLen = splitter.length();
    size_t iLen = input.length();

    for (size_t i = 0; i < iLen; ) {
        if (input[i] == splitter[0] && i + sLen <= iLen && input.substr(i, sLen) == splitter) {
            if (i != previousPos) result.push_back(input.substr(previousPos, i - previousPos));
            previousPos = i + sLen;
            i += sLen;
        }
        else {
            i++;
        }
    }

    if (previousPos < input.length() - 1) result.push_back(input.substr(previousPos));
}

std::vector<std::string> Split(const std::string& input, const std::string& splitter) {
    std::vector<std::string> result;

    Split(result, input, splitter);

    return result;
}

void ReduceCharacters(std::string& input, const std::string& acceptedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\n 0123456789.,%$£^&*+-_=?!/><(){}[]'\"#~@;:") {
    size_t resPos = 0;

    for (auto i : input) {
        for (auto x : acceptedChars) {
            if (i == x) input[resPos++] = i;
        }
    }

    input.resize(resPos);
}

std::string GetReducedCharacters(const std::string& input, const std::string& acceptedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\n 0123456789.,%$£^&*+-_=?!/><(){}[]'\"#~@;:") {
    std::string result = input;

    ReduceCharacters(result, acceptedChars);

    return result;
}
