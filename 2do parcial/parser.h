
/*int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);
//int parser_EmployeeFromText1(FILE* pFile, LinkedList* pArrayList);
int parser_EmployeeListToText(FILE* pFile , LinkedList* pArrayList);
FILE* openFileRead(char* path , LinkedList* pArrayList);
FILE* openFileWrite(char* path , LinkedList* pArrayList);*/

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);

