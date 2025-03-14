function chemin = genere_chemin_hb(points, p)
    % Génère un chemin en zigzag dans un polygone convexe en balayant
    % verticalement
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
    delta_x = maxX-minX;
    pas = delta_x/p;
    
    % Générer les lignes de balayage parallèles à l'axe X (de bas en haut)
    y = minY;
    direction = 1; % Alternance gauche-droite
    
    n = size(points,1);

    while y <= maxY
        % Trouver les intersections entre la ligne y = constante et le polygone
        intersections = [];
        
        for i = 1:n
            % Indices des deux points formant une arête du polygone
            p1 = points(i,:);
            p2 = points(mod(i,n)+1,:);

            % Vérifier si la ligne horizontale coupe cette arête
            if (p1(2) <= y && p2(2) >= y) || (p2(2) <= y && p1(2) >= y)
                % Calculer l'intersection par interpolation linéaire
                if p1(2) ~= p2(2)
                    x_intersect = p1(1) + (y-p1(2)) * (p2(1)-p1(1)) / (p2(2)-p1(2));
                    intersections = [intersections; x_intersect];
                end
            end
        end
        
        % Trier les intersections en ordre croissant
        intersections = sort(intersections);
        m=length(intersections);
        
        % Ajouter les points de la ligne de balayage
        if mod(m,2) == 0
            for j = 1:2:m
                if direction == 1
                    chemin = [chemin; intersections(j), y; intersections(j+1), y];
                else
                    chemin = [chemin; intersections(j+1), y; intersections(j), y];
                end
            end
        end
        
        % Inverser la direction
        direction = -direction;
        
        % Monter d'un pas
        y = y+pas;
    end
end
