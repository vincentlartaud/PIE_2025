#include <Servo.h>

Servo esc;  // Objet Servo pour contrôler l'ESC

const int escPin = 9;  // Broche PWM de l'ESC
const int minThrottle = 1000;  // Valeur minimale (moteur arrêté)
const int maxThrottle = 2000;  // Valeur maximale (pleine vitesse)

void setup() {
    Serial.begin(9600);
    esc.attach(escPin);

    Serial.println("Calibration de l'ESC en cours...");
    Serial.println("Débranchez la batterie, puis branchez-la quand vous y êtes invité.");

    delay(2000);
    Serial.println("Branchez la batterie MAINTENANT !");
    esc.writeMicroseconds(maxThrottle);  // Valeur max pour calibrer
    delay(3000);
    
    esc.writeMicroseconds(minThrottle);  // Retour à la valeur min
    Serial.println("Calibration terminée !");
    delay(2000);
}

void loop() {
    int vitesse;  // Variable pour stocker la vitesse entrée par l'utilisateur

    Serial.println("Entrez une valeur entre 1000 (arrêt) et 2000 (max) :");
    while (Serial.available() == 0);  // Attendre l'entrée utilisateur

    vitesse = Serial.parseInt();  // Lire la valeur entrée

    if (vitesse >= minThrottle && vitesse <= maxThrottle) {
        esc.writeMicroseconds(vitesse);
        Serial.print("Vitesse réglée à : ");
        Serial.println(vitesse);
    } else {
        Serial.println("Valeur invalide ! Entrez un nombre entre 1000 et 2000.");
    }
}
