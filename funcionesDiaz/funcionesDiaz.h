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
int menu()


/** \brief Obtiene nombre y apellido, y pone ambas iniciales en mayuscula
 *
 * \param Ingreo vector
 * \param Ingreso tamanio de vector
 */
void obtenerNomApe(char nomApe[][50], int tam);


/** \brief Obtiene y valida sexo
 *
 * \param Ingreso vector
 * \param Ingreso tamanio de vector
 */
void obtenerSexo(char sexo[], int tam);


/** \brief Verifica y obtiene edad
 *
 * \param Ingreso vector
 * \param Ingreso tamanio
 */
void obtenerEdad(int edad[], int tam);


/** \brief Verifica y obtiene legajo
 *
 * \param Ingreso vector
 * \param Ingreso tamaño de vector
 */
void obtenerLegajo(int legajos[], int tam);


/** \brief Duplica vector

 *
 * \param Ingreso vector
 * \param Ingreso tamaño de vector
 */
void duplicarVector(int vector[], int tam);


/** \brief Ordena vectores por sexo y nombre alfabeticamente
 *
 * \param Ingreso vectores
 * \param Ingreso tamanio de vector
 */
void ordenarVectores( int vector[], int vector2[], int vector3[], char vectorSex[], float vectorFloat[],char nomApe[][50], int vector4 [],int tam);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void inicializarEmpleados(eEmpleado vec[], int tam);


/** \brief Busca espacio libre para dar de alta empleado
 *
 * \param Ingreso vector
 * \param Ingreso tamanio vector
 * \return -1 sino hay lugar, o devuelve indice libre
 *
 */
int buscarLibre(eEmpleado vec[], int tam);


/** \brief Busca empleado dado de alta por su legajo
 *
 * \param Ingreso vector
 * \param Ingreso tamanio vector
 * \param Ingreso numero de legajo
 * \return -1 sino existe legajo, o devuelve el numero de legajo si esta
 *
 */
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);


/** \brief Muestra datos de un solo empleado
 *
 * \param Ingreso vector
 * \param Ingreso tamanio vector
 *
 */
void mostrarEmpleado(eEmpleado emp);


/** \brief Muestra datos de todos los empleados
 *
 * \param Ingreso vector
 * \param Ingreso tamanio vector
 *
 */
void mostrarEmpleados(eEmpleado vec[], int tam);

/** \brief Da de alta un empleado
 *
 * \param Ingreso vector
 * \param Ingreso tamanio vector
 *
 */
void altaEmpleado(eEmpleado vec[], int tam);


/** \brief Da de baja un empleado
 *
 * \param Ingreso vector
 * \param Ingreso tamanio de vector
 *
 */
void bajaEmpleado(eEmpleado vec[], int tam);


/** \brief Permite modificar sueldo de un empleado ya cargado
 *
 * \param Ingreso vector
 * \param Ingreso tamanio vector
 *
 */
void ModificacionsueldoEmpleado(eEmpleado vec[], int tam);
