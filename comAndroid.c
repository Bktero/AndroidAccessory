#include "comAndroid.h"

/**
 * \file comAndroid.c
 * \brief Fonctions pour le "open accessory mode" des telephones Android
 * \author Pierre Gradot
 * \version 1.0
 * \date 31 Decembre 2011
 *
 * Le fichier comAndroid.c contient les fonctions necessaires pour passer son telephone Android en mode accessoire.
 * Pour plus d'information sur le mode accessoire, vous pouvez visiter la page suivant de la documentation d'Android :
 * http://developer.android.com/guide/topics/usb/adk.html
 *
 * La communication avec le telephone est realisee en USB en utilisant la libusb-1.0.
 * Pour plus d'information et pour telecharger le libusb-1.0, vous pouvez visiter le site officiel de la bibliotheque :
 * http://www.libusb.org/
 */

 /**
 * \fn void handleGiveUp(libusb_device_handle *monHandle, const char* monMessage, const int libusbError)
 * \param monHandle : pointeur sur le handle USB a clore
 * \param monMessage : pointeur sur la chaine de caractere a afficher
 * \param libusbError : numero d'erreur de la libusb. Il sera converti en message texte grace a la fonction libusbErrorTranslate
 * \return void
 *
 * Cette fonction affiche les messages d'erreur et appelle la fonction (de libusb) libusb_close sur le handle passe en parametre.
 */
void handleGiveUp(libusb_device_handle *monHandle, const char* monMessage, const int libusbError)
{
    // Chaine correspondant au code erreur libusbError
    char* errorMessage = libusbErrorTranslate(libusbError);

    // Affichage des messages d'erreur
    puts("*** Une erreur est survenue...");

    // Affichage du message utilisateur
    printf("*** %s\n", monMessage);

    // Convertion du code d'erreur et affichage si succes
    if(NULL!=errorMessage)
    {
        printf("*** Erreur libusb = %s\n\n",errorMessage);
        free(errorMessage);
    }

    // Fermeture du handle
    libusb_close(monHandle);
}//handleGiveUp


 /**
 * \fn char* libusbErrorTranslate(const int errorNumber)
 * \param libusbError : numero d'erreur de la libusb a convertir
 * \return Pointeur sur caractere (char *), contenant le message correspondant.
 *
 * Cette fonction le code numerique d'erreur passe en parametre
 * et renvoit une chaine de caractere (char *) contenant le message correspondant.
 *
 * Attention ! La chaine retournee a ete allouee avec malloc() (taille de 100) et doit etre liberee a l'aide de free() !
 *
 * Pour rappel de la definition contenue dans libusb.h et utilisee pour convertir un code numerique en message texte :
 * libusb_error {
 * LIBUSB_SUCCESS = 0,
 * LIBUSB_ERROR_IO = -1,
 * LIBUSB_ERROR_INVALID_PARAM = -2,
 * LIBUSB_ERROR_ACCESS = -3,
 * LIBUSB_ERROR_NO_DEVICE = -4,
 * LIBUSB_ERROR_NOT_FOUND = -5,
 * LIBUSB_ERROR_BUSY = -6,
 * LIBUSB_ERROR_TIMEOUT = -7,
 * LIBUSB_ERROR_OVERFLOW = -8,
 * LIBUSB_ERROR_PIPE = -9,
 * LIBUSB_ERROR_INTERRUPTED = -10,
 * LIBUSB_ERROR_NO_MEM = -11,
 * LIBUSB_ERROR_NOT_SUPPORTED = -12,
 * LIBUSB_ERROR_OTHER = -99
 * }
 */
