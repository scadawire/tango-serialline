import os
import sys

from PyTango import *
db = Database()
#
#  On declare 2 devices : 1 pour chaque port de communication
print "dÃ©claration devices"
com1_name="test/serial/com1"
com2_name="test/serial/com2"

#chaque device tourne dans 1 DeviceServer qui lui est propre
##dev_info_com1 = DbDevInfo()
##dev_info_com1.name = com1_name
##dev_info_com1._class = "Serial"
##dev_info_com1.server = "ds_Serial/com1"
##db.add_device(dev_info_com1)

# ajout device COM2 et son serveur
##dev_info_com2 = DbDevInfo()
##dev_info_com2.name = com2_name
##dev_info_com2._class = "Serial"
##dev_info_com2.server = "ds_Serial/com2"
##db.add_device(dev_info_com2)
## 
# On renseigne les propriétés de chaque device
##properties_com1= {'Serialline':["COM1"]}
##properties_com2= {'Serialline':["COM2"]}
##db.put_device_property(com1_name,properties_com1)
##db.put_device_property(com2_name,properties_com2)

com1= DeviceProxy(com1_name)
com2= DeviceProxy(com2_name)

print "fin dÃ©claration devices"
print ""
################################################
########    PARAMETRAGE DE LA LIAISON   ########
################################################
# Baudrate : 9600
com1.DevSerSetBaudrate(9600)
com2.DevSerSetBaudrate(9600)
# Parity : No
com1.DevSerSetParity(0)
com2.DevSerSetParity(0)
# Char Length : 8
com1.DevSerSetCharLength(0)
com2.DevSerSetCharLength(0)
# Stop Bit : 1
com1.DevSerSetStopbit(0)
com2.DevSerSetStopbit(0)
# Timeout : 1s
com1.DevSerSetTimeout(1000)
com2.DevSerSetTimeout(1000)
print "Fin de parametrage de la liaison : 9600, 8, N, 1\n"
print ""   

################################################
########    PURGE DES BUFFERRS DE COM   ########
################################################

octet = com2.DevSerGetNChar()
print "Octet(s) present(s) avant purge %d"%octet
print ""   
com1.DevSerFlush(2)  # 2 = flush Input and output
com2.DevSerFlush(2)
print "Purge des buffer de communication"
print ""   
octet = com2.DevSerGetNChar()
print "Octet(s) present(s) apres purge %d"%octet

################################################
######## 	DEBUT DES TESTS		########
################################################
##octet =[ 0x00,0x01,0x32,0x00,0x45,0x46,0x47,0x48,0x49,0x50]
##octet1 =[ 0x00,0x01,0x02,0x03,0x04,0x05,0x07,0x08,0x09,0x10]
##for i in range(10):
##    print "octet1[i] = %c"%octet1[i]
##nbchar=com1.DevSerWriteChar(octet)
##print "DevSerWriteChar envoyÃ© nchar=%d"%(nbchar)
##chaine_read = com2.DevSerReadNChar(len(octet))
##for i in range(nbchar):
##    print "Chaine bin lue : char i %uc"%(chaine_read[i])

print ""   
print "*************************************************************"
print "************** Test 1) DevSerReadRaw ************************"
print "*************************************************************"

chaine_to_send="salut"
octets_ecrits= com1.DevSerWriteString(chaine_to_send)
chaine_read= com2.DevSerReadRaw()

print "chaine_to_send = %s "%(chaine_to_send)

print "chaine_read = %s"%(chaine_read)

if chaine_to_send == chaine_read:
    print "Resultat DevSerReadLine : Chaine LUE = chaine ECRITE"
    print "Resultat OK"  
else:
    print "Alerte : test de DevSerWriteString/DevSerReadRaw ne fonctionne pas "
    print "BAD LUCK !!!"
    pass

print ""
print "*************************************************************"
print "************** Test 2) DevSerReadNChar  *********************"
print "*************************************************************"

chaine_to_send="salut"
octets_ecrits= com1.DevSerWriteString(chaine_to_send)
print "Chaine ecrite: debut de la lecture"
chaine_read= com2.DevSerReadNChar(len(chaine_to_send))
print "Resulat :: chaine lue = %s "%(chaine_read)
print" et chaine ecrite = %s"%(chaine_to_send)

