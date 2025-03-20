#include <string>
using namespace std;
enum class Level { DEBUG, INFO, WARNING, ERROR, CRITICAL};

/*
 Convierte un nivel de severidad a su representación en texto.
 severity<enum class> Nivel de severidad (DEBUG, INFO, WARNING, ERROR, CRITICAL).
 retorna string la representación en texto del nivel de severidad.
 */
string convertLevel(Level severity);

/*
 Registra un mensaje en un archivo de log con un nivel de severidad.
 message<string> Mensaje a registrar.
 severity<enum class> Nivel de severidad del mensaje.
 */
void logMessage(const string message, Level severity);


void logMessage(const string message, const string file, int line);

void logMessage(const string message, const string user);