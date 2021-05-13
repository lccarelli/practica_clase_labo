#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"
#include "Menu.h"

int main(void) {

	int select;
	Producto producto[10];

	do {
			menu_main(&select);

					switch(select){

					case ADD:

						(producto_register(producto, PRODUCTO_CANT) == 0) ?
								printf("\nAccion realizada con exito.") :
								printf("\nDebe ingresar un empleado. ");
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