if chaine_to_send == chaine_read:
    print " DevSerReadNChar : chaine LUE = chaine ECRITE"
    print "Resultat OK"
else:
    print "Alerte : test de DevSerWriteString/DevSerReadNChar ne fonctionne pas "
    print "BAD LUCK !!!"
    pass

print ""
com1.DevSerFlush(2)  # 2 = flush Input and output
com2.DevSerFlush(2)
print "Purge des buffer de communication"
print ""   

print "*************************************************************"
print "************** Test 3) DevSerReadLine  **********************"
print "*************************************************************"

print "*************************************************************"
print "************** Test sur les differents parametres  **********"
print "*************************************************************"
print "***Test 3-1 : NewLine () avec DevSerReadLine"
newline = input("Entrer newline :")
com1.DevSerSetNewline(newline)
com2.DevSerSetNewline(newline)
print "Envoi du nouveau caractere de fin de ligne : %d"%(newline)

#ouverture du fichier a lire
chaine_to_send= "Test newline avec ; entre les chaines ;"+"\n"+"\r"       #fichier Ã  ecrire sur le port (sous forme d'une string)
octets_ecrits= com1.DevSerWriteString(chaine_to_send)
print "Chaine envoyee :",chaine_to_send

#lecture de chaque ligne sur le port
chaine_read= com2.DevSerReadLine()
print "chaine lu avant le newline : %s"%(chaine_read)

print ""
com1.DevSerFlush(2)  # 2 = flush Input and output
com2.DevSerFlush(2)
print "Purge des buffer de communication"
print ""   
print "*************************************************************"
print ""

print "***Test 3-2 : NewBaudrate avec DevSerReadNChar"
newbaudrate=input("Entrer newbaudrate :")

com1.DevSerSetBaudrate(newbaudrate)
com2.DevSerSetBaudrate(newbaudrate)
print "Envoi du nouveau baudrate : %d"%(newbaudrate)

chaine_to_send="salut"+"\n"+"\r"
octets_ecrits= com1.DevSerWriteString(chaine_to_send)
chaine_read= com2.DevSerReadNChar(len(chaine_to_send))

print "chaine_read = %s"%(chaine_read)

print "chaine_to_send = %s "%(chaine_to_send)

if chaine_to_send == chaine_read:
    print " DevSerReadNChar : chaine LUE = chaine ECRITE"
    print "Resultat OK"
else:
    print "Alerte newbaudrate : DevSerWriteString/DevSerReadNChar ne fonctionne pas "
    print "BAD LUCK !!!"
    pass
print ""
com1.DevSerFlush(2)  # 2 = flush Input and output
com2.DevSerFlush(2)
print "Purge des buffer de communication"
print ""   

print "*************************************************************"
print "***Test 3-3-1 : 1 Stop avec DevSerReadLine"

stopbit = input("Entrer stopbit :")

com1.DevSerSetStopbit(stopbit)
com2.DevSerSetStopbit(stopbit)
print "Envoi du nouveau bit de stop : %d"%(stopbit)

chaine_to_send="salut"+"\n"+"\r"
octets_ecrits= com1.DevSerWriteString(chaine_to_send)
chaine_read= com2.DevSerReadLine()

print "chaine_read = %s"%(chaine_read)

print "chaine_to_send = %s"%(chaine_to_send)


if chaine_to_send == chaine_read:
    print "Resultat DevSerReadLine : Chaine LUE = chaine ECRITE"
    print "Resultat OK"  
else:
    print "Alerte stopbit %d: DevSerWriteString/DevSerReadLine ne fonctionne pas "%(stopbit)
    print "BAD LUCK !!!"
    pass

print ""
com1.DevSerFlush(2)  # 2 = flush Input and output
com2.DevSerFlush(2)
print "Purge des buffer de communication"
print ""   

print "***Test 3-3-2 : 2 Stop avec DevSerReadLine"
stopbit = input("Entrer stopbit :")
com1.DevSerSetStopbit(stopbit)
com2.DevSerSetStopbit(stopbit)
print "Envoi du nouveau bit de stop : %d"%(stopbit)