char* libusbErrorTranslate(const int errorNumber)
{
    char* errorMessage = (char*)malloc(100*sizeof(char));
    if(NULL==errorMessage)
    {
        puts("*** Fonction libusbErrorTranslate :");
        puts("*** Impossible d'allouer l'espace memoire pour stocker le message d'erreur de la libusb !");
        perror("*** Errno ");
    }

    switch(errorNumber)
    {
        case 0 :
            //errorMessage="LIBUSB_SUCCESS";
            strncpy (errorMessage, "LIBUSB_SUCCESS", 100);
            *(errorMessage+99)='\n';
            break;
        case -1 :
            //errorMessage="LIBUSB_ERROR_IO";
            strncpy (errorMessage, "LIBUSB_ERROR_IO", 100);
            *(errorMessage+99)='\n';
            break;
        case -2 :
            //errorMessage="LIBUSB_ERROR_INVALID_PARAM";
            strncpy (errorMessage, "LIBUSB_ERROR_INVALID_PARAM", 100);
            *(errorMessage+99)='\n';
            break;
        case -3:
            //errorMessage="LIBUSB_ERROR_ACCESS";
            strncpy (errorMessage, "LIBUSB_ERROR_ACCESS", 100);
            *(errorMessage+99)='\n';
            break;
        case -4 :
            //errorMessage="LIBUSB_ERROR_NO_DEVICE";
            strncpy (errorMessage, "LIBUSB_ERROR_NO_DEVICE", 100);
            *(errorMessage+99)='\n';
            break;
        case -5 :
            //errorMessage="LIBUSB_ERROR_NOT_FOUND";
            strncpy (errorMessage, "LIBUSB_ERROR_NOT_FOUND", 100);
            *(errorMessage+99)='\n';
            break;
        case -6 :
            //errorMessage="LIBUSB_ERROR_BUSY";
            strncpy (errorMessage, "LIBUSB_ERROR_BUSY", 100);
            *(errorMessage+99)='\n';
            break;
        case -7 :
            //errorMessage="LIBUSB_ERROR_TIMEOUT";
            strncpy (errorMessage, "LIBUSB_ERROR_TIMEOUT", 100);
            *(errorMessage+99)='\n';
            break;
        case -8 :
            //errorMessage="LIBUSB_ERROR_OVERFLOW";
            strncpy (errorMessage, "LIBUSB_ERROR_OVERFLOW", 100);
            *(errorMessage+99)='\n';
            break;
        case -9 :
            //errorMessage="LIBUSB_ERROR_PIPE";
            strncpy (errorMessage, "LIBUSB_ERROR_PIPE", 100);
            *(errorMessage+99)='\n';
            break;
        case -10 :
            //errorMessage="LIBUSB_ERROR_INTERRUPTED";
            strncpy (errorMessage, "LIBUSB_ERROR_INTERRUPTED", 100);
            *(errorMessage+99)='\n';
            break;
        case -11 :
            //errorMessage="LIBUSB_ERROR_NO_MEM";
            strncpy (errorMessage, "", 100);
            *(errorMessage+99)='\n';
            break;
        case -12 :
            //errorMessage="LIBUSB_ERROR_NOT_SUPPORTED";
            strncpy (errorMessage, "LIBUSB_ERROR_NOT_SUPPORTED", 100);
            *(errorMessage+99)='\n';
            break;
        case -99 :
            //errorMessage="LIBUSB_ERROR_OTHER";
            strncpy (errorMessage, "LIBUSB_ERROR_OTHER", 100);
            *(errorMessage+99)='\n';
            break;
        default :
            //errorMessage="(NONE)";
            strncpy (errorMessage, "(NONE)", 100);
            *(errorMessage+99)='\n';
    }

    return errorMessage;
}//libusbErrorTranslate



 /**
 * \fn libusb_device_handle* phoneConnexionInit(libusb_context *ptrContext, const unsigned int phoneVendor_id, const unsigned int phoneProduct_id)
 * \param ptrContext : pointeur sur le contexte USB a utiliser
 * \param phoneVendor_id : Vendor id du telephone
 * \param phoneProduct_id : Product id du telephone
 * \return Pointeur sur handle (libusb_device_handle), contenant le handle avec une interface ouverte vers le telephone ; NULL en cas d'erreur.
 *
 * Cette fonction realise les operations suivantes :
 *      - recuperation d'un handle sur le peripherique USB dont le vendor et le product ids ont ete donnes en parametres
 *      - detachement du "kernel driver" si necessaire
 *      - reclamation de l'interface
 */
libusb_device_handle* phoneConnexionInit(libusb_context *ptrContext, const unsigned int phoneVendor_id, const unsigned int phoneProduct_id)
{

    #ifdef PHONE_DEBUG_ENABLED
    puts("***** PHONE CONNECTION INIT *****");
    printf("Vendor id = %d ; Product id = %d\n", phoneVendor_id, phoneProduct_id);
    #endif

	// Handle sur le telephone : a retourner
    libusb_device_handle *phoneHandle=NULL;

    // Code d'erreur pour les fonctions de la libusb
    int libusbError=0;

    // Recuperation d'un handle sur le phone
    puts("Recuperation d'un handle sur le smartphone...");
    phoneHandle = libusb_open_device_with_vid_pid(ptrContext,phoneVendor_id,phoneProduct_id);

    // Verification du handle
    if(NULL==phoneHandle)
    {
        handleGiveUp(phoneHandle, "Impossible de se connecter au smartphone (handle NULL)", 1);
        return NULL;
    }
    else
    {
        // Detacher le kernel driver si besoin
        #ifdef PHONE_DEBUG_ENABLED
        puts("Verification du kernel driver...");
        #endif
        libusbError = libusb_kernel_driver_active(phoneHandle, 0);

        if(0!=libusbError && 1!=libusbError)
        {
            handleGiveUp(phoneHandle, "Impossible de connaitre l'etat du kernel driver", libusbError);
            return NULL;
        }
        else if(1==libusbError)
        {
            #ifdef PHONE_DEBUG_ENABLED
            puts("Le kernel driver est actif");
            puts("On tente de le detacher...");
            #endif
            libusbError = libusb_detach_kernel_driver(phoneHandle, 0);

            if(0!=libusbError)
            {
                handleGiveUp(phoneHandle, "Impossible de detacher le kernel driver", libusbError);
                return NULL;
            }
            #ifdef PHONE_DEBUG_ENABLED
            else
            {
                puts("Kernel driver detache avec succes");
            }
            #endif
        }
        #ifdef PHONE_DEBUG_ENABLED
        else
        {
            puts("Aucun besoin de detacher le kernel driver");
        }
        #endif

        // On reclame l'interface
        #ifdef PHONE_DEBUG_ENABLED
        puts("Reclamation de l'interface...");
        #endif
        libusbError = libusb_claim_interface(phoneHandle, 0);

        if(0!=libusbError)
        {
            handleGiveUp(phoneHandle, "Impossible de reclamer l'interface", libusbError);
            return NULL;
        }
        else
        {
            #ifdef PHONE_DEBUG_ENABLED
            puts("Interface obtenue !");
            puts("***** PHONE CONNECTION INIT OK *****");
            #endif
            return phoneHandle;
        }
    }//phoneHandle == NULL ?
}//phoneConnexionInit


 /**
 * \fn void handlePrintDescription(libusb_device_handle *monHandle)
 * \param monHandle : pointeur sur le handle USB a decrire
 * \return void
 *
 * Cette fonction tente de recuperer jusqu'a 10 fois une description sur l'appareil pointe par le handle en parametre.
 * A chaque recuperation, l'index de description est augmente de 1.
 * Si une recuperation echoue, la fonction sera termine prematurement.
 *
 * \bug Cette fonction est experimentale.
 */
