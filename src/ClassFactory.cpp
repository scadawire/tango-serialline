/*----- PROTECTED REGION ID(ClassFactory.cpp) ENABLED START -----*/
static const char *RcsId = "$Header: /users/chaize/newsvn/cvsroot/Communication/SerialLine/src/ClassFactory.cpp,v 1.6 2010-12-07 09:08:49 pascal_verdier Exp $";

//+=============================================================================

//

// file :        ClassFactory.cpp

//

// description : C++ source for the class_factory method of the DServer

//               device class. This method is responsible to create

//               all class singletin for a device server. It is called

//               at device server startup

//

// project :     TANGO Device Server

//

// $Author: pascal_verdier $

//

// $Revision: 1.6 $

//

// $Log: not supported by cvs2svn $
// Revision 1.5  2005/03/22 08:02:30  taurel
// - Ported to Tango V5
// - Added small changed from AG in the Windows part (One Sleep to calm down thing and
//   some management of 0 character)
//
// Revision 1.4  2004/11/02 11:40:23  xavela
// xavier :
// in Serial.cpp :
// add a delete to avoid memory leaks in Serial::Dev_Ser_Read_Char method.
// add, in Serial::Dev_Ser_Flush, | PURGE_RXABORT and | PURGE_TXABORT for the Win32 part.
//
// Revision 1.3  2004/10/22 14:17:01  xavela
// xavier : only in win32 part, possibility to open a port COM higher than 9.
// changed TANGO_ROOT_WIN32 by SOLEIL_ROOT in the makefile.vc.
//
// Revision 1.2  2004/06/30 09:22:48  xavela
// xavier : ajout de la methode dev_ser_read_nretry()
// pour la partie win32
//
// Revision 1.1.1.1  2004/04/07 14:30:54  syldup
// initial import
//

// Revision 1.3  2003/02/05 09:27:33  perez

// Makefile ported to omniORB

//

// Revision 1.2  2002/04/16 10:42:17  perez

// Port Makefile to libtango 2.0 and SuSE7.2

//

// Revision 1.1  2001/12/07 08:48:10  perez

// Fix cout bug + fix no update serialdevice.newline bug

//

// Revision 1.0  2001/11/26 14:38:12  perez

// Initial Revision (ported to TANGO2)

//

//

// copyleft :    European Synchrotron Radiation Facility

//               BP 220, Grenoble 38043

//               FRANCE

//

//-=============================================================================

//

//  		This file is generated by POGO

//	(Program Obviously used to Generate tango Object)

//

//         (c) - Software Engineering Group - ESRF

//=============================================================================





#include <tango.h>

#include <SerialClass.h>



/**

 *	Create SerialClass singleton and store it in DServer object.

 *

 * @author	$Author: pascal_verdier $

 * @version	$Revision: 1.6 $ $

 */



void Tango::DServer::class_factory()

{



	add_class(Serial_ns::SerialClass::init("Serial"));



}

/*----- PROTECTED REGION END -----*/