chaine_to_send="salut"+"\n"+"\r"
octets_ecrits= com1.DevSerWriteString(chaine_to_send)
chaine_read= com2.DevSerReadLine()

print "chaine_read = %s"%(chaine_read)

print "chaine_to_send = %s"%(chaine_to_send)


if chaine_to_send == chaine_read:
    print "Resultat DevSerReadLine : Chaine LUE = chaine ECRITE"
    print "Resultat OK"  
else:
    print "Alerte stopbit %d: test de DevSerWriteString/DevSerReadLine ne fonctionne pas "%(stopbit)
    print "BAD LUCK !!!"
    pass
print ""
com1.DevSerFlush(2)  # 2 = flush Input and output
com2.DevSerFlush(2)
print "Purge des buffer de communication"
print ""   
print "*************************************************************"

print "***Test 3-4 : TimeOut avec DevSerReadNChar"
timeout = input("Entrer timeout :")
print "Envoi du nouveau : %d"%(timeout)

com1.DevSerSetTimeout(timeout)
com2.DevSerSetTimeout(timeout)

chaine_to_send="salut"+"\n"+"\r"
octets_ecrits= com1.DevSerWriteString(chaine_to_send)
chaine_read= com2.DevSerReadNChar(len(chaine_to_send))

print "chaine_read = %s"%(chaine_read)

print "chaine_to_send = %s "%(chaine_to_send)

if chaine_to_send == chaine_read:
    print " DevSerReadNChar : chaine LUE = chaine ECRITE"
    print "Resultat OK"
else:
    print "Alerte timeout : DevSerWriteString/DevSerReadNChar ne fonctionne pas "
    print "BAD LUCK !!!"
    pass

print ""
com1.DevSerFlush(2)  # 2 = flush Input and output
com2.DevSerFlush(2)
print "Purge des buffer de communication"
print ""   

print "*************************************************************"
print "***Test 3-5 : Parity avec DevSerReadLine()"
parity = input("Entrer paritee :")
print "Envoi nouvelle parité : %d"%(parity)

com1.DevSerSetParity(parity)
com2.DevSerSetParity(parity)

chaine_to_send="salut"+"\n"+"\r"
octets_ecrits= com1.DevSerWriteString(chaine_to_send)
chaine_read= com2.DevSerReadLine()

print "chaine_read = %s"%(chaine_read)

print "chaine_to_send = %s "%(chaine_to_send)


if chaine_to_send == chaine_read:
    print "Resultat DevSerReadLine : Chaine LUE = chaine ECRITE"
    print "Resultat OK"  
else:
    print "Alerte parity : DevSerWriteString/DevSerReadLine ne fonctionne pas "
    print "BAD LUCK !!!"
    pass
print ""
com1.DevSerFlush(2)  # 2 = flush Input and output
com2.DevSerFlush(2)
print "Purge des buffer de communication"
print ""   

print "*************************************************************"
print "***Test 3-6 : CharLength avec DevSerReadLine"
charlength = input("Entrer charlength :")

com1.DevSerSetCharLength(charlength)
com2.DevSerSetCharLength(charlength)
print "Envoi du nouveau charlength : %d"%(charlength)

chaine_to_send="salut"+"\n"+"\r"
octets_ecrits= com1.DevSerWriteString(chaine_to_send)
chaine_read= com2.DevSerReadLine()

print "chaine_read = %s"%(chaine_read)

print "chaine_to_send = %s "%(chaine_to_send)


if chaine_to_send == chaine_read:
    print "Resultat DevSerReadLine : Chaine LUE = chaine ECRITE"
    print "Resultat OK"  
else:
    print "Alerte charlength : DevSerWriteString/DevSerReadLine ne fonctionne pas "
    print "BAD LUCK !!!"
    pass
print ""
com1.DevSerFlush(2)  # 2 = flush Input and output
com2.DevSerFlush(2)
print "Purge des buffer de communication"
print ""   

print "*************************************************************"


print "Fin tests"
