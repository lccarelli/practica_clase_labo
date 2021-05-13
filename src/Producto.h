#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#define PRODUCTO_CANT 10
#define PRODUCTO_HARCODE 10
#define TEXT_LEN 51
#define ERROR -1
#define OK 0
#define FALSE 0
#define TRUE 1
#define EXIT 0
#define LOW_LOGIC -1

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
	int idNac;
	int idTipo;
	float precioUnitario;
}typedef Producto;


Producto* producto_new(void);
Producto* producto_newParametros(int id, char* descripcion, int idNac, int idTipo, float precioUnitario);
int producto_delete(Producto* this);

int producto_requestId(int* id);
int producto_setId(Producto* this, int id);
int producto_getId(Producto* this);

int producto_requestDescripcion(char* descripcion);
int producto_setDescripcion(Producto* this, char* descripcion);
char* producto_getDescripcion(Producto* this);

int producto_requestNacionalidad(int* idNac);
int producto_setNacionalidad(Producto* this, int idNac);
int producto_getIdNac(Producto* this);

int producto_requestTipo(int* idTipo);
int producto_setTipo(Producto* this, int idTipo);
int producto_getTipo(Producto* this);

int producto_requestPrecioUnitario(float* precioUnitario);
int producto_setPrecioUnitario(Producto* this, float precioUnitario);
float producto_getPrecioUnitario(Producto* this);

int producto_requestData(int* id, char* descripcion, int* idNac, int* idTipo, float* precioUnitario);
int producto_register(Producto* this, int len);
int producto_print(Producto* this);
#endif /* PRODUCTO_H_ */
