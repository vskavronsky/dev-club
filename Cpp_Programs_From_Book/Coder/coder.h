/*
 * coder.h
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: vitalii.lysenko
 *
 * Coder class header.
 *
 * You have to change this file to fix build errors, and make
 * the unit tests passed.
 *
 */

#ifndef CODER_H
#define CODER_H

#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <limits>

/*
 * This function was pre-compiled and is provided as a part of the
 * static library.
 *
 */
void encode( const char* buf, unsigned int size );

#pragma pack(push)

/*
 * Coder class header.
 *
 */
class Coder
{
private:
    char* m_buf;
    unsigned int m_size;
    
public:
    Coder();
    Coder( const Coder& other );
    ~Coder();
    
	void set( const char* buf, unsigned int size );
	const char* buf() const;
	unsigned int size() const;

	void encode();
	void decode();
    
    Coder& operator=( const Coder& other );
    
};

#pragma pack(pop)

#endif // CODER_H