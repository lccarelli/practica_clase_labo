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

int producto_setNacionalidad(Producto* list, char* nacionalidad){
	int result = OK;
	if(list!=NULL && nacionalidad!=NULL)
		strncpy(list->nacionalidad, nacionalidad, sizeof(list->nacionalidad));
	else result = ERROR;
	return result;
}

int producto_setPrecioUnitario(Producto* list, float precioUnitario){
	int result = OK;
	(list!=NULL && precioUnitario>0) ? (list->precioUnitario = precioUnitario) : (result = ERROR);
	return result;
}
