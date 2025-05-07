// Fonctions pour le déplacement du sous-marin

void avance(int vitesse, int t){
    // Fait avancer le moteur (vitesse absolue)
    moteur1.writeMicroseconds(vitesse);
    moteur2.writeMicroseconds(vitesse);
    delay(t);
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
}

void tourne_gauche(int delta_v, int t){
    // Fait tourner à gauche (vitesse relative par rapport au point mort v=1500)
    moteur1.writeMicroseconds(1500+delta_v);
    moteur2.writeMicroseconds(1500-delta_v);
    delay(t);
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
}

void tourne_droite(int delta_v, int t){
    // Fait tourner à gauche (vitesse relative par rapport au point mort v=1500)
    moteur1.writeMicroseconds(1500-delta_v);
    moteur2.writeMicroseconds(1500+delta_v);
    delay(t);
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
}

void arret(){
    // Arrête les moteurs
    moteur1.writeMicroseconds(throttleNeutre);
    moteur2.writeMicroseconds(throttleNeutre);
}

void calibrerESCs() {
    // Calibrage des moteurs
    Serial.println("Calibration des ESCs...");
    Serial.println("Débranchez les batteries, puis branchez-les quand vous y êtes invité.");
    delay(3000);
    Serial.println("Branchez les batteries MAINTENANT !");
    
    // Plein gaz pour init calibration
    avance(throttleAvant,3000);
  
    // Retour au minimum pour terminer la calibration
    arret();
    Serial.println("Calibration terminée !");
    delay(2000);
  }