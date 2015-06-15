clear
echo "Début de compilation"

g++ -std=c++0x Main.cpp ./class/*.cpp -o executable `pkg-config gtkmm-2.4 --cflags --libs` -lsfml-network -lsfml-window -lsfml-system

if [ "$?" = "0" ];then
  echo "Compilation terminé"

  echo "lancement exécutable"
  ./executable
  echo "exécutable lancé"
else
  echo "Erreur de compilation" 
fi
