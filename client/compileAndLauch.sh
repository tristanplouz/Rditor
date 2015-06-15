clear
echo "Début de compilation"

D_s= date +%S
D_m= date +%M
D_h= date +%H
g++ -std=c++0x -x c++ Main.cpp ./class/*.cpp -o executable `pkg-config gtkmm-2.4 --cflags --libs`
F_s= date +%S
F_m= date +%M
F_h= date +%H

echo "Compilation terminé"
T_s= $F_s - $D_s
T_m= $F_m - $D_m
T_h= $F_h - $D_h
echo "temps écoulé : $T_h\ :\ $T_m\ :\ $T_s " 

echo "lancement exécutable"
./executable
echo "exécutable lancé"
