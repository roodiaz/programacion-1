typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int ocupado;

}eEmpleado;


/** \brief Menu de opciones ABM
 *
 * \param Muestra opcines a elegir
 * \return Opcion elegida
 *
 */
int menuABM();


/** \brief Muestra informacion de un empleado
 *
 * \param Estructura de empleados
 * \return Nada
 *
 */
void mostrarEmpleado(eEmpleado empleado);

/** \brief Muestra informacion de todos los empleados dados de alta
 *
 * \param Ingresar vector
 * \param Ingresar tamaño del vector
 * \return Nada
 *
 */
void mostrarEmpleados(eEmpleado vec[], int tam);

/** \brief Busca espacio libre para dar de alta empleado
 *
 * \param Ingresar vector
 * \param Ingresar tamaño del vector
 * \return Nada
 *
 */
int buscarLibre(eEmpleado vec[], int tam);


/** \brief
 *
 * \param Ingresar vector
 * \param Ingresar tamaño del vector
 * \return Numero de empleado
 *
 */
int buscarEmpleado(eEmpleado vec[], int tam, int id);


/** \brief Opciones para dar de alta un empleado
 *
 * \param Ingresar vector
 * \param Ingresar tamaño del vector
 * \return Nada
 *
 */
void altaEmpleado(eEmpleado vec[], int tam);


/** \brief Opciones para dar de baja un empleado
 *
 * \param Estructura de empleados
 * \return Nada
 *
 */
 void bajaEmpleado(eEmpleado vec[], int tam);


 /** \brief Permite la modifacion de datos de empleados
  *
  * \param Ingresar vector
  * \param Ingresar tamaño del vector
  * \return Nada
  *
  */
void modificacionEmpleado(eEmpleado vec[], int tam);

/** \brief Ordena empleados por apellido y sector
 *
 * \param Ingresar vector
 * \param Ingresar tamaño del vector
 * \return Nada
 *
 */
 void ordenarEmpleados(eEmpleado vec[], int tam);

/** \brief muestra lista ordenada y informacion de sueldos
 *
 * \param Ingresar vector
 * \param Ingresar tamaño del vector
 * \return nada
 *
 */
void informacionEmpleados(eEmpleado vec[], int tam);

