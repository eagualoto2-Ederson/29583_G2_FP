import json
import os

# -----------------------------
# Cargar inventario desde archivo
# -----------------------------
def cargar_inventario():
    if os.path.exists("inventario.json"):
        with open("inventario.json", "r") as archivo:
            return json.load(archivo)
    return []


# -----------------------------
# Guardar inventario en archivo
# -----------------------------
def guardar_inventario(inventario):
    with open("inventario.json", "w") as archivo:
        json.dump(inventario, archivo, indent=4)
    print("\n✔ Inventario guardado correctamente.\n")


# -----------------------------
# Registrar un nuevo repuesto
# -----------------------------
def registrar_repuesto(inventario):
    print("\n--- Registrar nuevo repuesto ---")

    nombre = input("Nombre del repuesto: ").title()
    marca = input("Marca del vehículo: ").title()
    modelo = input("Modelo del vehículo: ").title()
    anio = input("Año del vehículo: ")
    categoria = input("Categoría (motor, frenos, suspensión, etc.): ").title()
    ubicacion = input("Ubicación (estante, caja, etc): ").title()

    repuesto = {
        "nombre": nombre,
        "marca": marca,
        "modelo": modelo,
        "anio": anio,
        "categoria": categoria,
        "ubicacion": ubicacion
    }

    inventario.append(repuesto)
    guardar_inventario(inventario)

    print("✔ Repuesto registrado con éxito.\n")


# -----------------------------
# Mostrar inventario completo
# -----------------------------
def mostrar_inventario(inventario):
    print("\n--- Inventario Completo ---")
    if not inventario:
        print("No hay repuestos registrados.\n")
        return

    for i, rep in enumerate(inventario, 1):
        print(f"\nRepuesto #{i}")
        print(f"Nombre: {rep['nombre']}")
        print(f"Marca: {rep['marca']}")
        print(f"Modelo: {rep['modelo']}")
        print(f"Año: {rep['anio']}")
        print(f"Categoría: {rep['categoria']}")
        print(f"Ubicación: {rep['ubicacion']}")
    print()


# -----------------------------
# Buscar repuestos
# -----------------------------
def buscar_repuesto(inventario):
    print("\n--- Buscar Repuesto ---")
    criterio = input("Buscar por nombre o categoría: ").title()

    resultados = [rep for rep in inventario if criterio in rep["nombre"] or criterio in rep["categoria"]]

    if resultados:
        print("\nResultados encontrados:")
        for rep in resultados:
            print(f"- {rep['nombre']} ({rep['categoria']}) -> Ubicación: {rep['ubicacion']}")
    else:
        print("No se encontraron repuestos con ese criterio o categoria.\n")


# -----------------------------
# Editar repuesto
# -----------------------------
def editar_repuesto(inventario):
    mostrar_inventario(inventario)

    if not inventario:
        return

    try:
        idx = int(input("Ingrese el número del repuesto al que desea editar: ")) - 1
        if idx < 0 or idx >= len(inventario):
            print("Índice inválido.")
            return
    except ValueError:
        print("Debe ingresar un número.")
        return

    print("\nDeje en blanco si no desea modificar ese campo.\n")

    rep = inventario[idx]

    nuevo_nombre = input(f"Nombre ({rep['nombre']}): ")
    nueva_marca = input(f"Marca ({rep['marca']}): ")
    nuevo_modelo = input(f"Modelo ({rep['modelo']}): ")
    nuevo_anio = input(f"Año ({rep['anio']}): ")
    nueva_categoria = input(f"Categoría ({rep['categoria']}): ")
    nueva_ubicacion = input(f"Ubicación ({rep['ubicacion']}): ")

    if nuevo_nombre: rep["nombre"] = nuevo_nombre.title()
    if nueva_marca: rep["marca"] = nueva_marca.title()
    if nuevo_modelo: rep["modelo"] = nuevo_modelo.title()
    if nuevo_anio: rep["anio"] = nuevo_anio
    if nueva_categoria: rep["categoria"] = nueva_categoria.title()
    if nueva_ubicacion: rep["ubicacion"] = nueva_ubicacion.title()

    guardar_inventario(inventario)
    print("✔ Repuesto actualizado correctamente.\n")


# -----------------------------
# Eliminar repuesto
# -----------------------------
def eliminar_repuesto(inventario):
    mostrar_inventario(inventario)

    if not inventario:
        return

    try:
        idx = int(input("Ingrese el número del repuesto al que desea eliminar: ")) - 1
        if idx < 0 or idx >= len(inventario):
            print("Índice inválido.")
            return
    except ValueError:
        print("Debe ingresar un número.")
        return

    eliminado = inventario.pop(idx)
    guardar_inventario(inventario)

    print(f"✔ Repuesto '{eliminado['nombre']}' eliminado.\n")


# -----------------------------
# Borrar TODO el inventario
# -----------------------------
def limpiar_inventario(inventario):
    confirmar = input("\n¿Seguro que deseas borrar TODO el inventario? (S/N): ").lower()

    if confirmar == "s":
        inventario.clear()
        guardar_inventario(inventario)
        print("✔ Inventario completamente vaciado.\n")
    else:
        print("Operación cancelada.\n")


# -----------------------------
# Menú principal
# -----------------------------
def menu():
    inventario = cargar_inventario()

    while True:
        print("============ Sistema de Inventario ============")
        print("1. Registrar repuesto")
        print("2. Mostrar inventario")
        print("3. Buscar repuesto")
        print("4. Editar repuesto")
        print("5. Eliminar repuesto")
        print("6. Borrar todo el inventario")
        print("7. Salir")
        print("================================================")

        opcion = input("Seleccione una opción: ")

        if opcion == "1":
            registrar_repuesto(inventario)
        elif opcion == "2":
            mostrar_inventario(inventario)
        elif opcion == "3":
            buscar_repuesto(inventario)
        elif opcion == "4":
            editar_repuesto(inventario)
        elif opcion == "5":
            eliminar_repuesto(inventario)
        elif opcion == "6":
         limpiar_inventario(inventario)
        elif opcion == "7":
            print("Saliendo del sistema...")
            break
        else:
            print("Opción no válida. Intente nuevamente.\n")


# Ejecutar el programa
menu()
