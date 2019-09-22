int getStringAlpha(int longMax, int intentos, char* mensaje, char* dondeAsignar);

int getIntRange(int* dondeAsignar, int min, int max, int intentos, char* mensaje);

int getSexo(int intentos, char* dondeAsignar, char* mensaje);

int getChar(int intentos, char* dondeAsignar, char* mensaje);

int getFloatRange(float min, float max, int intentos, float* dondeAsignar, char* mensaje);

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
