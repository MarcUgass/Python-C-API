import numpy as np
import time

# Tamaño de la matriz
n = 10000

# Crear la matriz
inicio_creacion = time.time()
numpy_array = np.fromfunction(lambda i, j: i + j, (n, n), dtype=np.float64)
fin_creacion = time.time()

# Realizar operaciones intensivas
inicio_operaciones = time.time()
suma = np.sum(numpy_array)
fin_operaciones = time.time()

# Tiempos de ejecución
duracion_creacion = fin_creacion - inicio_creacion
duracion_operaciones = fin_operaciones - inicio_operaciones

print("Tiempo de creación del array: ", duracion_creacion, " segundos")
print("Tiempo total de la suma: ", duracion_operaciones, " segundos")
print("Sumatorio: ", suma)