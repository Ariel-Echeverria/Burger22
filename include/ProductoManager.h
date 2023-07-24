#ifndef TAREAMANAGER_H
#define TAREAMANAGER_H
#include "Producto.h"
#include "ProductoArchivo.h"

class ProductoManager {
public:
	void Cargar();
	void ListarTodos();
	void ListarXId();
	void Editar();

	void Listar(Producto producto);

private:
	ProductoArchivo _archivo;
};

#endif
