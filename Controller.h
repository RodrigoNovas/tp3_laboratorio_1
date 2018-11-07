/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int r
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int r
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Se ingresa alta de empleados nuevos que iran ingresados dentro del excel
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int r
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int r
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int r
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int r
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int r
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
