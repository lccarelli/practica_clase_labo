#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"


Producto* producto_new(void){
    return (Producto*) malloc(sizeof(Producto));
};

Producto* producto_newParametros(int id,char* descripcion,char* nacionalidad, float precioUnitario){
	Producto* producto = producto_new();
	Producto* result = NULL;

    if(producto != NULL ){
        if(
        		producto_setId(producto, id) &&
				producto_setDescripcion(producto, descripcion) &&
				producto_setNacionalidad(producto, nacionalidad) &&
				producto_setPrecioUnitario(producto, precioUnitario)

		){
        	producto_delete(producto);
        };
    };
    return producto;
}

void producto_delete(Producto* this){

    if(this != NULL)
    	return free(this);
};


int producto_setId(Producto* list, int id){
	int result = OK;
	(list!=NULL && id>0) ? (list->id = id) : (result = ERROR);
	return result;
}

int producto_setDescripcion(Producto* list, char* descripcion){
	int result = OK;
	if(list!=NULL && descripcion!=NULL)
		strncpy(list->descripcion, descripcion, sizeof(list->descripcion));
	else result = ERROR;
	return result;
}

int producto_setNacionalidad(Producto* list, int idNac){
	int result = OK;
	(list!=NULL && idNac>0) ? (list->naciodadlidad.id = idNac) : (result = ERROR);
	return result;
}

int producto_setPrecioUnitario(Producto* list, float precioUnitario){
	int result = OK;
	(list!=NULL && precioUnitario>0) ? (list->precioUnitario = precioUnitario) : (result = ERROR);
	return result;
}

int producto_requestDescripcion(char* descripcion){
	int result = ERROR;
	if (utn_getString(descripcion, TEXT_LEN, "\ndescripcion?", "\nERROR-> descripcion?", 3) == 0)
		result = OK;
	return result;
}

int producto_requestIdNacionalidad(int* idNac){
	int result = ERROR;
	if (utn_getNumero(idNac, "\nidNac?", "\nERROR-> idNac?", 0, 5, 3) == 0)
		result = OK;
	return result;
}

int producto_requestPrecioUnitario(float* precioUnitario){
	int result = ERROR;
	if (utn_getNumeroFlotante(precioUnitario, "\nprecioUnitario?", "\nERROR-> precioUnitario?", 0, 1000000000, 3) == 0)
		result = OK;
	return result;
}

int producto_requestData(char* descripcion, int* idNac, float* precioUnitario){
	int result = ERROR;
	if(
			producto_requestDescripcion(descripcion) == 0 &&
			producto_requestIdNacionalidad(idNac) == 0 &&
			producto_requestPrecioUnitario(precioUnitario) == 0
		)
	{
		result = OK;
	}
	return result;
}
