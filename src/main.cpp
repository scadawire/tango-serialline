/*PROTECTED REGION ID(Serial::main.cpp) ENABLED START*/
//=============================================================================
//
// file :        main.cpp
//
// description :  C++ source for a TANGO device server main.
//               The main rule is to initialise (and create) the Tango
//               system and to create the DServerClass singleton.
//               The main should be the same for every Tango device server.
//
// project :     TANGO Device Server.
//
// $Author: pascal_verdier $
//
// $Revision: 1.7 $
// $Date: 2010-12-07 09:12:53 $
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source: /users/chaize/newsvn/cvsroot/Communication/SerialLine/src/main.cpp,v $
// $Log: not supported by cvs2svn $
// Revision 1.6  2010/12/07 09:10:09  pascal_verdier
// Moved to Pogo-7 code generator.
//
// Revision 1.5  2010/10/06 21:42:30  vince_soleil
// Breakpad Migration
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
// Revision 1.1.1.1  2004/04/07 14:30:53  syldup
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
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================

#include <tango/tango.h>

#if defined(ENABLE_CRASH_REPORT)
# include <crashreporting/crash_report.h>
#else
# define DECLARE_CRASH_HANDLER
# define INSTALL_CRASH_HANDLER
#endif

DECLARE_CRASH_HANDLER;

int main(int argc,char *argv[])
{
	INSTALL_CRASH_HANDLER;

	Tango::Util *tg = 0;
	try

	{
		// Initialise the device server
		//----------------------------------------
		tg = Tango::Util::init(argc,argv);

		// Create the device server singleton 
		//	which will create everything
		//----------------------------------------
		tg->server_init(false);

		// Run the endless loop
		//----------------------------------------
                std::cout << "Ready to accept request" << std::endl;
		tg->server_run();
	}
	catch (std::bad_alloc)
	{
            std::cout << "Can't allocate memory to store device object !!!" << std::endl;
                std::cout << "Exiting" << std::endl;
	}
	catch (CORBA::Exception &e)
	{
		Tango::Except::print_exception(e);
                std::cout << "Received a CORBA_Exception" << std::endl;
                std::cout << "Exiting" << std::endl;
	}
	return(0);
}

/*PROTECTED REGION END*/	//	Serial::main.cpp
