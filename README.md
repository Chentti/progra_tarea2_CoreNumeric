# progra_tarea2_CoreNumeric

## Autor

**Edmundo Andre Centti Torres**

---

## Descripción

`CoreNumeric` es una librería desarrollada en **C++20** que implementa algoritmos numéricos genéricos utilizando:

* **Templates**
* **Concepts**
* **Namespaces**
* **Fold Expressions**
* **Programación Genérica**


---

## Funcionalidades implementadas

La librería incluye las siguientes operaciones:

### Operaciones básicas

* `add(a,b)` → suma dos valores
* `sub(a,b)` → resta dos valores
* `mul(a,b)` → multiplicación
* `div(a,b)` → división

---

### Algoritmos sobre contenedores

* `sum(container)` → suma todos los elementos
* `count_elements(container)` → cuenta elementos
* `mean(container)` → promedio aritmético
* `variance(container)` → varianza poblacional
* `max(container)` → mayor elemento del contenedor

---

### Algoritmos avanzados

* `transform_reduce(container, lambda)`
  Aplica una transformación a cada elemento y luego acumula el resultado.

Ejemplo:

```cpp
transform_reduce(v, [](double x){ return x*x; });
```

---

### Variadic Templates

Funciones que aceptan cantidad variable de argumentos:

* `sum_variadic(...)`
* `mean_variadic(...)`
* `variance_variadic(...)`
* `max_variadic(...)`

Ejemplo:

```cpp
sum_variadic(1,2,3,4);
```

## Casos donde falla la compilación

### 1. `mean(string)`

```cpp
vector<string> v{"a","b"};
mean(v);
```

Falla porque `string` no cumple `Divisible`.

---

### 2. `variance(string)`

```cpp
vector<string> v{"a","b"};
variance(v);
```

Falla porque `string` no cumple:

* `Subtractable`
* `Multipliable`
* `Divisible`

---

### 3. `count_elements(int)`

```cpp
count_elements(5);
```

Falla porque `int` no cumple `Iterable`.

---

### 4. `add("hola","mundo")`

```cpp
add("hola","mundo");
```

Falla porque `const char*` no cumple `Addable`.

---

### 5. `mean(vector<char>)`

Puede fallar dependiendo de implementación, ya que `char / char` promueve a `int`, rompiendo `same_as<char>` en `Divisible`.

---

## Tipos soportados

La librería funciona correctamente con:

* `int`
* `double`
* `float`
* `long`
* Clases personalizadas que implementen operadores requeridos

Ejemplo:

* `Coordenada`
* `Vector3D`
* `Esfera`

---
