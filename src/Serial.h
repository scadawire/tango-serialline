//=============================================================================
//
// file :        Serial.h
//
// description : Include for the Serial class.
//
// project :	TANGO Device Server
//
// $Author: xavela $
//
// $Revision: 1.6 $
//
// $Log: not supported by cvs2svn $
// Revision 1.5  2005/03/22 08:02:31  taurel
// - Ported to Tango V5
// - Added small changed from AG in the Windows part (One Sleep to calm down thing and
//   some management of 0 character)
//
// Revision 1.3  2004/10/22 14:17:01  xavela
// xavier : only in win32 part, possibility to open a port COM higher than 9.
// changed TANGO_ROOT_WIN32 by SOLEIL_ROOT in the makefile.vc.
//
// Revision 1.2  2004/06/30 09:22:48  xavela
// xavier : ajout de la methode dev_ser_read_nretry()
// pour la partie win32
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
//
// Revision 1.1.1.1  2003/04/24 07:14:57  meyer
// Imported using TkCVS
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
// Revision 1.0  2001/11/26 14:38:14  perez
// Initial Revision (ported to TANGO2)
//
//
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifndef _SERIAL_H
#define _SERIAL_H

#include <tango.h>
//using namespace Tango;

/**
 * @author	$Author: xavela $
 * @version	$Revision: 1.6 $ $
 */




 //	Add your own constants definitions here.
 //-----------------------------------------------
#ifdef __linux
#include <termios.h>
#endif

/**
 * maximum string length supported to date
 */
#define SL_MAXSTRING 10240      // MP 22/02/99 : 1K -> 10K


/**
 * Specific data structure
 */
typedef struct _SerialLinePart
{
	const char *serialline; /* serial line device descriptor */
#ifdef __linux
	int        serialin;    /* serial line file descriptor used for input */
	int        serialout;   /* serial line file descriptor for output */
#endif
	
#ifdef WIN32 
	HANDLE         hfile;       /* handle on the serial line device */
#endif
	
	short      timeout;     /* timeout in milliseconds */
	short      parity;      /* parity */
	short      charlength;  /* character size */
	short      stopbits;    /* number of stop bits */
unsigned long  baudrate;    /* baud rate */
	short      newline;     /* new line character */

	//Note : Following values are not managed under WIN32

	short      xon;         /* output resume character */
	short      xoff;        /* output suspend character */
	short      upper;       /* upper case only flag */
	short      erase;       /* erase on backspace flag */
	short      echo;        /* input characters echoed flag */
	short      linefeed;    /* automatic linefeed flag */
	short      null;        /* set null character count */
	short      backspace;   /* backspace character */
	short      del;         /* delete character */
	char       buffer[SL_MAXSTRING];
	int        ncharread;

} SerialLinePart;



/**
 * symbolic defines - used by server and client alike
 */
#define SL_RAW        0     /* raw read/write mode */
#define SL_NCHAR      1     /* character read/write mode */
#define SL_LINE       2     /* line read mode */
#define SL_RETRY      3     /* retry read mode */

#define SL_NONE       0
#define SL_ODD        1
#define SL_EVEN       3

#define SL_DATA8      0
#define SL_DATA7      1
#define SL_DATA6      2
#define SL_DATA5      3

#define SL_STOP1      0
#define SL_STOP15     1
#define SL_STOP2      2

#define SL_TIMEOUT    3 /* timeout parameter */
#define SL_PARITY     4 /* number of parity bits parameter */
#define SL_CHARLENGTH 5 /* number of data bits parameter */
#define SL_STOPBITS   6 /* number of stop bits parameter */
#define SL_BAUDRATE   7 /* baud rate parameter */
#define SL_NEWLINE    8 /* new line character parameter */


namespace Serial_ns
{

/**
 * Class Description:
 * C++ source for the SerialClass
 */

/*
 *	Device States Description:
 */


class Serial: public Tango::Device_3Impl
{
public :
	//	Add your own data members here
	//-----------------------------------------


