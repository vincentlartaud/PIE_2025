
#include <Servo.h>

Servo moteur1;
Servo moteur2;

const int pinMoteur1 = 9;
const int pinMoteur2 = 10;

const int throttleStop = 1000;     // Moteur arrêté
const int throttleNeutre = 1500;   // Point mort (neutre)
const int throttleArriere = 1700;    // Marche avant (adapter selon ESCs)
const int throttleAvant = 1300;  // Marche arrière (adapter selon ESCs)

void calibrerESCs() {
  Serial.println("Calibration des ESCs...");
  Serial.println("Débranchez les batteries, puis branchez-les quand vous y êtes invité.");
  delay(3000);
  Serial.println("Branchez les batteries MAINTENANT !");
  
  // Plein gaz pour init calibration
  moteur1.writeMicroseconds(throttleAvant);
  moteur2.writeMicroseconds(throttleAvant);
  delay(3000);

  // Retour au minimum pour terminer la calibration
  moteur1.writeMicroseconds(throttleStop);
  moteur2.writeMicroseconds(throttleStop);
  Serial.println("Calibration terminée !");
  delay(2000);
}

void setup() {
  Serial.begin(9600);

  moteur1.attach(pinMoteur1);
  moteur2.attach(pinMoteur2);

  calibrerESCs();

  // Mise au neutre après calibration
  moteur1.writeMicroseconds(throttleNeutre);
  moteur2.writeMicroseconds(throttleNeutre);
  delay(120000); // Pause de 2min le temps de refermer le bolide et de le mettre à l'eau
}

void loop() {
  for (int cycle = 1; cycle <= 10; cycle++) {
    Serial.print("=== Cycle ");
    Serial.print(cycle);
    Serial.println(" ===");

    /*
    // Marche avant 5s
    Serial.println("Marche avant (5s)...");
    moteur1.writeMicroseconds(1350);
    moteur2.writeMicroseconds(1350);
    delay(5000);

    // Pause 2s
    Serial.println("Pause (2s)...");
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
    delay(2000);

    // Virage 3s
    Serial.println("Virage (3s)...");
    moteur1.writeMicroseconds(1350);
    moteur2.writeMicroseconds(1650);
    delay(3000);

    // Pause 2s
    Serial.println("Pause (2s)...");
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
    delay(2000);

    // Virage 3s
    Serial.println("Virage (3s)...");
    moteur1.writeMicroseconds(1650);
    moteur2.writeMicroseconds(1350);
    delay(3000);

    // Pause 2s
    Serial.println("Pause (2s)...");
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
    delay(2000);

    // Marche avant 10s
    Serial.println("Marche avant (10s)...");
    moteur1.writeMicroseconds(throttleAvant);
    moteur2.writeMicroseconds(throttleAvant);
    delay(10000);

    // Pause 10s
    Serial.println("Pause (10s)...");
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
    delay(10000);
    */

    // Marche avant 7s
    Serial.println("Marche avant (7s)...");
    moteur1.writeMicroseconds(1450);
    moteur2.writeMicroseconds(1450);
    delay(7000);

    // Pause 2s
    Serial.println("Pause (2s)...");
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
    delay(2000);

    // Marche avant 7s
    Serial.println("Marche avant (7s)...");
    moteur1.writeMicroseconds(1320);
    moteur2.writeMicroseconds(1320);
    delay(7000);

    // Pause 2s
    Serial.println("Pause (2s)...");
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
    delay(2000);

    // Marche avant 7s
    Serial.println("Marche avant (7s)...");
    moteur1.writeMicroseconds(throttleAvant);
    moteur2.writeMicroseconds(throttleAvant);
    delay(7000);

    // Pause 2s
    Serial.println("Pause (2s)...");
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
    delay(2000);
  }

  // Fin de la boucle, arrêt complet
  Serial.println("Séquence terminée ! Arrêt des moteurs.");
  moteur1.writeMicroseconds(throttleStop);
  moteur2.writeMicroseconds(throttleStop);
  while (true);  // Boucle infinie pour ne pas recommencer
}

