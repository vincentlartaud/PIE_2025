% Calcul des coordonnées des points du trajet du sous-marin 

% Coordonnées de l'enveloppe
% A faire : fenêtre graphique pour sélectionner ces points
points = [0 0; 1 0; 1 1; 0 1];
% points = [0 0; 7 0; 10 3; 0 5];

% Nombre de zigzags
p=5;

% Test convexité 
conv=est_convexe(points);
if ~conv 
    error("Erreur : le polygone n'est pas convexe !")
end

% Direction du balayage : 0 pour verticalement et 1 pour horizontalement
dir=1;

% Génération du chemin
chemin=genere_chemin(points,p,dir);

% Affichage
figure; hold on; axis equal;
fill(points(:,1), points(:,2), 'cyan', 'FaceAlpha', 0.3, 'EdgeColor', 'black'); % Polygone
plot(chemin(:,1),chemin(:,2), '-o', 'MarkerFaceColor', 'red'); % Chemin en zigzag
xlabel('X'); ylabel('Y');
title('Trajet en Zigzag dans un Polygone Convexe');
if dir
    legend("Balayage vertical");
else
    legend("Balayage horizontal");
end
hold off;