

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#define TEXT_LEN 51

struct{
	int id;
	char descripcion[TEXT_LEN];
}typedef Nacionalidad;

struct{
	int id;
	char marca[TEXT_LEN];
	char fabrica[TEXT_LEN];
	char tipoTela[TEXT_LEN];
}typedef Tipo;

struct{
	int id;
	char descripcion[TEXT_LEN];
	Nacionalidad naciodadlidad;
	Tipo tipo;
	float precioUnitario;
}typedef Producto;


Producto* producto_new(void);
Producto* producto_newParametros(int id,char* descripcion,char* nacionalidad, float precioUnitario);
void producto_delete(Producto* this);
int producto_setId(Producto* list, int id);
int producto_setDescripcion(Producto* list, char* descripcion);
int producto_setNacionalidad(Producto* list, char* nacionalidad);
int producto_setPrecioUnitario(Producto* list, float precioUnitario);
int producto_requestDescripcion(char* descripcion);
int producto_requestIdNacionalidad(int* idNac);
int producto_requestPrecioUnitario(float* precioUnitario);
int producto_requestData(char* descripcion, int* idNac, float* precioUnitario);

#endif /* PRODUCTO_H_ */
