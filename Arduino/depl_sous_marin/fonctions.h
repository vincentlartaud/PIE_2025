// Fonctions pour le déplacement du sous-marin

void avance(int vitesse, int t); // Fait avancer le moteur (vitesse absolue)

void tourne_gauche(int delta_v, int t); // Fait tourner à gauche (vitesse relative par rapport au point mort v=1500)

void tourne_droite(int delta_v, int t); // Fait tourner à gauche (vitesse relative par rapport au point mort v=1500)

void arret(); // Arrête les moteurs

void calibrerESCs(); // Calibrage des moteurs