	//	Here is the Start of the automatic code generation part
	//-------------------------------------------------------------	
/**
 *	@name attributes
 *	Attributs member data.
 */
//@{
//@}

/**
 *	@name Device properties
 *	Device properties member data.
 */
//@{
/**
 *	
 */
	string	serialline;
/**
 *	
 */
	Tango::DevShort	timeout;
/**
 *	
 */
	string	parity;
/**
 *	
 */
	Tango::DevShort	charlength;
/**
 *	
 */
	Tango::DevShort	stopbits;
/**
 *	
 */
	Tango::DevLong	baudrate;
/**
 *	End of message Character used in particular by the DevSerReadLine command
 *	Default = 13
 */
	Tango::DevShort	newline;
//@}

/**@name Constructors
 * Miscellaneous constructors */
//@{
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	Serial(Tango::DeviceClass *cl,string &s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	Serial(Tango::DeviceClass *cl,const char *s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device name
 *	@param d	Device description.
 */
	Serial(Tango::DeviceClass *cl,const char *s,const char *d);
//@}

/**@name Destructor
 * Only one desctructor is defined for this class */
//@{
/**
 * The object desctructor.
 */	
	~Serial() {delete_device();};
//@}

	
/**@name Miscellaneous methods */
//@{
/**
 *	Initialize the device
 */
	virtual void init_device();
	/**
 *	will be called at device destruction or at init command.
 */
	void delete_device();
/**
 *	Always executed method befor execution command method.
 */
	virtual void always_executed_hook();

//@}

/**
 * @name Serial methods prototypes
 */

//@{
/**
 *	Execution allowed for DevSerWriteString command.
 */
	virtual bool is_DevSerWriteString_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerWriteChar command.
 */
	virtual bool is_DevSerWriteChar_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerReadString command.
 */
	virtual bool is_DevSerReadString_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerReadChar command.
 */
	virtual bool is_DevSerReadChar_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for WriteRead command.
 */
	virtual bool is_WriteRead_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerGetNChar command.
 */
	virtual bool is_DevSerGetNChar_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerReadNChar command.
 */
	virtual bool is_DevSerReadNChar_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerReadRaw command.
 */
	virtual bool is_DevSerReadRaw_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerReadLine command.
 */
	virtual bool is_DevSerReadLine_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerFlush command.
 */
	virtual bool is_DevSerFlush_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerSetParameter command.
 */
	virtual bool is_DevSerSetParameter_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerSetTimeout command.
 */
	virtual bool is_DevSerSetTimeout_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerSetParity command.
 */
	virtual bool is_DevSerSetParity_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerSetCharLength command.
 */
	virtual bool is_DevSerSetCharLength_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerSetStopbit command.
 */
	virtual bool is_DevSerSetStopbit_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerSetBaudrate command.
 */
	virtual bool is_DevSerSetBaudrate_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerSetNewline command.
 */
	virtual bool is_DevSerSetNewline_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerReadRetry command.
 */
	virtual bool is_DevSerReadRetry_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DevSerReadNBinData command.
 */
	virtual bool is_DevSerReadNBinData_allowed(const CORBA::Any &any);
/**
 * This command gets the device status (stored in its <i>device_status</i> data member) and returns it to the caller.
 *	@return	Status descrition
 *	@exception DevFailed
 */
	virtual Tango::ConstDevString	dev_status();
/**
 * Write a string of characters to a serial line and return
 *	the number of characters written.
 *	@param	argin	String to write
 *	@return	Number of characters written
 *	@exception DevFailed
 */
	Tango::DevLong	dev_ser_write_string(Tango::DevString);
/**
 * Write N characters to a seria line and return the
 *	number of characters written.
 *	@param	argin	Characters to write
 *	@return	Number of characters written
 *	@exception DevFailed
 */
	Tango::DevLong	dev_ser_write_char(const Tango::DevVarCharArray *);
/**
 * Win32 method :
 *	Read a string of characters, the type of read is specified in the
 *	input parameter SL_RAW SL_NCHAR SL_LINE
 *	@param	argin	type of read SL_RAW SL_NCHAR SL_LINE
 *	@return	String read
 *	@exception DevFailed
 */
	Tango::DevString	dev_ser_read_string(Tango::DevLong);
/**
 * Win32 method :
 *	Read an array of characters, the type of read is specified in the
 *	input parameter, it can be SL_RAW SL_NCHAR SL_LINE
 *	@param	argin	type of read SL_RAW SL_NCHAR SL_LINE
 *	@return	Array of characters read
 *	@exception DevFailed
 */
	Tango::DevVarCharArray	*dev_ser_read_char(Tango::DevLong);
/**
 * This method permit to send a request to a device throw the serial line and returns the
 *	response of the device.
 *	The commands write and read don't return until they have not finished.
 *	@param	argin	type of reading strategy(RAW,NCHAR..),command to write on the port com
 *	@return	response of the device behind the serial line
 *	@exception DevFailed
 */
	Tango::DevString	write_read(const Tango::DevVarLongStringArray *);
/**
 * Return the number of chars available in receiving buffer
 *	@return	number of char available in receiving buffer
 *	@exception DevFailed
 */
	Tango::DevLong	dev_ser_get_nchar();
/**
 * Read a string of N characters from the serial line
 *	If there are no characters to be read returns an empty string.
 *	@param	argin	number of the caracters to read on the serial line
 *	@return	pointer to the string read updated
 *	@exception DevFailed
 */
	Tango::DevString	dev_ser_read_nchar(Tango::DevLong);
/**
 * read a string from the serialline device in mode raw (no end
 *	of string expected, just empty the entire serialline receiving buffer).
 *	@return	pointer to the string read updated
 *	@exception DevFailed
 */
	Tango::DevString	dev_ser_read_raw();
/**
 * read a string from the serialline device in mode line (up to
 *	and including the character specified by the NewLine property
 *	@return	pointer to the string read updated
 *	@exception DevFailed
 */
	Tango::DevString	dev_ser_read_line();
/**
 * Win32 method :
 *	Flush serial line port according to argin passed.
 *	@param	argin	flush to do 0=input 1=output 2=both
 *	@exception DevFailed
 */
	void	dev_ser_flush(Tango::DevLong);
/**
 * Set serial line parameters
 *	@param	argin	device parameters in pair
 *	@exception DevFailed
 */
	void	dev_ser_set_parameter(const Tango::DevVarLongArray *);
/**
 * This command sets the new timeout (in ms).
 *	@param	argin	Value of the timeout to set
 *	@exception DevFailed
 */
	void	dev_ser_set_timeout(Tango::DevShort);
/**
 * Sets the new parity of the serial line.
 *	NONE 0
 *	ODD 1
 *	EVEN 3
 *	@param	argin	The new parity to set.
 *	@exception DevFailed
 */
	void	dev_ser_set_parity(Tango::DevShort);
/**
 * Sets the new charlength.
 *	0 = 8 bits
 *	1 = 7 bits
 *	2 = 6 bits
 *	3 = 5 bits
 *	@param	argin	The new charlength to set
 *	@exception DevFailed
 */
	void	dev_ser_set_char_length(Tango::DevShort);
/**
 * Sets the new stop bit.
 *	0 = none
 *	1 = one stop
 *	2 = 1.5 stop bit
 *	@param	argin	The new stopbit to set
 *	@exception DevFailed
 */
	void	dev_ser_set_stopbit(Tango::DevShort);
/**
 * Sets the new baudrateof the serial line ( up to 4 Mega).
 *	Default is 9600.
 *	@param	argin	The new baudrate to set
 *	@exception DevFailed
 */
	void	dev_ser_set_baudrate(Tango::DevULong);
/**
 * The new ending character in hexa.
 *	Default is 0x13 (=CR
 *	@param	argin	The new line character to set
 *	@exception DevFailed
 */
	void	dev_ser_set_newline(Tango::DevShort);
/**
 * read a string from the serialline device in mode raw (no end
 *	of string expected, just empty the entire serialline receiving buffer).
 *	If read successfull, read again "nretry" times.
 *	@param	argin	number of reading retries
 *	@return	pointer to the string read updated
 *	@exception DevFailed
 */
	Tango::DevString	dev_ser_read_retry(Tango::DevLong);
/**
 * Read the specified number of char from the serial line.
 *	If the number of caracters is greater than caracters avaiable, this command returns
 *	all caracters avaiables.
 *	If there are no characters to be read returns an empty array.
 *	@param	argin	nb char to read
 *	@return	array of data
 *	@exception DevFailed
 */
	Tango::DevVarCharArray	*dev_ser_read_nbin_data(Tango::DevLong);

/**
 *	Read the device properties from database
 */
	 void get_device_property();
//@}

	//	Here is the end of the automatic code generation part
	//-------------------------------------------------------------	



protected :	
	//	Add your own data members here
	//-----------------------------------------
/**
 *      Open the device desciptors and update member variable
 *
 */
		void open_desc(void);
/**
*      Read a string of characters from the serial line.
*			 If string read retry to read "nretry" times.
*			 Specify number of retries.
*      The maximum number of characters that can be read is
*      SL_MAXSTRING, if there are more characters in the received
*      buffer, they are let there for the next read.
*
*	@param	argin: number N of retries
* @return String read
*/
        char *retry_read_string(long);
/**
 *      Read a string of characters from the serial line if
 *      there are no characters to be read return an empty string.
 *      The maximum number of characters that can be read is
 *      SL_MAXSTRING, if there are more characters in the received
 *      buffer, they are let there for the next read.
 *
 *      @return String read
 */
        char *raw_read_string(void);
/**
 *      Read a string of N characters from the serial line if
 *      there are no characters to be read return an empty string.
 *
 *      @param  argin   number N of characters to read
 *      @return String read
 */
        char *nchar_read_string(long);
/**
 *      Read a string of characters from the serial line
 *      up and including the next newline.
 *
 *      @return String read
 */
        char *line_read_string(void);
/**
 *      Return a string with the serial line configuration parameter
 *      decoded from the termio structure passed.
 *
 *	@param	term structure to decode
 *	@param	eol end of line character to use
 *      @return String with configuration decoded
 */
        char *decode_parameters(struct termios, char);

		// setup the serial line 
		void serial_setparameter( void );
		
		// Data members
        SerialLinePart serialdevice;

#ifdef __linux

		// Set serial line parameters for Linux plateform
		void dev_ser_set_parameter_linux(const Tango::DevVarLongArray *);
#endif


#ifdef WIN32
		// WIN32 function to write on a WIN32 COM descriptor 
		long write_win32(char *str);
		//close file descriptor
		void close_handle_win32();
				// Set serial line parameters for Win32 plateform
		void dev_ser_set_parameter_win32(const Tango::DevVarLongArray *);
		long write_win32_bin_char_array( const Tango::DevVarCharArray *);

#endif
	


};

}	// namespace

#endif	// _SERIAL_H
