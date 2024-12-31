clear

# Limpiar directorio de compilación
mkdir -p build
rm -rf build/*

# Compilar los archivos fuente
g++ -c -std=c++17 -I./include main.cpp -o build/main.o

g++ -c -std=c++17 -I./include src/Randomizer.cpp -o build/Randomizer.o

g++ -c -std=c++17 -I./include src/logic/Ant.cpp -o build/Ant.o
g++ -c -std=c++17 -I./include src/logic/Space.cpp -o build/Space.o

g++ -c -std=c++17 -I./include src/gui/MainWindow.cpp -o build/MainWindow.o
g++ -c -std=c++17 -I./include src/gui/Frame.cpp -o build/Frame.o
g++ -c -std=c++17 -I./include src/gui/BoardFrame.cpp -o build/BoardFrame.o


# Enlazar los objetos y generar el ejecutable
g++ build/main.o \
    build/Randomizer.o \
    build/Ant.o build/Space.o \
    build/MainWindow.o build/Frame.o build/BoardFrame.o \
    -o build/main.exe \
    -Iinclude -lsfml-graphics -lsfml-window -lsfml-system

# Ejecutar el programa
./build/main.exe