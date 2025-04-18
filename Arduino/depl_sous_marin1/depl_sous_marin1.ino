#include <Servo.h>
#include <fonctions.h>

Servo moteur1;
Servo moteur2;

const int pinMoteur1 = 9;
const int pinMoteur2 = 10;

// Définition des vitesses
const int throttleStop = 2000; // Moteur arrêté
const int throttleNeutre = 1500; // Point mort (neutre) 
const int throttleAvant = 1300; // Marche avant
const int throttleArriere = 1700; // Marche arrière
const int throttleVirage = 200 ; // Virage (vitesse relative par rapport au neutre)

void setup(){
  Serial.begin(9600);

  moteur1.attach(pinMoteur1);
  moteur2.attach(pinMoteur2);

  // Calibrage 
  calibrerESCs();

  // Mise au neutre après calibrage
  avance(throttleNeutre,120000) // Pause de 2min le temps de refermer le bolide et de le mettre à l'eau
}

void loop(){
  for (int i=1; i<=10; i++) {
    Serial.print("=== Cycle ");
    Serial.print(i);
    Serial.println(" ===");

    avance(throttleAvant,3000);
    delay(2000);
    tourne_gauche(throttleVirage,3000);
    delay(2000);
    avance(throttleAvant,3000);
    delay(2000);
    tourne_droite(throttleVirage,3000);
    delay(2000);
    avance(5000);
  }

  // Fin de la boucle, arrêt complet
  Serial.println("Séquence terminée ! Arrêt des moteurs.");
  arret();
  while(true);  // Boucle infinie pour ne pas recommencer
}
