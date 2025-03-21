function sauve_chemin(fichier, chemin)
    % Sauvegarde un chemin de points dans un fichier texte
    % Entrées :
    % - fichier : Nom du fichier de sortie
    % - chemin : Matrice Nx2 contenant les coordonnées (x, y)
    
    % Ouvrir le fichier en mode écriture
    fichierID = fopen(fichier, 'w');
    
    % Vérifier si l'ouverture du fichier a réussi
    if fichierID == -1
        error('Impossible diouvrir le fichier %s.', fichier);
    end
    
    % Écrire les coordonnées dans le fichier (format : x y)
    for i = 1:size(chemin, 1)
        fprintf(fichierID, '%.6f %.6f\n', chemin(i,1), chemin(i,2)); % on écrit chaque couple de coordonnées 
    end
    fprintf(fichierID, '%.6f %.6f\n', chemin(1,1), chemin(1,2)); % dernier trajet : le sous-marin revient à l'origine

    % Fermer le fichier
    fclose(fichierID);
    
    disp(['Chemin sauvegardé dans '+fichier]);
end