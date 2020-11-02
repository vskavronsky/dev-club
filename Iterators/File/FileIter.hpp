#ifndef FILEITER_HPP
#define FILEITER_HPP

#include <iostream>
#include <fstream>
#include "Exceptions.hpp"

class FileIter {
    private:
        std::string m_result;
        std::ifstream m_fin;
        std::ofstream m_fout;

    public:
        FileIter(const std::string& inputFilePath, const std::string& outputFilePath);
        virtual ~FileIter();

        void write();

        void next();
        void operator++();
        void operator++(int);

        bool end() const;

        const std::string& value() const;
        const std::string& operator*() const;

};

std::ostream& operator<<(std::ostream& out, const FileIter& fileIter);

#endif // FILEITER_HPP
