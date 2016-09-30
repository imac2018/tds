# TDs
Un dépôt pour nos codes sources liés aux TDs.

## Pourquoi ?
- Pouvoir finir ses TDs à la maison, sans devoir s'envoyer ses propres fichiers à chaque fois;
- Pouvoir directement partager du code, sans besoin de Mail ou Facebook;
- Ca offre des pistes à ceux qui sont moins à l'aise, et ça reste pratique pour les autres;
- Apprendre (un peu) Git.
- Allez viens, on est bien !

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
