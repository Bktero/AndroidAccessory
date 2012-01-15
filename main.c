/**
 * \file main.c
 * \brief Programme de test pour essayer de passer mon Samsung Teos en mode accessoire.
 * \author Pierre Gradot
 * \version 1.0
 * \date 31 Decembre 2011
 */

#include <stdlib.h>
#include <stdio.h>
#include <libusb-1.0/libusb.h>

// Remarque : la ligne suivante semble correspondre a la libusb-0.1
// #include <usb.h>

#include "comAndroid.h"
#define LIBUSB_DEBUG_ENABLED

int main(void)
{
	puts("Debut du programme");
	puts("------------------");

	// Contexte libusb
	libusb_context *pctx=NULL;

	// Initialisation du contexte usb
	puts("Initialisation du contexte...");
	if(0!=libusb_init(&pctx))
	{
		perror("Erreur lors de libusb_init");
		exit(EXIT_FAILURE);
	}

	// Activation du debug de la libusb
	#ifdef LIBUSB_DEBUG_ENABLED
	puts("Activation du debug de la libusb...");
	libusb_set_debug(pctx,3);
	#endif

	// Ouverture du telephone
    libusb_device_handle *teosHandle;

    unsigned int teosVendor_id = 0x04e8;
    unsigned int teosProduct_id =  0x6877;
    int teosError=0;

    // Recuperation d'un handle sur le teos
    teosHandle = phoneConnexionInit(pctx, teosVendor_id, teosProduct_id);
    if(NULL==teosHandle)
    {
        puts("Impossible d'obtenir un handle sur le teos");
    }
    else
    {
        // Communication avec le telephone
        puts("\nDebut de la communication avec le telephone...");

        handlePrintDescription(teosHandle);

        // Passage en mode accessoire
        puts("\nPassage en mode accessoire...");
        teosError = phoneActivateADKMode(teosHandle);
        if(0==teosError)
        {
            puts("Le teos est passe en mode accessoire");
        }
        else
        {
            printf("Echec... Resultat du passage en mode accessoire : %d\n\n",teosError);
        }
    }

    // Fin du traitement avec ce handle
    puts("Fermeture du handle...");
    if(NULL==teosHandle)
    {
        libusb_close(teosHandle);
    }

	// Fin du programme
	puts("Sortie du contexte...");
	libusb_exit(pctx);

    puts("------------------");
	puts("Fin du programme");
	return EXIT_SUCCESS;
}
