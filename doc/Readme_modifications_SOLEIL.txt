



Portage du DeviceServer TANGO SerialLine Linux vers WIN32

==========================================================



But

===



Le but de notre travail �tait de rendre possible l'utilisation sous WIN32 

du DeviceServer Serial Line Tango �crit par l'ESRF pour LINUX.



Le philosophie a donc consist� en :

 -garder la m�me interface 

- toucher au minimum au code existant pour (essayer) ne provoquer de regression de 

code sous Linux

- ajouter si besoin des methodes � l'interface existante pour am�liorer l'ergonomie 





S�paration du code en 3 fichiers

=================================



Les fonctions dont les impl�mentations sont tr�s diff�rentes entre WIN32 et Linux ont �t� 

mises dans 2 fichiers diff�rents: SerialWin32.cpp et SerialLinux.cpp



Le fichier Serial.cpp contient le code g�n�rique pour les 2 plateformes. 







Misc. changes

============



- replacement of cout and coutX by new Tango log streams

- ajout de commandes Tango pour simplifier l'utilisation depuis les clients : 



Sur les lectures: DevSerNcharReadString, 



sur le param�trage : SetTimeOut, SetParity, SetBaudRate, ..



- le createFile n'utilise plus le OVERLAPPED afin d'avoir des ecritures synchrones sur la liaison s�rie 

(et etre sur que le HW a bien recu la commande envoy�e).



- la methode line_read_string g�re maintenant le timeout



_ Il n'y a plus de flag OVERLAPPED, mais on conserve le pointeur sur la structure OVERLPPED pour que les commandes

READ et WRITE rendent la main seuleument quand elles ont termin�es leur t�che.





// 23-10-2003



* Le fichier "SerialWin32.cpp" :



- Utilisation de #define de l'API Win32 pour la Parit�, Bit de Stop et Char Length.



- Contient toutes les methodes utilis�es pour la plateforme Linux (avec le m�me nom).



- la fonction "write_win32" inclu le caractere NULL.



- la fonction "serial_setparameter()" n'utilise plus la structure "COMMTIMEOUTS"







* le fichier "Serial.cpp" :

- contient des methodes pour changer chaque parametre individuellement, une methode "write_read()".







* le fichier "SerialLinux.cpp" :

- a ete mis � jour et correspond � l'interface implementee par l'ESRF (Manu Perez).

