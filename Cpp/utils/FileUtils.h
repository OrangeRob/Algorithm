#ifndef __FILEUTILS_H__
#define __FILEUTILS_H__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace FileUtils {

    int firstCharacterIndex(const std::string& s, int start) {
        for( int i = start ; i < s.length() ; i ++ )
            if( isalpha(s[i]) )
                return i;
        return s.length();
    }

    std::string lowerString(const std::string& s) {
        std::string ret = "";
        for( int i = 0 ; i < s.length() ; i ++ )
            ret += tolower(s[i]);
        return ret;
    }

    bool readFile(const std::string& filePath, std::vector<std::string>& words) {
        /* load file */
        std::string line;
        std::string contents = "";
        std::ifstream file(filePath);
        if(file.is_open()) {
            while(getline(file, line))
                contents += (line + "\n");
            file.close();
        } else {
            std::cout << "can't open " << filePath << "!" << std::endl;
            return false;
        }

        int start = firstCharacterIndex(contents, 0);
        for( int i = start + 1 ; i <= contents.length() ; ) {
            if( i == contents.length() || !isalpha(contents[i]) ) {
                words.push_back(lowerString(contents.substr(start, i - start)) );
                start = firstCharacterIndex(contents, i);
                i = start + 1;
            }
            else
                i++;
        }
        return true;
    }

} // namespace FileUtils

#endif //__FILEUTILS_H__
