static const char *RcsId = "$Header: /users/chaize/newsvn/cvsroot/Communication/SerialLine/src/Serial.cpp,v 1.1.1.1 2004-04-07 14:30:53 syldup Exp $";
//+=============================================================================
//
// file :         Serial.cpp
//
// description :  C++ source for the Serial and its commands. 
//                The class is derived from Device. It represents the
//                CORBA servant object which will be accessed from the
//                network. All commands which can be executed on the
//                Serial are implemented in this file.
//
// project :      TANGO Device Server
//
// $Author: syldup $
//
// $Revision: 1.1.1.1 $
//
// $Log: not supported by cvs2svn $
// 
// changes from SOLEIL : 
//	

// Revision 1.3  2003/10/08 14:27:01  perez
// Fix bugs of strlen() on binary data
// Move from cout to logging
// Move timeout unit from 1/256 to mS
// Add higher baudrates
// Add error on invalid baudrate
// Fix bug in DevSerSetParameter() on parity
// Add DevSerFlush() command
// Add DevSerGetNChar() command
// Static buffer now belonging to object
// Cleanup logging and data dump

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
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


//===================================================================
//
//	The folowing table gives the correspondance
//	between commands and method's name.
//
//	Command's name	|	Method's name
//	----------------------------------------
//	State	|	dev_state()
//	Status	|	dev_status()
//	DevSerWriteString	|	dev_ser_write_string()
//	DevSerWriteChar	|	dev_ser_write_char()
//	DevSerReadString	|	dev_ser_read_string()
//	DevSerReadChar	|	dev_ser_read_char()
//	WriteRead	|	write_read()
//	DevSerGetNChar	|	dev_ser_get_nchar()
//	DevSerReadNChar	|	dev_ser_read_nchar()
//	DevSerReadRaw	|	dev_ser_read_raw()
//	DevSerReadLine	|	dev_ser_read_line()
//	DevSerFlush	|	dev_ser_flush()
//	DevSerSetParameter	|	dev_ser_set_parameter()
//	DevSerSetTimeout	|	dev_ser_set_timeout()
//	DevSerSetParity	|	dev_ser_set_parity()
//	DevSerSetCharLength	|	dev_ser_set_char_length()
//	DevSerSetStopbit	|	dev_ser_set_stopbit()
//	DevSerSetBaudrate	|	dev_ser_set_baudrate()
//	DevSerSetNewline	|	dev_ser_set_newline()
//
//===================================================================

#include <tango.h>
#include <Serial.h>
#include <stdio.h>
#include <errno.h>

#ifdef __linux
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#endif


