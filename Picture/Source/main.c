//======================================================================//
// Projet Informatique: Indexation de Fichiers
//======================================================================//
// UPSSITECH L3 SMI 2013-2014
// Auteur: VEILLARD Aurélien
// Date de création: 18/11/13
//======================================================================//
// Fichier C: main.c
//======================================================================//
// Fonctions:
// - 
//======================================================================//

#include "openPicture.h"
#include <time.h>

//======================================================================//

int main(int argc, char* argv[]) {	
	FILE* picture = NULL;
	FILE* config = NULL;
	FILE* descriptor = NULL;
	FILE* log = NULL;
	time_t clock;
	
	int debug = 1;
	if(argc < 2) {
		fprintf(stderr, "> Bad utilisation: need filename\n");
		return EXIT_FAILURE; 
	}
	
	picture = fopen(argv[1], "r");	// Donc pour exécuter ./execute Data/xx.txt
	config = fopen("Config/picture.conf", "r");
	descriptor = fopen("Bases/descriptor.base", "a");
	
	if(debug) {
		log = fopen("Logs/trace.log", "a");
		time(&clock);
		fprintf(log, "#%s", ctime(&clock));
	}
	
	if(picture != NULL && config != NULL) {
		fprintf(log, "> Openning success: %s\n", argv[1]);
		fflush(stdout);
		openPict(picture, log, config, descriptor, argv[1]);
	} else if(picture == NULL){
		fprintf(log, "> ERROR: can't open picture\n");
		fflush(stdout);
	} else {
		fprintf(log, "> ERROR: can't open configuration file\n");
		fflush(stdout);
	}
	
	fclose(config);
	fclose(picture);
	
	fprintf(log, "> Indexation of '%s' done!\n", argv[1]);
	
	if(debug) {
		fprintf(log, "> Closing: %s\n", argv[1]);
		fclose(log);
	}
}