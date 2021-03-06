#ifndef NUMIO_H
#define NUMIO_H

/************************************************************************************/
/*  MAX_PATH_LENGTH - Максимальный размер пути к файлу                              */
/*  DEFAULT_INPUT_PATH - Стандартный путь к файлу, из которого происходит чтение    */
/*  DEFAULT_OUTPUT_PATH - Стандартный путь к файлу, в который происходит вывод      */
/************************************************************************************/

#define MAX_PATH_LENGTH 151
#define DEFAULT_INPUT_PATH "input.txt"
#define DEFAULT_OUTPUT_PATH "output.txt"


/************************************************************************************/
/*  Функция для чтения числа из файла                                               */
/*                                                                                  */
/*  int _scanFile(IN char* path,                                                    */
/*                OUT p_element numptr);                                            */
/*                                                                                  */
/*  Входные параметры:                                                              */
/*                                                                                  */
/*  char* path - путь к файлу, из которого производить чтение                       */
/*                                                                                  */
/*  Выходные параметры:                                                             */
/*                                                                                  */
/*  p_element numptr - массив, в который будет помещено число, читаемое из файла    */
/*                                                                                  */
/*  Возвращаемые значения:                                                          */
/*                                                                                  */
/*  -1 - не удалось открыть файл                                                    */
/*   0 - число успешно считано из файла                                             */
/*                                                                                  */
/************************************************************************************/
LIB(int) _scanFile(IN char* path,
                   OUT p_element numptr);


/************************************************************************************/
/*  Функция для вывода числа в файл                                                 */
/*                                                                                  */
/*  int _printFile(IN char* path,                                                   */
/*                 IN p_element numptr);                                            */
/*                                                                                  */
/*  Входные параметры:                                                              */
/*                                                                                  */
/*  char* path - путь к файлу, из которого производить чтение                       */
/*  p_element numptr - указатель на число, которое необходимо записать в файл       */
/*                                                                                  */
/*  Выходные параметры:                                                             */
/*                                                                                  */
/*  p_element numptr - массив, в который будет помещено число, читаемое из файла    */
/*                                                                                  */
/*  Возвращаемые значения:                                                          */
/*                                                                                  */
/*  -1 - не удалось открыть файл                                                    */
/*   0 - число успешно напечатано в файл                                            */
/*                                                                                  */
/************************************************************************************/

LIB(int) _printFile(IN char* path,
                    IN p_element numptr);


/************************************************************************************/
/*  Функция для вывода числа в консоль в формате Little Endian                      */
/*                                                                                  */
/*  void printConsoleLE(IN p_element numptr);                                       */
/*                                                                                  */
/*  Входные параметры:                                                              */
/*                                                                                  */
/*  p_element numptr - число, которое нужно вывести в консоль                       */
/*                                                                                  */
/************************************************************************************/

LIB(void) printConsoleLE(IN p_element numptr);

/************************************************************************************/
/*  Функция для вывода числа в консоль в формате Little Endian                      */
/*                                                                                  */
/*  void printConsoleLE2(IN p_element numptr,                                       */
/*                       IN unsigned int size);                                     */
/*                                                                                  */
/*  Входные параметры:                                                              */
/*                                                                                  */
/*  p_element numptr    - число, которое нужно вывести в консоль                    */
/*  unsigned int size   - длина числа                                               */
/*                                                                                  */
/************************************************************************************/

LIB(void) printConsoleLE2(IN p_element numptr, unsigned int size);



/************************************************************************************/
/*  Функция для вывода числа в консоль в формате Big Endian                         */
/*                                                                                  */
/*  void printConsoleBE(IN p_element numptr);                                       */
/*                                                                                  */
/*  Входные параметры:                                                              */
/*                                                                                  */
/*  p_element numptr - число, которое нужно вывести в консоль                       */
/*                                                                                  */
/************************************************************************************/

LIB(void) printConsoleBE(IN p_element numptr);

/************************************************************************************/
/*  Функция для вывода числа в консоль в формате Big Endian                         */
/*                                                                                  */
/*  void printConsoleBE2(IN p_element numptr,                                       */
/*                       IN unsigned int size);                                     */
/*                                                                                  */
/*  Входные параметры:                                                              */
/*                                                                                  */
/*  p_element numptr    - число, которое нужно вывести в консоль                    */
/*  unsigned int size   - длина числа                                               */
/*                                                                                  */
/************************************************************************************/

LIB(void) printConsoleBE2(IN p_element numptr, unsigned int size);

#endif