/**
 * \file comAndroid.h
 * \brief Fonctions pour le mode accessoire des telephones Android
 * \author Pierre Gradot
 * \version 1.0
 * \date 31 Decembre 2011
 *
 * Le fichier comAndroid.h est le fichier d'en-tete du fichier comAndroid.c
 */
#ifndef COM_ANDROID_H
#define COM_ANDROID_H


/*--------------------------------------------------------------------------------------------------------------------
* Utilisation de bibliotheques
*/
#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*--------------------------------------------------------------------------------------------------------------------
* Definitions des constants et des macros
*/

/**
* \def PHONE_DEBUG_ENABLED
* Definir cette variable aura pour effet sur les fonctions du fichier comAndroid.c d'afficher plus de messages en console.
* Ces messages sont utiles pour debugguer l'application ou pour suivre plus en details son execution.
*/
#define PHONE_DEBUG_ENABLED


/**
* \def ADK_GET_PROTOCOL 51
* Code de la requete USB a envoyer au telephone pour obtenir la version utilisee du protocole ADK.
*/
#define ADK_GET_PROTOCOL 51



/*--------------------------------------------------------------------------------------------------------------------
* Prototypes des fonctions
*/
void handleGiveUp(libusb_device_handle *monHandle, const char* monMessage, const int libusbError);
void handlePrintDescription(libusb_device_handle *monHandle);
char* libusbErrorTranslate(const int errorNumber);
int phoneActivateADKMode(libusb_device_handle *monHandle);
libusb_device_handle* phoneConnexionInit(libusb_context *ptrContext, const unsigned int phoneVendor_id, const unsigned int phoneProduct_id);


#endif
