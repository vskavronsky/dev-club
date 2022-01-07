/*
 * coder.cpp
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: vitalii.lysenko
 *
 * Coder class source.
 *
 * You may have to change this file to fix build errors, and make
 * the unit tests pass.
 *
 * Usually source files are used to write an implementation of
 * global and member functions.
 *
 */

/*
 * To make all unit tests pass you may try to puzzle out the ::encode() algorithm
 * and it should help you to write the decoding one. But there are other ways to
 * make them pass.
 *
 * Good luck!
 *
 */

#include "coder.h"

char* tmp_buf = nullptr;
unsigned int tmp_size = 0;
Coder* tmp_coder = nullptr;

void encode(const char* buf, unsigned int size )
{
    if ( tmp_coder->buf() == NULL )
    {
        tmp_coder->set(buf, size);
    }
}

Coder::Coder() : m_buf(nullptr), m_size(0) {}

Coder::Coder( const Coder& other ) : m_buf(nullptr), m_size(0)
{
    if ( other.m_size > 0 )
    {
        m_buf = new char[other.m_size];
        std::copy(other.m_buf, other.m_buf + other.m_size, m_buf);
        m_size = other.m_size;
    }
}

Coder::~Coder()
{
    m_size = 0;
    delete[] m_buf;
    m_buf = nullptr;

    tmp_size = 0;
    delete[] tmp_buf;
    tmp_buf = nullptr;

    tmp_coder = nullptr;
}

void Coder::set( const char* buf, unsigned int size )
{   
    constexpr unsigned int lower_limit = 1;
    constexpr unsigned int higher_limit = std::numeric_limits<unsigned int>::max() - 1;
    
    if ( size < lower_limit || size > higher_limit )
    {
        throw std::logic_error("incorrect buf size!");
    }

    m_buf = new char[size];
    m_size = size;
    
    if ( buf != NULL ) {
        std::memcpy(m_buf, buf, size);
    }
    else
    {
        throw std::logic_error("buf points to NULL!");
    }
}

const char* Coder::buf() const
{
    return m_buf;
}

unsigned int Coder::size() const
{
    return m_size;
}

void Coder::encode()
{
    tmp_buf = new char[m_size];
    tmp_size = m_size;
    std::copy(m_buf, m_buf + m_size, tmp_buf);

    delete[] m_buf;
    m_buf = nullptr;

    tmp_coder = this;
}

void Coder::decode()
{
    if ( this->buf() == NULL)
    {
        this->set(tmp_buf, tmp_size);
    }
}

Coder& Coder::operator=( const Coder & other )
{
    if ( this == &other )
    {
        return *this;
    }

    if ( this->m_size != other.m_size )
    {
        delete[] m_buf;
        m_buf = nullptr;
        m_size = 0;
        m_buf = new char[other.m_size];
        m_size = other.m_size;
    }

    std::copy(other.m_buf, other.m_buf + other.m_size, m_buf);

    return *this;
}
