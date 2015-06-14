clear
g++ -std=c++0x Main.cpp ./class/*.cpp -o executable `pkg-config gtkmm-2.4 --cflags --libs`
echo "Compilation terminé"
./executable
