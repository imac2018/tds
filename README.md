# TD's
Un dépôt pour nos codes sources liés aux TDs.  
Hashtag Math, POO, Signal et (soon ?) OpenGL.

## Pourquoi ?
- Pouvoir finir ses TDs à la maison, sans devoir s'envoyer ses propres fichiers à chaque fois;
- Pouvoir directement partager du code, sans besoin de Mail ou Facebook;
- Ca offre des pistes à ceux qui sont moins à l'aise, et ça reste pratique pour les autres;
- Apprendre (un peu) Git.
- Allez viens, on est bien !

## Au menu
- Comment c'est que ça marche ? (Git débutant)
- Convention de nommage
- Précautions
- Trucs cool à faire

## Comment c'est que ça marche ? (Git débutant)
Mets-toi dans le dossier de ton choix: la commande suivante va cloner le dépôt dans un nouveau sous-dossier `tds`.
- `git clone https://github.com/imac2018/tds`
- `cd tds`
Et en fait, dès que tu commences/reprend un TD, tu crées le sous-dossier approprié à ton nom, et tu bosses directement dedans.

Au début de chaque séance, tu ferais :
- `cd <le_dossier_tds>`
- `git pull`

Avant de partir, tu fais :
- `cd <le_dossier_tds>` (revenir au dossier racine du dépôt)
- `git add -A` (ajouter aux changement tous les fichiers modifiés)
- `git commit -m "Ceci est un message qui explique mes changements."` (laisser un caillou derrière soi)
- `git pull` (Recevoir les derniers changements depuis qu'on a touché notre code)
- `git push origin master` (Envoyer les changements au serveur)
Bien sûr, il y a plus de détails à connaître mais globalement ça c'est suffisant pour commencer.

## Convention de nommage
Y'en a pas, on s'en fout.

Mais nommage conseillé pour pas foutre le bordel ^^ : `<nom_cours>/<nom_td>/<nom|surnom>/<file>`

## Précautions
La taille max. du dépôt est 1 Go.
C'est fait pour contenir du code source, **et surtout pas** des images, de l'audio etc.

Si ton fichier est léger ça passe. Mais s'il est lourd, faut pas encombrer le dépôt avec.
Crées donc un fichier `.gitignore` dans ton dossier et écris-y chaque fichier qui doit être ignoré par Git, dans ce dossier là.

Tu peux insérer des "wildcards" (jokers), genre :
```.gitignore
cape.png  # Ignorer cape.png (duh!)
*.png     # Ignorer tous les fichiers qui finissent par png juste ici.
images/** # Ignorer tous les fichiers contenus dans Images/.
**/*.png  # Ignorer tous les fichiers .png, ici et dans chaque sous-dossier.
```

## Trucs cools à faire
- Contribuer au wiki quand ça s'y prête;
- Ouvrir une Issue quand il y a un problème, ou pour des requêtes;
- Profiter de la vie
