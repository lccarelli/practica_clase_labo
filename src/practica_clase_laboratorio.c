
#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"

int main(void) {

	Producto producto[10];

	char descripcion[51];
	int idNac;
	float precioUnitario;
	int id;


	do {
			menu_main(&select);

					switch(select){

					case ADD:

						if(producto_requestData(descripcion, &idNac, &precioUnitario) == 0)
						{
							//en construccion
							producto[0] = producto_newParametros(id, descripcion, idNac, precioUnitario);
						}
						break;

					case LOW:

						break;

					case MODIFY:

						break;

					case LIST:


						break;
					}

			} while(!(select == EXIT));

	return EXIT_SUCCESS;
}
