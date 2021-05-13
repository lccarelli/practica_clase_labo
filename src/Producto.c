#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "Producto.h"
#include "Menu.h"
#include <string.h>

Producto* producto_new(void){
	return (Producto*) malloc(sizeof(Producto));
}

int producto_delete(Producto* this){
	int retorno = OK;
	(this != NULL) ? free(this) : (retorno = ERROR);
	return retorno;
}

int producto_requestId(int* id){
	int result = ERROR;
	if (utn_getNumero(id, "\nId?", "\nERROR-> id?", 0, 5, 3) == OK)
		result = OK;
	return result;
}

int producto_setId(Producto* this, int id){
	int result = OK;
	(this!=NULL && id>0) ? (this->id = id) : (result = ERROR);
	return result;
}

int producto_getId(Producto* this){
	int aux = ERROR;
	if(this!=NULL) (aux = this->id);
	return aux;
}

int producto_requestDescripcion(char* descripcion){
	int result = ERROR;
	if (utn_getString(descripcion, TEXT_LEN, "\ndescripcion?", "\nERROR-> descripcion?", 3) == 0)
		result = OK;
	return result;
}

int producto_requestNacionalidad(int* idNac){
	int result = ERROR;
	if (utn_getNumero(idNac, "\nId Nac?", "\nERROR-> idNac?", 0, 5, 3) == OK)
		result = OK;
	return result;
}

int producto_setDescripcion(Producto* this, char* descripcion){
	int result = OK;
	if(this!=NULL && descripcion!=NULL)
		strncpy(this->descripcion, descripcion, sizeof(this->descripcion));
	else result = ERROR;
	return result;
}

char* producto_getDescripcion(Producto* this){
	char* aux = NULL;
	if(this!=NULL) (aux = this->descripcion);
	return aux;
}

int producto_setNacionalidad(Producto* this, int idNac){
	int result = OK;
	(this!=NULL && idNac>0) ? (this->idNac = idNac) : (result = ERROR);
	return result;
}

int producto_getIdNac(Producto* this){
	int aux = ERROR;
	if(this!=NULL) (aux = this->idNac);
	return aux;
}

int producto_requestTipo(int* idTipo){
	int result = ERROR;
	if (utn_getNumero(idTipo, "\nidTipo?", "\nERROR-> idTipo?", 0, 5, 3) == OK)
		result = OK;
	return result;
}

int producto_setTipo(Producto* this, int idTipo){
	int result = OK;
	(this!=NULL && idTipo>0) ? (this->idTipo = idTipo) : (result = ERROR);
	return result;
}

int producto_getTipo(Producto* this){
	int aux = ERROR;
	if(this!=NULL) (aux = this->idTipo);
	return aux;
}

int producto_setPrecioUnitario(Producto* this, float precioUnitario){
	int result = OK;
	(this!=NULL && precioUnitario>0) ? (this->precioUnitario = precioUnitario) : (result = ERROR);
	return result;
}

int producto_requestPrecioUnitario(float* precioUnitario){
	int result = ERROR;
	if (utn_getNumeroFlotante(precioUnitario, "\nprecioUnitario?", "\nERROR-> precioUnitario?", 0, 1000000000, 3) == OK)
		result = OK;
	return result;
}

float producto_getPrecioUnitario(Producto* this){
	int aux = ERROR;
	if(this!=NULL) (aux = this->precioUnitario);
	return aux;
}



int producto_requestData(int* id, char* descripcion, int* idNac, int* idTipo, float* precioUnitario){
	int result = ERROR;
	if(
			producto_requestId(id) == OK &&
			producto_requestDescripcion(descripcion) == OK &&
			producto_requestNacionalidad(idNac) == OK &&
			producto_requestTipo(idTipo) == OK &&
			producto_requestPrecioUnitario(precioUnitario) == OK
		)
	{
		result = OK;
	}
	return result;
}

Producto* producto_newParametros(int id, char* descripcion, int idNac, int idTipo, float precioUnitario){
	Producto* auxProducto = producto_new();
	if(
			auxProducto!=NULL &&
			(
					producto_setId(auxProducto, id) <0 ||
					producto_setDescripcion(auxProducto, descripcion) < 0 ||
					producto_setNacionalidad(auxProducto, idNac) < 0 ||
					producto_setTipo(auxProducto, idTipo) < 0)
	){
		producto_delete(auxProducto);
	}
	return auxProducto;
}


int producto_register(Producto* this, int len){
	int result = ERROR;
	Producto buffer;

	if(
			producto_requestData(
					&buffer.id,
					buffer.descripcion,
					&buffer.idNac,
					&buffer.idTipo,
					&buffer.precioUnitario) == OK
	){
		this = producto_newParametros(buffer.id, buffer.descripcion, buffer.idNac, buffer.idTipo, buffer.precioUnitario);
		printf("\nEmpleado cargado->");
		producto_print(this);
		result = OK;
	}
	return result;
}


int producto_print(Producto* this){
	int result = ERROR;
	if(this!=NULL){
		printf("\nID-> %d -- DESCRIPCION-> %s -- ID-NAC-> %d --ID-TIPO-> %d -- PRECIOU-> %.2f",
				producto_getId(this),
				producto_getDescripcion(this),
				producto_getIdNac(this),
				producto_getTipo(this),
				producto_getPrecioUnitario(this)
				);
		result = OK;
	}
	return result;
}








