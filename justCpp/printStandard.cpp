#include <iostream>

const int numStandards = 7;
// the c++26 stdCode is a placeholder since the exact code won't be determined until the standard is finalized
const long stdCode[numStandards] = { 199711L, 201103L, 201402L, 201703L, 202002L, 202302L, 202612L };
const char* stdName[numStandards] = { "Pre-C++11", "C++11", "C++14", "C++17", "C++20", "C++23", "C++26" };

long getCppStandard()
{
#if defined (_MSVC_LANG)
	return _MSVC_LANG;
#elif defined (_MSC_VER)
	return -1;
#else
	//__cplusplus is the intended way to query the language standard code
	return __cplusplus;
#endif
}

int main()
{
	long standard = getCppStandard();

	if (standard == -1)
	{
		std::cout << "Error: Unable to determine your language standard.  Sorry.\n";
		return 0;
	}

	for (int i = 0; i < numStandards; ++i)
	{
		// if the reported version is one of the finalizd standard codes
		//then we know exactly hwat version the compiler is running
		if (standard == stdCode[i])
		{
			std::cout << "compiler is using" << stdName[i] << "(language standard code" << "L)\n";
			break;
		}

		//if the reported Version is between two finalized standard codes,
		//this must be a preview edition
		if (standard < stdCode[i])
		{
			std::cout << "complier is preview edition of " << stdName[i]
				<< "(language standard code " << standard << "L)\n";
			break;
		}
	}

	return 0;

}
