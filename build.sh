clear

# Limpiar directorio de compilación
mkdir -p build
rm -rf build/*

# Compilar los archivos fuente
g++ -c -std=c++17 -I./include main.cpp -o build/main.o

g++ -c -std=c++17 -I./include src/logic/Ant.cpp -o build/Ant.o
g++ -c -std=c++17 -I./include src/logic/Space.cpp -o build/Space.o

# Enlazar los objetos y generar el ejecutable
g++ build/main.o \
    build/Ant.o build/Space.o \
    -o build/main.exe

# Ejecutar el programa
./build/main.exe