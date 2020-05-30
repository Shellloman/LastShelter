CC=g++
CFLAGS=-Wall -g -I"include/"
LDFLAGS= -lSDL2 -lSDL2_image -lSDL2_ttf
OPTS =  -I"include/" -L"/usr/lib" lib/libIrrKlang.so -pthread
EXEC=bin/progT
PIECES = src/pieces/atelier.h src/pieces/dortoir.h src/pieces/eaupotable.h src/pieces/infirmerie.h src/pieces/milice.h src/pieces/reacteur.h src/pieces/refectoire.h src/pieces/salon.h
PIECESO = obj/atelier.o obj/dortoir.o obj/eaupotable.o obj/infirmerie.o obj/milice.o obj/reacteur.o obj/refectoire.o obj/salon.o

all: $(EXEC)

bin/progT : obj/jeu.o obj/main.o obj/piece.o obj/construction.o obj/liste.o obj/graphisme.o  obj/personnage.o obj/menu.o obj/stat.o obj/bouton.o obj/audio.o obj/mouv.o obj/alerte.o $(PIECESO) obj/inv.o obj/equip.o
	$(CC) -o $@ $^ $(LDFLAGS) $(OPTS)

obj/main.o : src/main.cpp src/jeu.h src/menu/menu.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/jeu.o : src/jeu.cpp src/jeu.h src/pieces/piece.h src/outils/construction.h src/outils/graphisme.h src/outils/stat.h src/outils/audio.h src/personnages/mouvement.h $(PIECES) src/outils/alerte.h src/personnages/equipement.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/piece.o : src/pieces/piece.cpp src/pieces/piece.h src/personnages/Personnage.h src/constante.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/atelier.o : src/pieces/atelier.cpp src/pieces/atelier.h src/pieces/piece.h src/personnages/Personnage.h src/constante.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/dortoir.o : src/pieces/dortoir.cpp src/pieces/dortoir.h src/pieces/piece.h src/personnages/Personnage.h src/constante.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/eaupotable.o : src/pieces/eaupotable.cpp src/pieces/eaupotable.h src/pieces/piece.h src/personnages/Personnage.h src/constante.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/infirmerie.o : src/pieces/infirmerie.cpp src/pieces/infirmerie.h src/pieces/piece.h src/personnages/Personnage.h src/constante.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/milice.o : src/pieces/milice.cpp src/pieces/milice.h src/pieces/piece.h src/personnages/Personnage.h src/constante.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/reacteur.o : src/pieces/reacteur.cpp src/pieces/reacteur.h src/pieces/piece.h src/personnages/Personnage.h src/constante.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/refectoire.o : src/pieces/refectoire.cpp src/pieces/refectoire.h src/pieces/piece.h src/personnages/Personnage.h src/constante.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/salon.o : src/pieces/salon.cpp src/pieces/salon.h src/pieces/piece.h src/personnages/Personnage.h src/constante.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/construction.o : src/outils/construction.cpp src/pieces/piece.h src/outils/construction.h src/outils/Liste.h $(PIECES) src/outils/alerte.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/liste.o : src/outils/Liste.cpp src/outils/Liste.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/personnage.o : src/personnages/Personnage.cpp src/personnages/Personnage.h src/constante.h src/personnages/equipement.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/menu.o : src/menu/menu.cpp src/menu/menu.h src/constante.h src/menu/bouton.h src/outils/audio.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/graphisme.o : src/outils/graphisme.cpp src/outils/graphisme.h src/pieces/piece.h src/outils/construction.h src/constante.h src/outils/stat.h src/outils/alerte.h src/personnages/equipement.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/stat.o : src/outils/stat.cpp src/outils/stat.h src/pieces/piece.h src/outils/alerte.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/bouton.o : src/menu/bouton.cpp src/menu/bouton.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/audio.o :src/outils/audio.cpp src/outils/audio.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/mouv.o : src/personnages/mouvement.cpp src/personnages/mouvement.h src/pieces/piece.h src/outils/alerte.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/alerte.o : src/outils/alerte.cpp src/outils/alerte.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/equip.o : src/personnages/equipement.cpp src/personnages/equipement.h
	$(CC) -o $@ -c $< $(CFLAGS)

obj/inv.o : src/personnages/inventaire.cpp src/personnages/inventaire.h src/personnages/equipement.h
	$(CC) -o $@ -c $< $(CFLAGS)

cleano:
	rm -rf obj/*
clean:
	rm -rf bin/*
	rm -rf obj/*
