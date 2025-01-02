clear

# Limpiar directorio de compilación
mkdir -p build
rm -rf build/*

# Compilar los archivos fuente
g++ -c -std=c++17 -I./include main.cpp -o build/main.o

g++ -c -std=c++17 -I./include src/Randomizer.cpp -o build/Randomizer.o

g++ -c -std=c++17 -I./include src/logic/Ant.cpp -o build/Ant.o
g++ -c -std=c++17 -I./include src/logic/Space.cpp -o build/Space.o

g++ -c -std=c++17 -I./include src/gui/components/MainWindow.cpp -o build/MainWindow.o
g++ -c -std=c++17 -I./include src/gui/components/Frame.cpp -o build/Frame.o
g++ -c -std=c++17 -I./include src/gui/components/Button.cpp -o build/Button.o
g++ -c -std=c++17 -I./include src/gui/components/TextBox.cpp -o build/TextBox.o
g++ -c -std=c++17 -I./include src/gui/components/Graphic.cpp -o build/Graphic.o
g++ -c -std=c++17 -I./include src/gui/components/GraphicFunction.cpp -o build/GraphicFunction.o
g++ -c -std=c++17 -I./include src/gui/components/Grid.cpp -o build/Grid.o

g++ -c -std=c++17 -I./include src/gui/GUI.cpp -o build/GUI.o
g++ -c -std=c++17 -I./include src/gui/ButtonFunctions.cpp -o build/ButtonFunctions.o

# Enlazar los objetos y generar el ejecutable
g++ build/main.o \
    build/Randomizer.o \
    build/Ant.o build/Space.o \
    build/MainWindow.o build/Frame.o build/Button.o build/TextBox.o build/Graphic.o build/GraphicFunction.o build/Grid.o \
    build/GUI.o src/gui/ButtonFunctions.cpp \
    -o build/main.exe \
    -Iinclude -lsfml-graphics -lsfml-window -lsfml-system

# Ejecutar el programa
./build/main.exe