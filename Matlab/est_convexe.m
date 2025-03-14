function conv = est_convexe(points)
    % Fonction qui teste si un polygone est convexe
    % Entrée : points (n x 2) - Matrice contenant les coordonnées des sommets
    % Sortie : conv (booléen) - True si le polygone est convexe, False sinon
    
    n = size(points, 1); % Nombre de sommets du polygone
    
    % Vérification que le polygone a au moins 3 sommets
    if n < 3
        error('Un polygone doit avoir au moins 3 sommets.');
    end
    
    % Initialisation des variables
    ref = 0;
    conv = true;
    
    % Boucle sur chaque triplet de points consécutifs
    for i = 1:n
        % Indices circulaires pour prendre les points P_i, P_{i+1}, P_{i+2}
        i1 = i;                      % P_i
        i2 = mod(i, n) + 1;           % P_{i+1}
        i3 = mod(i+1, n) + 1;         % P_{i+2}
        
        % Vecteurs formés par les points successifs
        v1 = points(i2, :) - points(i1, :); % P_{i+1} - P_i
        v2 = points(i3, :) - points(i2, :); % P_{i+2} - P_{i+1}
        
        % Déterminant
        det = v1(1) * v2(2) - v1(2) * v2(1);
        
        % Déterminer le signe de la première non-nullité du det
        if det ~= 0
            if ref == 0
                ref = sign(det);
            elseif sign(det) ~= ref
                conv = false;
                return;
            end
        end
    end
end