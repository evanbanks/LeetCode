class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(const vector<string>& strs) {
        std::string encoded;
        for (int i=0; i<strs.size(); ++i){
            std::string length = std::to_string(strs[i].size());
            while (length.size() !=3 ) length += "*";
            encoded += length;
            encoded += strs[i];
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(const string& s) {
        std::vector<string> decoded;
        for (int i=0, j=0; i<s.size(); ++i){
            std::string length;
            for (; i<j+3; ++i) if (std::isdigit(s[i])) length += s[i];
            int l = std::stoi(length);
            decoded.push_back(s.substr(i,l));
            i += l-1;
            j = i+1;
        }
        return decoded;
    }
};
