import time

def crear_tupla_grande(n):
    return tuple(range(n))

def suma_elementos(tupla):
    return sum(tupla)

def contar_impares(tupla):
    return sum(1 for x in tupla if x % 2 != 0)

def encontrar_maximo(tupla):
    return max(tupla)

# Definir el tamaño de la tupla
n = 100000000  # 100 millones de elementos

# Crear la tupla grande
inicio_creacion = time.time()
tupla = crear_tupla_grande(n)
fin_creacion = time.time()

# Realizar operaciones intensivas
inicio_operacion = time.time()
resultado_suma = suma_elementos(tupla)
resultado_impares = contar_impares(tupla)
resultado_maximo = encontrar_maximo(tupla)
fin_operacion = time.time()

# Tiempos de ejecución
tiempo_creacion = fin_creacion - inicio_creacion
tiempo_operacion = fin_operacion - inicio_operacion

print("Tiempo de creación de la tupla: ", tiempo_creacion, "segundos")
print("Tiempo de las operaciones: ", tiempo_operacion, "segundos\n")
print("La suma de todos los elementos de la tupla da como resultado: ", resultado_suma)
