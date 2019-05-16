
int menuInformes();

void mostrarAutosPorColor(eAuto lista[], int tam, eColor color[], int tamColor, eMarca marca[], int tamMarca);

void mostrarAutosPorMarca(eAuto lista[], int tam, eColor color[], int tamColor, eMarca marca[], int tamMarca);

void trabajosUnAuto(eAuto listA[], int tamA, eServicio listaS[], int tamS, eTrabajo listT[], int tamT, eColor listC[], int tamC, eMarca listM[], int tamM);

void autosSinTrabajos(eAuto listA[], int tamA, eTrabajo listaT[], int tamT, eColor listaC[], int tamC, eMarca listaM[], int tamM);

void importePorAuto(eAuto listA[], int tamA, eServicio listaS[], int tamS, eTrabajo listT[], int tamT, eColor listC[], int tamC, eMarca listM[], int tamM);

void servicioMasPedido(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);
