#ifndef SUB_H
#define SUB_H

/************************************************************/
/*  Функция вычитания чисел                                 */
/*                                                          */
/*  void subtraction(IN p_element valueL,                   */
/*                   IN p_element valueM,                   */
/*                   OUT p_element out);                    */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element valueL    - уменьшаемое                       */
/*  p_element valueM    - вычитаемое                        */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element out    - массив, в который будет помещен      */
/*                     результат вычитания                  */
/*                                                          */
/************************************************************/

LIB(void) subtraction(IN p_element valueL,
                      IN p_element valueM,
                      OUT p_element out);

/************************************************************/
/*  Функция вычитания чисел                                 */
/*                                                          */
/*  void subtraction2(IN p_element valueL,                  */
/*                    IN unsigned int valueLSize,           */
/*                    IN p_element valueM,                  */
/*                    IN unsigned int valueMSize,           */
/*                    OUT p_element out);                   */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element valueL            - уменьшаемое               */
/*  p_element valueM            - вычитаемое                */
/*  unsigned int valueLSize     - длина числа valueL        */
/*  unsigned int valueMSize     - длина числа valueM        */
/*                                                          */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element out    - массив, в который будет помещен      */
/*                     результат вычитания                  */
/*                                                          */
/************************************************************/

LIB(void) subtraction2(IN p_element valueL,
                       IN unsigned int valueLSize,
                       IN p_element valueM,
                       IN unsigned int valueMSize,
                       OUT p_element out);

/************************************************************/
/*  Функция вычитает 1 из заданного числа                   */
/*                                                          */
/*  void decrement(IN OUT p_element valueL);                */
/*                                                          */
/*  Входные параметры:                                      */
/*                                                          */
/*  p_element valueL    - уменьшаемое                       */
/*                                                          */
/*  Выходные параметры:                                     */
/*                                                          */
/*  p_element valueL - массив, в который будет помещен      */
/*                     результат дикрементирования          */
/*                                                          */
/************************************************************/

LIB(void) decrement(IN OUT p_element valueL);

#endif