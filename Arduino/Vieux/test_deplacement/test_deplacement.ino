// Définition des fonctions pour tourner et avancer + test

#include <Servo.h>

// Définition des deux Servos
Servo esc_gauche;
Servo esc_droite;

// Nom des moteurs
const int escPin_gauche = 9; // moteur gauche
const int escPin_droite = 10; // moteur droit

// Valeurs min et max de la vitesse
const int minThrottle = 1000;  // Arrêt
const int maxThrottle = 2000;  // Vitesse max

void tourne_gauche(int vitesse, int t){
  // Fait tourner le sous-marin à gauche pendant le temps t (en ms)
  esc_gauche.writeMicroseconds(minThrottle);
  esc_droite.writeMicroseconds(vitesse);
  delay(t);
  esc_gauche.writeMicroseconds(minThrottle);
  esc_droite.writeMicroseconds(minThrottle);
}

void tourne_droite(int vitesse, int t){
  // Fait tourner le sous-marin à droite pendant le temps t (en ms)
  esc_gauche.writeMicroseconds(vitesse);
  esc_droite.writeMicroseconds(minThrottle);
  delay(t);
  esc_gauche.writeMicroseconds(minThrottle);
  esc_droite.writeMicroseconds(minThrottle);
}

void avance(int vitesse, int t){
  // Fait avancer le sous-marin pendant le temps t (en ms)
  esc_gauche.writeMicroseconds(vitesse);
  esc_droite.writeMicroseconds(vitesse);
  delay(t);
  esc_gauche.writeMicroseconds(minThrottle);
  esc_droite.writeMicroseconds(minThrottle);
}


void setup() {
  // Moteur gauche
    Serial.begin(9600);
    esc_gauche.attach(escPin_gauche);
    esc_droite.attach(escPin_droite);

/*
    Serial.println("Calibration de l'ESC en cours...");
    Serial.println("Débranchez la batterie, puis branchez-la quand vous y êtes invité.");

    delay(500);
    Serial.println("Branchez la batterie MAINTENANT !");
    Serial.println("Appuyer sur une touche pour continuer");
    while(Serial.available()==0); // Attendre réponse

    esc_gauche.writeMicroseconds(maxThrottle);  // Valeur max pour calibrer
    esc_droite.writeMicroseconds(maxThrottle);  // Valeur max pour calibrer
    delay(1000);
    esc_gauche.writeMicroseconds(minThrottle);  // Retour à la valeur min
    esc_droite.writeMicroseconds(minThrottle);  // Retour à la valeur min
    Serial.println("Calibration terminée !");
    delay(2000);
*/
    esc_gauche.writeMicroseconds(1000);
    esc_droite.writeMicroseconds(1000);
    delay(3000);  // Pause de sécurité

    esc_gauche.writeMicroseconds(1200);
    esc_droite.writeMicroseconds(1200);
    delay(2000);

}

void loop() {
  // Test : avancer 1s ; tourner à gauche 1s ; tourner à droite 1s
  int vitesse = 1500; // Vitesse intermédiaire pour tester
  int t = 1000;
  avance(vitesse,5*t);
  delay(t);
  //tourne_gauche(vitesse,t);
  //delay(2*t);
  //tourne_droite(vitesse,t);
  //delay(2*t);
}
