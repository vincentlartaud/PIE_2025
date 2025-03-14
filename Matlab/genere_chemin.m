function chemin=genere_chemin(points,p,dir)
    % Génère un chemin en zigzag dans un polygone convexe en balayant selon
    % la direction donnée par dir
    % Entrées :
    % - points : Matrice (n x 2) des sommets du polygone convexe
    % - p : nombre de zigzags (pas = delta_x/p)
    % - dir : booléen, 0 pour un trajet vertical, 1 pour horizontal
    % Sortie :
    % - chemin : Liste ordonnée des points de passage du sous-marin

    if dir
        chemin=genere_chemin_hb(points,p);
    else
        chemin=genere_chemin_gd(points,p);
    end
end