namespace Serial
{

#ifdef WIN32
	// all methods containing WIN32 API calls
#include "SerialWin32.cpp"
#endif

#ifdef __linux
	// all methods containing Linux API calls
#include "SerialLinux.cpp"
#endif

//+----------------------------------------------------------------------------
//
// method : 		Serial::Serial(string &s)
// 
// description : 	constructor for simulated Serial
//
// in : - cl : Pointer to the DeviceClass object
//      - s : Device name 
//
//-----------------------------------------------------------------------------
Serial::Serial(Tango::DeviceClass *cl,string &s):Tango::Device_2Impl(cl,s.c_str())
{
	init_device();
}

Serial::Serial(Tango::DeviceClass *cl,const char *s):Tango::Device_2Impl(cl,s)
{
	init_device();
}

Serial::Serial(Tango::DeviceClass *cl,const char *s,const char *d)
	:Tango::Device_2Impl(cl,s,d)
{
	init_device();
}

void Serial::init_device()
{
Tango::DevVarLongArray argin_array;
char           tab[]="Serial::init_device(): ";

	
	INFO_STREAM << "Serial::Serial() create device " << device_name << endl;
	
	// Initialise variables to default values
	//--------------------------------------------
	
	// Initialise variables to default values
	//
	serialdevice.serialline    = NULL;
#ifdef __linux
	serialdevice.serialin      = 0;
	serialdevice.serialout     = 0;
#endif
	serialdevice.timeout       = 100;
	serialdevice.parity        = SL_NONE;
	serialdevice.charlength    = SL_DATA8;
	serialdevice.stopbits      = SL_STOP1;
	serialdevice.baudrate      = 9600;
	serialdevice.newline       = 13;
	serialdevice.xon           = 0;
	serialdevice.xoff          = 0;
	serialdevice.upper         = 0;
	serialdevice.erase         = 0;
	serialdevice.echo          = 0;
	serialdevice.linefeed      = 0;
	serialdevice.null          = 0;
	serialdevice.backspace     = 0;
	serialdevice.del           = 0;
	
	// Read device resources from database
	serialline   = "";
	timeout      = -1;
	parity       = "";
	charlength   = -1;
	stopbits     = -1;
	baudrate     = -1;
	newline      = -1;
	
	DEBUG_STREAM << tab << "calling get_device_property()" << endl;
	
	get_device_property();
	
	DEBUG_STREAM << tab << "serialline:"   << serialline   << endl;
	DEBUG_STREAM << tab << "timeout:"      << timeout      << endl;
	DEBUG_STREAM << tab << "parity:"       << parity       << endl;
	DEBUG_STREAM << tab << "charlength:"   << charlength   << endl;
	DEBUG_STREAM << tab << "stopbits:"     << stopbits     << endl;
	DEBUG_STREAM << tab << "baudrate:"     << baudrate     << endl;
	DEBUG_STREAM << tab << "newline:"      << newline      << endl;

	
	// Mandatory properties
	if(serialline == "")
	{
		TangoSys_MemStream out_stream;
		out_stream << "serialline property not defined in the database" << ends;
		
		ERROR_STREAM << tab << out_stream.str() << endl;
		Tango::Except::throw_exception(
			(const char *)"Serial::error_resources",
			out_stream.str(),
        (const char *)tab);
	}
	serialdevice.serialline = serialline.c_str();
	
	// If timeout specified update the object
	if(timeout != -1)
	{
		serialdevice.timeout = timeout;
		DEBUG_STREAM << tab << "timeout set to: " 
			<< serialdevice.timeout << "(mS)" << endl;
	}
	
	// If parity specified then convert it to an integer
	if (parity != "")
	{
		if (parity == "even")
		{
			this->serialdevice.parity = SL_EVEN;
			DEBUG_STREAM << tab << "parity set to: SL_EVEN" << endl;
		}
		else
		{
			if (parity == "odd")
			{
				this->serialdevice.parity = SL_ODD;
				DEBUG_STREAM << tab << "parity set to: SL_ODD" << endl;
			}
			else
			{
				this->serialdevice.parity = SL_NONE;
				DEBUG_STREAM << tab << "parity set to: SL_NONE" << endl;
			}
		}
	}

	// Do the same for the number of data bits
	switch(charlength)
	{
	case 5:
		this->serialdevice.charlength = SL_DATA5;
		DEBUG_STREAM << "Serial::init_device()::charlength set to: SL_DATA5" << endl;
		break;
	case 6:
		this->serialdevice.charlength = SL_DATA6;
		DEBUG_STREAM << "Serial::init_device()::charlength set to: SL_DATA6" << endl;
		break;
	case 7:
		this->serialdevice.charlength = SL_DATA7;
		DEBUG_STREAM << "Serial::init_device()::charlength set to: SL_DATA7" << endl;
		break;
	case 8:
		this->serialdevice.charlength = SL_DATA8;
		DEBUG_STREAM << "Serial::init_device()::charlength set to: SL_DATA8" << endl;
		break;
	default:
		break;
	}
	
	// Do the same for the number of stop bits, note 1.5 stopbits
	// are not supported via the database !
	switch(stopbits)
	{
	case 1:
		this->serialdevice.stopbits = SL_STOP1;
		DEBUG_STREAM << "Serial::init_device()::stopbits set to: SL_STOP1" << endl;
		break;
	case 2:
		this->serialdevice.stopbits = SL_STOP2;
		DEBUG_STREAM << "Serial::init_device()::stopbits set to: SL_STOP2" << endl;
		break;
	default:
		break;
	}
	
	// If baudrate specified update the object
	if(baudrate != -1)
	{
		serialdevice.baudrate = baudrate;
		DEBUG_STREAM << "Serial::init_device()::baudrate set to:"
			<< serialdevice.baudrate     << endl;
	}
	
	// If timeout specified update the object
	if(newline != -1)
	{
		serialdevice.newline = newline;
		DEBUG_STREAM << "Serial::init_device()::newline set to:"
			<< serialdevice.newline     << endl;
	}
	
	// Configure the serial line if there were defined in the database
	if (this->serialdevice.serialline != NULL)
	{
		// Open the serial line
		open_desc();

		// Setup input serial line with device's default values
		argin_array.length(12);
		argin_array[0]        = SL_TIMEOUT;
		argin_array[1]        = this->serialdevice.timeout;
		
		argin_array[2]        = SL_PARITY;
		argin_array[3]        = this->serialdevice.parity;
		
		argin_array[4]        = SL_CHARLENGTH;
		argin_array[5]        = this->serialdevice.charlength;
		
		argin_array[6]        = SL_STOPBITS;
		argin_array[7]        = this->serialdevice.stopbits;
		
		argin_array[8]        = SL_BAUDRATE;
		argin_array[9]        = this->serialdevice.baudrate;
		
		argin_array[10]       = SL_NEWLINE;
		argin_array[11]       = this->serialdevice.newline;
		
		// now do the serial line real initialisation 
		dev_ser_set_parameter(&argin_array);

	}
	else
	{
		// This can not happen because the test on serialline took place earlier
		FATAL_STREAM << "Serial::Serial():no serial line to initialise !" << endl;
	}
	
}
//+----------------------------------------------------------------------------
//
// method : 		Serial::delete_device()
// 
// description : will be called at device destruction or at init command.
//
//-----------------------------------------------------------------------------

void Serial::delete_device()
{
#ifdef WIN32
	close_handle_win32();
#endif

}
//+----------------------------------------------------------------------------
//
// method : 		Serial::readDeviceProperies()
// 
// description : 	Read the device properties from database.
//
//-----------------------------------------------------------------------------
void Serial::get_device_property()
{
	//	Initialize your default values here.
	//------------------------------------------
	
	
	//	Read device properties from database.(Automatic code generation)
	//-------------------------------------------------------------
	Tango::DbData	data;
	data.push_back(Tango::DbDatum("Serialline"));
	data.push_back(Tango::DbDatum("Timeout"));
	data.push_back(Tango::DbDatum("Parity"));
	data.push_back(Tango::DbDatum("Charlength"));
	data.push_back(Tango::DbDatum("Stopbits"));
	data.push_back(Tango::DbDatum("Baudrate"));
	data.push_back(Tango::DbDatum("Newline"));

	//	Call database and extract values
	//--------------------------------------------
	get_db_device()->get_property(data);
	if (data[0].is_empty()==false)	data[0]  >>  serialline;
	if (data[1].is_empty()==false)	data[1]  >>  timeout;
	if (data[2].is_empty()==false)	data[2]  >>  parity;
	if (data[3].is_empty()==false)	data[3]  >>  charlength;
	if (data[4].is_empty()==false)	data[4]  >>  stopbits;
	if (data[5].is_empty()==false)	data[5]  >>  baudrate;
	if (data[6].is_empty()==false)	data[6]  >>  newline;


	//	End of Automatic code generation
	//-------------------------------------------------------------
	
}

//+----------------------------------------------------------------------------
//
// method : 		Serial::always_executed_hook()
// 
// description : 	method always executed before any command is executed
//
//-----------------------------------------------------------------------------
void Serial::always_executed_hook()
{
	
	DEBUG_STREAM << "In always_executed_hook method" << endl;
	
}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_write_string
 *
 *	description:	method to execute "DevSerWriteString"
 *	Write a string of characters to a serial line and return
 *	the number of characters written.
 *
 * @param	argin	String to write
 * @return	Number of characters written
 *
 */
//+------------------------------------------------------------------
Tango::DevLong Serial::dev_ser_write_string(Tango::DevString argin)
{
	long            nchar;
	Tango::DevLong	argout ;
	
	//	Add your own code to control device here
	DEBUG_STREAM << "Serial::dev_ser_write_string(): writing: " << argin << endl;
	
	
#ifdef __linux
	nchar = write(
        this->serialdevice.serialout,
        argin,
        strlen(argin));
#endif
	
#ifdef WIN32
	nchar = write_win32(argin);
#endif

//		If error writing data then warn client 
	if (nchar < 0)
	{
		TangoSys_MemStream out_stream;
		
#ifdef __linux
		out_stream << "error writing to device, errno: " << errno;
		if(errno == ETIMEDOUT)
			out_stream << " (timeout)";
		out_stream << ends;
#endif
#ifdef WIN32
		DWORD LastError = GetLastError();
		out_stream << "error writing to device( number :" << LastError << ")" << ends;
#endif 
		
		ERROR_STREAM << "Serial::dev_ser_write_string(): " << out_stream.str() << endl;
		
		Tango::Except::throw_exception(
			(const char *)"Serial::error_write",
			out_stream.str(),
			(const char *)"Serial::dev_ser_write_string");
	}
	
	argout = nchar;
	return argout;
}


//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_write_char
 *
 *	description:	method to execute "DevSerWriteChar"
 *	Write N characters to a seria line and return the
 *	number of characters written.
 *
 * @param	argin	Characters to write
 * @return	Number of characters written
 *
 */
//+------------------------------------------------------------------
Tango::DevLong Serial::dev_ser_write_char(const Tango::DevVarCharArray *argin)
{
 int            nchar;
 int            i;
 Tango::DevLong	argout ;
 char           tab[]="Serial::dev_ser_write_char(): ";
 INFO_STREAM << tab << "entering... !" << endl;

 INFO_STREAM << tab << "char to write:";
 char tab2[]="    ";
 TangoSys_MemStream os;
 for(i=0;i<argin->length();i++)
 {
  this->serialdevice.buffer[i] = (*argin)[i];

  if ( (*argin)[i]>32 )
   os << tab2 << "'" << (*argin)[i] << "'";
  else
   os << tab2 << "' '";

  os << " 0x" << std::hex << (int)((*argin)[i]) << ends;

  INFO_STREAM << os.str() << endl;

  os.seekp(0);
  os.seekg(0);
 }
	
	// won't be sent to serial line, for printout only
 this->serialdevice.buffer[i]=0; 
#ifdef __linux
	nchar = write(
        this->serialdevice.serialout,
        this->serialdevice.buffer,
        argin->length());
#endif
	
#ifdef WIN32
	nchar = write_win32_bin_char_array(argin);
#endif

	//	If error writing data then warn client 
	if (nchar < 0) 
	{
		TangoSys_MemStream out_stream;
		
#ifdef __linux
		out_stream << "error writing to device, errno: " << errno;
		if(errno == ETIMEDOUT)
			out_stream << " (timeout)";
		
		out_stream << ends;
#endif
#ifdef WIN32
		out_stream << "error writing to device" << ends;
#endif 
		
		ERROR_STREAM << "Serial::dev_ser_write_char(): " << out_stream.str() << endl;

		ERROR_STREAM << tab << out_stream.str() << endl;
		Tango::Except::throw_exception(
			(const char *)"Serial::error_write",
			out_stream.str(),
			(const char *)tab);
	}
	
	argout = nchar;
	return argout;
}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_read_nchar
 *
 *	description:	method to execute "DevSerReadNChar"
 *	Read a string of N characters from the serial line
 *	If there are no characters to be read returns an empty string.
 *
 * @param	argin	number of the caracters to read on the serial line
 * @return	pointer to the string read updated
 *
 */
//+------------------------------------------------------------------
Tango::DevString Serial::dev_ser_read_nchar(Tango::DevLong argin)
{
	//	POGO has generated a method core with argout allocation.
	//	If you would like to use a static reference without copying,
	//	See "TANGO Device Server Programmer's Manual"
	//		(chapter : Writing a TANGO DS / Exchanging data)
	//------------------------------------------------------------
	Tango::DevString	argout;
	
	DEBUG_STREAM << "Serial::dev_ser_nchar_read_string(): entering... !" << endl;

	//	Add your own code to control device here
    argout = nchar_read_string(argin);

	return argout;
}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_read_raw
 *
 *	description:	method to execute "DevSerReadRaw"
 *	read a string from the serialline device in mode raw (no end
 *	of string expected, just empty the entire serialline receiving buffer).
 *
 * @return	pointer to the string read updated
 *
 */
//+------------------------------------------------------------------
Tango::DevString Serial::dev_ser_read_raw()
{
	//	POGO has generated a method core with argout allocation.
	//	If you would like to use a static reference without copying,
	//	See "TANGO Device Server Programmer's Manual"
	//		(chapter : Writing a TANGO DS / Exchanging data)
	//------------------------------------------------------------
	Tango::DevString	argout;

	DEBUG_STREAM << "Serial::dev_ser_raw_read_string(): entering... !" << endl;

	//	Add your own code to control device here
	argout = raw_read_string ( );

	return argout;
}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_read_line
 *
 *	description:	method to execute "DevSerReadLine"
 *	read a string from the serialline device in mode line (up to
 *	and including the character specified by the NewLine property
 *
 * @return	pointer to the string read updated
 *
 */
//+------------------------------------------------------------------
Tango::DevString Serial::dev_ser_read_line()
{
	//	POGO has generated a method core with argout allocation.
	//	If you would like to use a static reference without copying,
	//	See "TANGO Device Server Programmer's Manual"
	//		(chapter : Writing a TANGO DS / Exchanging data)
	//------------------------------------------------------------
	Tango::DevString	argout ;

	DEBUG_STREAM << "Serial::dev_ser_read_line(): entering... !" << endl;

	//	Add your own code to control device here
	argout = line_read_string( );

	return argout;
}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_set_timeout
 *
 *	description:	method to execute "DevSerSetTimeout"
 *	This command sets the new timeout (in ms).
 *
 * @param	argin	Value of the timeout to set
 *
 */
//+------------------------------------------------------------------
void Serial::dev_ser_set_timeout(Tango::DevShort argin)
{
	
	Tango::DevVarLongArray argin_array ;

	DEBUG_STREAM << "Serial::dev_ser_set_timeout(): entering... !" << endl;

	//	Add your own code to control device here
	
	// Setup input serial line with device's new value of timeout
	argin_array.length(2);
	argin_array[0] = SL_TIMEOUT;
	argin_array[1] = argin;

	try
	{
		// now do the serial line real initialisation 
		dev_ser_set_parameter(&argin_array);
	}
	catch (Tango::DevFailed & )

	{
		ERROR_STREAM << "dev_ser_set_timeout: error setting new timeout" << endl;
			Tango::Except::throw_exception(
				(const char *)"Serial::dev_ser_set_parameter",
				(const char*) "Error setting new timeout",
				(const char *)"Serial::dev_ser_set_timeout");

	}

}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_set_parity
 *
 *	description:	method to execute "DevSerSetParity"
 *	Sets the new parity of the serial line.
 *	NONE 0
 *	ODD 1
 *	EVEN 3
 *
 * @param	argin	The new parity to set.
 *
 */
//+------------------------------------------------------------------
void Serial::dev_ser_set_parity(Tango::DevShort argin)
{
	Tango::DevVarLongArray argin_array;

	DEBUG_STREAM << "Serial::dev_ser_set_parity(): entering... !" << endl;

	//	Add your own code to control device here

	// Setup input serial line with device's new value of parity
	argin_array.length(2);
	argin_array[0] = SL_PARITY;
	argin_array[1] = argin;

	try
	{
		// now do the serial line real initialisation 
		dev_ser_set_parameter(&argin_array);
	}
	catch (Tango::DevFailed & )

	{
		ERROR_STREAM << "dev_ser_set_parity: error setting new parity" << endl;
			Tango::Except::throw_exception(
				(const char *)"Serial::dev_ser_set_parameter",
				(const char *) "Error setting new parity",
				(const char *)"Serial::dev_ser_set_parity");
	}

}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_set_stopbit
 *
 *	description:	method to execute "DevSerSetStopbit"
 *	Sets the new stop bit.
 *	0 = none
 *	1 = one stop
 *	2 = 1.5 stop bit
 *
 * @param	argin	The new stopbit to set
 *
 */
//+------------------------------------------------------------------
void Serial::dev_ser_set_stopbit(Tango::DevShort argin)
{
	Tango::DevVarLongArray argin_array;

	DEBUG_STREAM << "Serial::dev_ser_set_stopbit(): entering... !" << endl;

	//	Add your own code to control device here

	// Setup input serial line with device's new value of stopbit
	argin_array.length(2);
	argin_array[0] = SL_STOPBITS;
	argin_array[1] = argin;

	try
	{
		// now do the serial line real initialisation 
		dev_ser_set_parameter(&argin_array);
	}
	catch (Tango::DevFailed &  )

	{
		ERROR_STREAM << "dev_ser_set_stopbit: error setting new stopbit" << endl;
			Tango::Except::throw_exception(
				(const char *)"Serial::dev_ser_set_parameter",
				(const char *) "Error setting new stopbit",
				(const char *)"Serial::dev_ser_set_stopbit");

	}

}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_set_baudrate
 *
 *	description:	method to execute "DevSerSetBaudrate"
 *	Sets the new baudrateof the serial line ( up to 4 Mega).
 *	Default is 9600.
 *
 * @param	argin	The new baudrate to set
 *
 */
//+------------------------------------------------------------------
void Serial::dev_ser_set_baudrate(Tango::DevULong argin)
{
	Tango::DevVarLongArray argin_array;

	DEBUG_STREAM << "Serial::dev_ser_set_baudrate(): entering... !" << endl;

	//	Add your own code to control device here

	// Setup input serial line with device's new value of baudrate
	argin_array.length(2);
	argin_array[0] = SL_BAUDRATE;
	argin_array[1] = argin;

	try
	{
		// now do the serial line real initialisation 
		dev_ser_set_parameter(&argin_array);
	}
	catch (Tango::DevFailed & )

	{
		ERROR_STREAM << "dev_ser_set_baudrate: error setting new baudrate" << endl;
			Tango::Except::throw_exception(
				(const char *)"Serial::dev_ser_set_parameter",
				(const char*) "Error setting new baudrate",
				(const char *)"Serial::dev_ser_set_baudrate");

	}

}


//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_set_newline
 *
 *	description:	method to execute "DevSerSetNewline"
 *	The new ending character in hexa.
 *	Default is 0x13 (=CR
 *
 * @param	argin	The new line character to set
 *
 */
//+------------------------------------------------------------------
void Serial::dev_ser_set_newline(Tango::DevShort argin)
{
	Tango::DevVarLongArray argin_array;

	DEBUG_STREAM << "Serial::dev_ser_set_newline(): entering... !" << endl;

	//	Add your own code to control device here

	// Setup input serial line with device's new value of newline
	argin_array.length(2);
	argin_array[0] = SL_NEWLINE;
	argin_array[1] = argin;

	try
	{
		// now do the serial line real initialisation 
		dev_ser_set_parameter(&argin_array);
	}
	catch (Tango::DevFailed & )

	{
		ERROR_STREAM << "dev_ser_set_newline: error setting new newline" << endl;
			Tango::Except::throw_exception(
				(const char *)"Serial::dev_ser_set_parameter",
				(const char *) "Error setting new newline",
				(const char *)"Serial::dev_ser_set_newline");

	}
}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_set_char_length
 *
 *	description:	method to execute "DevSerSetCharLength"
 *	Sets the new charlength.
 *	0 = 8 bits
 *	1 = 7 bits
 *	2 = 6 bits
 *	3 = 5 bits
 *
 * @param	argin	The new charlength to set
 *
 */
//+------------------------------------------------------------------
void Serial::dev_ser_set_char_length(Tango::DevShort argin)
{

	Tango::DevVarLongArray argin_array;

	DEBUG_STREAM << "Serial::dev_ser_set_char_length(): entering... !" << endl;

	//	Add your own code to control device here

	// Setup input serial line with device's new value of charlength
	argin_array.length(2);
	argin_array[0] = SL_CHARLENGTH;
	argin_array[1] = argin;

	try
	{
		// now do the serial line real initialisation 
		dev_ser_set_parameter(&argin_array);
	}
	catch (Tango::DevFailed & )

	{
		ERROR_STREAM << "dev_ser_set_charlength: error setting new charlength" << endl;
			Tango::Except::throw_exception(
				(const char *)"Serial::dev_ser_set_parameter",
				(const char*) "Error setting new charlength",
				(const char *)"Serial::dev_ser_set_char_length");

	}


}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_set_parameter
 *
 *	description:	method to execute "DevSerSetParameter"
 *	Set serial line parameters
 *
 * @param	argin	device parameters in pair
 *
 */
//+------------------------------------------------------------------
void Serial::dev_ser_set_parameter(const Tango::DevVarLongArray *argin)
{

#ifdef __linux
	dev_ser_set_parameter_linux(argin);
#endif
	
#ifdef WIN32
	dev_ser_set_parameter_win32(argin);
#endif

}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_read_string
 *
 *	description:	method to execute "DevSerReadString"
 *	Win32 method :
 *	Read a string of characters, the type of read is specified in the
 *	input parameter SL_RAW SL_NCHAR SL_LINE
 *
 * @param	argin	type of read SL_RAW SL_NCHAR SL_LINE
 * @return	String read
 *
 */
//+------------------------------------------------------------------
Tango::DevString Serial::dev_ser_read_string(Tango::DevLong argin)
{
 long              read_type;
 long              nchar;
 Tango::DevString  argout;
 char              tab[]="Serial::dev_ser_read_string(): ";


	INFO_STREAM << tab << "entering... !" << endl;
	read_type = argin & 0x000f;

	switch (read_type)
	{
		case SL_RAW :
			INFO_STREAM << tab << "SL_RAW" << endl;
			argout = raw_read_string();
			break;
		case SL_NCHAR :
			nchar = argin >> 8;
			INFO_STREAM << tab << "SL_NCHAR nchar="<< nchar << endl;
			argout = nchar_read_string(nchar);
			break;
		case SL_LINE :
			INFO_STREAM << tab << "SL_LINE" << endl;
			argout = line_read_string();
			break;

		default :
			TangoSys_MemStream out_stream;
			out_stream << "unknown type of read, must be SL_RAW, SL_NCHAR, SL_LINE"
					   << ends;

			ERROR_STREAM << tab << out_stream.str() << endl;
			Tango::Except::throw_exception(
				   (const char *)"Serial::error_argin",
				   out_stream.str(),
				   (const char *)tab);						
	}

	INFO_STREAM << tab << "returning: " << argout << endl;
	return argout;
}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_read_char
 *
 *	description:	method to execute "DevSerReadChar"
 *	Win32 method :
 *	Read an array of characters, the type of read is specified in the
 *	input parameter, it can be SL_RAW SL_NCHAR SL_LINE
 *
 * @param	argin	type of read SL_RAW SL_NCHAR SL_LINE
 * @return	Array of characters read
 *
 */
//+------------------------------------------------------------------
Tango::DevVarCharArray *Serial::dev_ser_read_char(Tango::DevLong argin)
{
// SOLEIL Copy and allocation mechanism has been changed between DevString and DevVarCharArray
// and is now
// 
 Tango::DevString	string_argout;
 long				read_type;
 long				nchar;
 char				tab[]="Serial::dev_ser_read_char(): ";

 INFO_STREAM << tab << "entering... !" << endl;

 read_type = argin & 0x000f;


 switch (read_type)
 {
  case SL_RAW :
        INFO_STREAM << tab << "SL_RAW" << endl;
        string_argout = raw_read_string();
        break;
  case SL_NCHAR :
		nchar = argin >> 8;
        INFO_STREAM << tab << "SL_NCHAR nchar = " << nchar << endl;
        string_argout = nchar_read_string(nchar);
        break;
  case SL_LINE :
        INFO_STREAM << tab << "SL_LINE" << endl;
        string_argout = line_read_string();
        break;

  default :
        TangoSys_MemStream out_stream;
        out_stream << "unknown type of read, must be SL_RAW, SL_NCHAR, SL_LINE"
                   << ends;

        ERROR_STREAM << tab << out_stream.str() << endl;
        Tango::Except::throw_exception(
               (const char *)"Serial::error_argin",
               out_stream.str(),
               (const char *)tab);
 }

 //
 // Convert Tango::DevString to Tango_DevVarCharArray
 //
 size_t	len = this->serialdevice.ncharread;
 
 CORBA::Octet* buf = Tango::DevVarCharArray::allocbuf (len);
 
 // memory check
 if ( !buf )
 {
	TangoSys_MemStream out_stream;
	out_stream << "Tango::DevVarCharArray::allocbuf(len) : out of memory" << ends;

	ERROR_STREAM << tab << out_stream.str() << endl;
	Tango::Except::throw_exception(
		   (const char *)"Serial::memory not allocated",
		   out_stream.str(),
		   (const char *)tab);
 }
 
 // now we can make the copy
 ::memcpy(buf, string_argout, len);

 // copy with constructor in release (1), so it deallocates the memory itself
 Tango::DevVarCharArray* argout = new Tango::DevVarCharArray(len, len, buf, 1);
 
 // memory check
 if ( !argout )
 {
	TangoSys_MemStream out_stream;
	out_stream << "out of memory" << ends;

	ERROR_STREAM << tab << out_stream.str() << endl;
	Tango::Except::throw_exception(
		   (const char *)"Serial::memory not allocated",
		   out_stream.str(),
		   (const char *)tab);
 }
 
 
 // Print the read string
 INFO_STREAM << tab << this->serialdevice.ncharread << " char read" << endl;
 char tab2[]="    ";
 TangoSys_MemStream os;
 for(int i=0; i<this->serialdevice.ncharread;i++)
 {
  (*argout)[i] = (string_argout)[i];

  if((*argout)[i] > 32)
   os << tab2 << "'" << (*argout)[i] << "'";
  else
   os << tab2 << "' '";

  os << " 0x" << std::hex << (int)((*argout)[i]) << ends;

  INFO_STREAM << os.str() << endl;

  os.seekp(0);
  os.seekg(0);
 }

	return argout;
}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_flush
 *
 *	description:	method to execute "DevSerFlush"
 *	Win32 method :
 *	Flush serial line port according to argin passed.
 *
 * @param	argin	flush to do 0=input 1=output 2=both
 *
 */
//+------------------------------------------------------------------
void Serial::dev_ser_flush(Tango::DevLong argin)
{
 char	tab[]="Serial::dev_ser_flush(): ";

 INFO_STREAM << tab << "entering... !" << endl;

 INFO_STREAM << tab << "argin: " << argin;

 // Minimum check on value passed
 if((argin != 0) && (argin != 1) && (argin != 2))
 {
  TangoSys_MemStream out_stream;
  out_stream << "invalid flush action " << argin << " (0=input 1=output 2=both)"
             << ends;

  ERROR_STREAM << tab << out_stream.str() << endl;
  Tango::Except::throw_exception(
         (const char *)"Serial::error_argin",
         out_stream.str(),
         (const char *)tab);
 }

 // Flush the input buffer
 if((argin == 0) || (argin == 2))
 {
 	#ifdef WIN32
		PurgeComm( serialdevice.hfile, PURGE_RXCLEAR );
	#endif
	#ifdef __linux
		tcflush(this->serialdevice.serialin, TCIFLUSH);
	#endif
 }

 // Flush the output buffer
 if((argin == 1) || (argin == 2))
 {
	#ifdef WIN32
		 PurgeComm( serialdevice.hfile, PURGE_TXCLEAR );
	#endif
	#ifdef __linux
		 tcflush(this->serialdevice.serialin, TCOFLUSH);
	#endif
 }

}

//+------------------------------------------------------------------
/**
 *	method:	Serial::dev_ser_get_nchar
 *
 *	description:	method to execute "DevSerGetNChar"
 *	Return the number of chars available in receiving buffer
 *
 * @return	number of char available in receiving buffer
 *
 */
//+------------------------------------------------------------------
Tango::DevLong Serial::dev_ser_get_nchar()
{
 int	ncharin;        // number of characters in the receiving buffer
 char	tab[]="Serial::dev_ser_get_nchar(): ";

 INFO_STREAM << tab << "entering... !" << endl;

	//
	// Number of characters in the receiving buffer?
	//
#ifdef WIN32 
 DWORD			cur_error;
 COMSTAT		cur_stat;
	if(ClearCommError(serialdevice.hfile, &cur_error, &cur_stat) == false)
#endif 
#ifdef __linux
if (ioctl(this->serialdevice.serialin, FIONREAD, &ncharin) < 0)
#endif

	 {
	  TangoSys_MemStream out_stream;
	  out_stream << "error reading number of char in receiving buffer" << ends;

	  ERROR_STREAM << tab << out_stream.str() << endl;

	  Tango::Except::throw_exception(
			 (const char *)"Serial::DevSerGetNChar",
			 out_stream.str(),
			 (const char *)tab);
	 }
#ifdef WIN32 
 	// cur_stat structure now contains the number of bytes available in the buffer
	ncharin = cur_stat.cbInQue<SL_MAXSTRING?cur_stat.cbInQue:SL_MAXSTRING;
#endif

	INFO_STREAM << tab << "ncharin=" << ncharin << endl;
	return ncharin;

}

//+------------------------------------------------------------------
/**
 *	method:	Serial::write_read
 *
 *	description:	method to execute "WriteRead"
 *	This method permit to send a request to a device throw the serial line and returns the
 *	response of the device.
 *	The commands write and read don't return until they have not finished.
 *
 * @param	argin	command to write on the port com
 * @return	response of the device behind the serial line
 *
 */
//+------------------------------------------------------------------
Tango::DevString Serial::write_read(Tango::DevString argin)
{
	//	POGO has generated a method core with argout allocation.
	//	If you would like to use a static reference without copying,
	//	See "TANGO Device Server Programmer's Manual"
	//		(chapter : Writing a TANGO DS / Exchanging data)
	//------------------------------------------------------------
	//call purge to get a "read message"  coherent with the "write message"
	 // 2 = Flush the input and output buffer 
	dev_ser_flush(2);

	// Then write the input message 
	dev_ser_write_string(argin);

	// take time to breath to avoid 995 error message 
#ifdef __linux
	sleep(1);
#endif
#ifdef WIN32 
//	Sleep(1);
#endif

	return  dev_ser_read_line( );
}

}	//	namespace

