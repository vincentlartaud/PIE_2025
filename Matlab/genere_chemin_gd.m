function chemin = genere_chemin_gd(points,p)
    % Génère un chemin en zigzag dans un polygone convexe en balayant
    % horizontalement
    % Entrées :
    % - points : Matrice (n x 2) des sommets du polygone convexe
    % - p : nombre de zigzags (pas = delta_x/p)
    % Sortie :
    % - chemin : Liste ordonnée des points de passage du sous-marin
    
    % Trouver les limites du polygone
    minX = min(points(:,1));
    maxX = max(points(:,1));
    minY = min(points(:,2));
    maxY = max(points(:,2));

    % Initialisation du chemin
    chemin = [];

    % Nombre de zigzags
    delta_y = maxY-minY;
    pas = delta_y/p;
    
    % Générer les lignes de balayage parallèles à l'axe Y (de gauche à droite)
    x = minX;
    direction = 1; % Alternance bas-haut et haut-bas

    n = size(points,1);
    
    while x <= maxX
        % Trouver les intersections entre la ligne x = constante et le polygone
        intersections = [];
        
        for i = 1:n
            % Indices des deux points formant une arête du polygone
            p1 = points(i,:);
            p2 = points(mod(i,n)+1,:);

            % Vérifier si la ligne verticale coupe cette arête
            if (p1(1) <= x && p2(1) >= x) || (p2(1) <= x && p1(1) >= x)
                % Calculer l'intersection par interpolation linéaire
                if p1(1) ~= p2(1)
                    y_intersect = p1(2) + (x-p1(1)) * (p2(2)-p1(2)) / (p2(1)-p1(1));
                    intersections = [intersections; y_intersect];
                end
            end
        end
        
        % Trier les intersections en ordre croissant
        intersections = sort(intersections);
        m=length(intersections);
        
        % Ajouter les points de la ligne de balayage
        if mod(m, 2) == 0
            if direction == 1
                chemin = [chemin; repmat(x,m,1), intersections];
            else
                chemin = [chemin; repmat(x,m,1),flip(intersections)];
            end
        end
        
        % Inverser la direction
        direction = -direction;
        
        % Avancer vers la droite d'un pas
        x = x+pas;
    end
end