#include "FileIter.hpp"

FileIter::FileIter(const std::string& inputFilePath, const std::string& outputFilePath) {
    m_fin.open(inputFilePath);

    if ( !m_fin.is_open() ) {
        throw ReadError();
    } else {
        std::getline(m_fin, m_result);
    }

    m_fout.open(outputFilePath);
}

FileIter::~FileIter() {
    m_fin.close();
    m_fout.close();
}

void FileIter::write() {
    m_fout << m_result;
    m_fout << std::endl;
}

void FileIter::next() {
    if ( end() ) {
        return;
    }
    std::getline(m_fin, m_result);
}

void FileIter::operator++() {
    next();
}

void FileIter::operator++(int) {
    operator++();
}

bool FileIter::end() const {
    return m_fin.eof();
}

const std::string& FileIter::value() const {
    return m_result;
}

const std::string& FileIter::operator*() const {
    return value();
}

std::ostream& operator<<(std::ostream& out, const FileIter& fileIter) {
    return out << *fileIter;
}
