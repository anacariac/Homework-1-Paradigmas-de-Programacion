#include <string>
using namespace std;

bool compare(string s1, string s2);

bool compare(const char* s1, const char* s2);

constexpr bool compare_constexpr(const char* s1, const char* s2);

void finalTime(string s1, string s2);

void finalTime(const char* s1,const char* s2,bool expr = false);

