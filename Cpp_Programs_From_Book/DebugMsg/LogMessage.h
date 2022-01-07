#pragma once
#if DEBUG == 1
inline void logMessage(const char* msg) {
	std::cout << msg << std::endl;
}
#else
#define logMessage(X) (0)
#endif