void handlePrintDescription(libusb_device_handle *monHandle)
{
    #ifdef PHONE_DEBUG_ENABLED
    puts("***** HANDLE PRINT DESCRIPTION *****");
    #endif

    puts("Descriptif de l'appareil pointe :");
    unsigned char handleDescriptor[500]={0};
    int descId=0;
    int hError=0;
    char* hErrorMessage=NULL;

    for(descId=0;descId<10;descId++)
    {
        hError = libusb_get_string_descriptor_ascii (monHandle, descId, handleDescriptor, 500);
        if(0>hError)
        {
            puts("Pas possible de recuperer une description a cet indice, on s'arrete...");

            // Message d'erreur de la libusb
            hErrorMessage=libusbErrorTranslate(hError);
            if(NULL!=hErrorMessage)
            {
                printf("Erreur libusb = %s\n",hErrorMessage);
                free(hErrorMessage);
            }
            else
            {
                // On affiche le numero si impossible d'obtenir un message texte
                printf("Erreur libusb = %d\n",hError);
            }

            // Pour sortir de la boucle
            descId=10;
        }
        else
        {
            puts((const char*)handleDescriptor);
        }
    }

    #ifdef PHONE_DEBUG_ENABLED
    puts("***** HANDLE PRINT DESCRIPTION OK *****");
    #endif
}//handlePrintDescription


 /**
 * \fn int phoneActivateADKMode(libusb_device_handle *monHandle)
 * \param monHandle : pointeur sur le handle USB du telephone a passer en mode accessoire
 * \return Entier (int), indiquant si une erreur s'est produite ou pas (0 en cas de succes, inferieur a 0 en cas d'erreur)
 *
 * Cette fonction passe l'appareil en mode accessoire. Pour cela, elle :
 *      - recupere la version utilisee du protocole "open accessory" pour savoir si le telephone le supporte
 *      - presente l'appareil utilisateur de la fonction
 *      - demande au telephone de passer en mode accessoire
 *
 * \bug Ne possedant pas de telephone supportant le mode accessoire, les 2 dernieres etapes n'ont pas ete implementees.
 *
 */
int phoneActivateADKMode(libusb_device_handle *monHandle)
{
    #ifdef PHONE_DEBUG_ENABLED
    puts("***** PHONE ACTIVATE ADK MODE *****");
    #endif

    // Code retour
    int returnCode=0;

    // Code d'erreur des fonctions de la libusb
    int libusbError=0;

    // ADK protocol version (16 bits in little endian mode)
    unsigned char protocolVersion[2]={0,0};

    // On demande la version du protocole ADK utilisee
    #ifdef PHONE_DEBUG_ENABLED
    puts("\nDemande de la version utilisee du protocole ADK...");
    #endif
    libusbError = libusb_control_transfer(monHandle,
                                          LIBUSB_ENDPOINT_IN | LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE,
                                          ADK_GET_PROTOCOL,
                                          0,
                                          0,
                                          protocolVersion,
                                          2,
                                          1000);
    if(0>libusbError)
    {
        handleGiveUp(monHandle, "Impossible d'obtenir la version du protocole ADK utilisee", libusbError);
        returnCode=-1;
    }
    else
    {
        #ifdef PHONE_DEBUG_ENABLED
        printf("Version du protocole ADK obtenue avec succes (version = %s)\n",protocolVersion);
        #endif
        returnCode=0;
    }


    #ifdef PHONE_DEBUG_ENABLED
    if(0==returnCode)
    {
        puts("***** PHONE ACTIVATE ADK MODE OK *****");
    }
    else
    {
        puts("***** PHONE ACTIVATE ADK MODE KO *****");
    }
    #endif

    return returnCode;
}//phoneActivateADKMode
