



Portage du DeviceServer TANGO SerialLine Linux vers WIN32

==========================================================



But

===



Le but de notre travail était de rendre possible l'utilisation sous WIN32 

du DeviceServer Serial Line Tango écrit par l'ESRF pour LINUX.



Le philosophie a donc consisté en :

 -garder la même interface 

- toucher au minimum au code existant pour (essayer) ne provoquer de regression de 

code sous Linux

- ajouter si besoin des methodes à l'interface existante pour améliorer l'ergonomie 





Séparation du code en 3 fichiers

=================================



Les fonctions dont les implémentations sont très différentes entre WIN32 et Linux ont été 

mises dans 2 fichiers différents: SerialWin32.cpp et SerialLinux.cpp



Le fichier Serial.cpp contient le code générique pour les 2 plateformes. 







Misc. changes

============



- replacement of cout and coutX by new Tango log streams

- ajout de commandes Tango pour simplifier l'utilisation depuis les clients : 



Sur les lectures: DevSerNcharReadString, 



sur le paramétrage : SetTimeOut, SetParity, SetBaudRate, ..



- le createFile n'utilise plus le OVERLAPPED afin d'avoir des ecritures synchrones sur la liaison série 

(et etre sur que le HW a bien recu la commande envoyée).



- la methode line_read_string gère maintenant le timeout



_ Il n'y a plus de flag OVERLAPPED, mais on conserve le pointeur sur la structure OVERLPPED pour que les commandes

READ et WRITE rendent la main seuleument quand elles ont terminées leur tâche.





// 23-10-2003



* Le fichier "SerialWin32.cpp" :



- Utilisation de #define de l'API Win32 pour la Parité, Bit de Stop et Char Length.



- Contient toutes les methodes utilisées pour la plateforme Linux (avec le même nom).



- la fonction "write_win32" inclu le caractere NULL.



- la fonction "serial_setparameter()" n'utilise plus la structure "COMMTIMEOUTS"







* le fichier "Serial.cpp" :

- contient des methodes pour changer chaque parametre individuellement, une methode "write_read()".







* le fichier "SerialLinux.cpp" :

- a ete mis à jour et correspond à l'interface implementee par l'ESRF (Manu Perez).

