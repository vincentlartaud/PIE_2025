
#include <Servo.h>

Servo moteur1;
Servo moteur2;

const int pinMoteur1 = 9;
const int pinMoteur2 = 10;

const int throttleStop = 1000;     // Moteur arrêté
const int throttleNeutre = 1500;   // Point mort (neutre)
const int throttleAvant = 1700;    // Marche avant (adapter selon ESCs)
const int throttleArriere = 1300;  // Marche arrière (adapter selon ESCs)

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
  delay(1000);
}

void loop() {
  for (int cycle = 1; cycle <= 5; cycle++) {
    Serial.print("=== Cycle ");
    Serial.print(cycle);
    Serial.println(" ===");

    // Pause 20s
    Serial.println("Pause (20s)...");
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
    delay(20000);

    // Marche avant 20s
    Serial.println("Marche avant (20s)...");
    moteur1.writeMicroseconds(throttleAvant);
    moteur2.writeMicroseconds(throttleAvant);
    delay(20000);

    // Pause 20s
    Serial.println("Pause (20s)...");
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
    delay(20000);

    // Marche arrière 20s
    Serial.println("Marche arrière (20s)...");
    moteur1.writeMicroseconds(throttleArriere);
    moteur2.writeMicroseconds(throttleArriere);
    delay(20000);
  }

  // Fin de la boucle, arrêt complet
  Serial.println("Séquence terminée ! Arrêt des moteurs.");
  moteur1.writeMicroseconds(throttleStop);
  moteur2.writeMicroseconds(throttleStop);
  while (true);  // Boucle infinie pour ne pas recommencer
}

