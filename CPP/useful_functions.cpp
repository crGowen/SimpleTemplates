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
