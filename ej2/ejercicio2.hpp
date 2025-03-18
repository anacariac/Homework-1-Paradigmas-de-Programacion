#include <string>
using namespace std;
enum class Level { DEBUG, INFO, WARNING, ERROR, CRITICAL};

string convertLevel(Level severity);

void logMessage(const string message, Level severity);

void logMessage(const string message, const string file, int line);

void logMessage(const string message, const string user);