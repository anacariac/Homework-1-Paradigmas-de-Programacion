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
 message<const string> Mensaje a registrar.
 severity<enum class> Nivel de severidad del mensaje.
 */
void logMessage(const string message, Level severity);

/*
 Registra un mensaje en un archivo de log junto con el nombre del archivo y el número de línea.
 message<const string> Mensaje a registrar.
 file<const string> Nombre del archivo donde ocurrió el evento.
 line<int> Número de línea en el archivo donde ocurrió el evento.
 */
void logMessage(const string message, const string file, int line);

/*
Registra un mensaje de seguridad en un archivo de log, asociado a un usuario específico.
message<const string> Mensaje de seguridad a registrar.
user<const string> Nombre del usuario asociado al evento.
 */
void logMessage(const string message, const string user);