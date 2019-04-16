/** \brief Realizar la suma de dos numeros
 *
 * \param Primer numero a sumar
 * \param Segundo numero a sumar
 * \return Resultado de la suma
 *
 */
int sumarDosNumeros(int, int);


/** \brief Realizar la resta de dos numeros
 *
 * \param Primer numero a restar
 * \param Segundo numero a restar
 * \return Resultado de la suma
 *
 */
int restarDosNumeros(int, int);


/** \brief Realizar la multiplicacion de dos numeros
 *
 * \param Primer numero a multiplicar
 * \param Segundo numero a multiplicar
 * \return Producto de la multiplicacion
 *
 */
int multiplicarDosNumeros(int, int);


/** \brief Realizar la division de dos numeros
 *
 * \param Numero divisor
 * \param Numero dividendo
 * \return Resto de la division
 *
 */
float dividirDosNumeros(int, int);


/** \brief Calcular el factorial de un numero
 *
 * \param Numero a calcular
 * \return Factorial del numero ingresado
 *
 */
int factorial(int);

/** \brief Menu de opciones para calculadora
 *
 * \return Opcion elegida
 *
 */



/** \brief pide un nombre y apellido
 *
 * \param le ingreso un vector [][50]
 * \param el tamanio del vector [tam][50]
 * \param lo pide y acomoda con iniciales en mayus
 */


void pedirNomApe(char nomApe[][50], int tam);

/** \brief pide sexos
 *
 * \param le ingreso un vector []
 * \param el tamanio del vector [tam]
 * \param los pide y acomoda
 */


void obtenerSexo(char sexo[], int tam);


/** \brief pide legajos
 *
 * \param le ingreso un vector []
 * \param el tamanio del vector [tam]
 * \param los pide y acomoda
 */
void obtenerLegajo(int legajos[], int tam);

/** \brief pide edades
 *
 * \param le ingreso un vector []
 * \param el tamanio del vector [tam]
 * \param los pide y acomoda
 */

void obtenerEdad(int edad[], int tam);

/** \brief duplica un vector x 2
 *
 * \param le ingreso un vector []
 * \param el tamanio del vector [tam]
 * \param lo duplica
 */

void duplicarVector(int vector[], int tam);

/** \brief ingreso vectores y los ordena por sexo y alfabeticamente
 *
 * \param le ingreso un vector []
 * \param el tamanio del vector [tam]
 * \param lo duplica
 */

int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);
void altaEmpleado(eEmpleado vec[], int tam);
void bajaEmpleado(eEmpleado vec[], int tam);
void ModificacionEmpleado(eEmpleado vec[], int tam);
