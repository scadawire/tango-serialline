//=========================================================
//
//		THIS FILE CONTAINS ALL THE METHODS FOR 
//
//					WIN 32 PLATEFORM
//
//=========================================================


#include <Serial.h>
#include <Tango.h>
#include <time.h>

// extract from "serialdsP.h" (TACO file)
// Needed because different from old SL_NONE etc

/* Now we use the constant define by the Win32 API :
*	Parity :	"NOPARITY", "ODDPARITY", "EVENPARITY".
*	CharLength : "WIN_SL_DATA5", "WIN_SL_DATA6", "WIN_SL_DATA7", "WIN_SL_DATA8".
*	Stop bit : "ONESTOPBIT", "ONE5STOPBIT", "TWOSTOPBIT".
*/

//#define WINSL_NONE       0
//#define WINSL_ODD        1	/* NOT USED */
//#define WINSL_EVEN       2

#define WIN_SL_DATA8      8
#define WIN_SL_DATA7      7
#define WIN_SL_DATA6      6
#define WIN_SL_DATA5      5


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
void Serial::dev_ser_set_parameter_win32(const Tango::DevVarLongArray *argin)
{
	DEBUG_STREAM << "Serial::dev_ser_set_parameter(): entering... !" << endl;

	//	Add your own code to control device here
SerialLinePart	oldserialline;
char			temp[256];
	
	
	INFO_STREAM << "Serial::dev_ser_set_parameter: entering ." << endl;
	
	/*
	* Keep a record of the last valid set of parameters
	*/
	oldserialline.timeout    = serialdevice.timeout;
	oldserialline.parity     = serialdevice.parity;
	oldserialline.charlength = serialdevice.charlength;
	oldserialline.stopbits   = serialdevice.stopbits;
	oldserialline.baudrate   = serialdevice.baudrate;
	oldserialline.newline	 = serialdevice.newline;
	
	/*
	* Get device parameters passed
	*/
	for(int i=0;i<argin->length();i+=2)
	{
		switch ((*argin)[i])
		{
		case SL_TIMEOUT:
			
			// Record new value
			serialdevice.timeout = (short)(*argin)[i+1];
			DEBUG_STREAM << "dev_ser_set_parameter: new timeout: " << serialdevice.timeout;
			break;
			
			
		case SL_PARITY:
			// Minimum check on value passed
			switch((*argin)[i+1])
			{
			case SL_NONE:
				serialdevice.parity = NOPARITY;
				break;
			case SL_ODD:
				serialdevice.parity = ODDPARITY;
				break;
			case SL_EVEN:
				serialdevice.parity = EVENPARITY;
				break;
			}
			
			// Record new value
			sprintf(temp, "dev_ser_set_parameter: new parity: %d (%d=none %d=odd %d=even)",
				serialdevice.parity,NOPARITY, ODDPARITY, EVENPARITY);

			DEBUG_STREAM << string(temp) <<  endl;
			break;
			
			
		case SL_CHARLENGTH:
			// Minimum check on value passed
			switch((*argin)[i+1])
			{
			case SL_DATA5:
				serialdevice.charlength = WIN_SL_DATA5;
				break;
			case SL_DATA6:
				serialdevice.charlength = WIN_SL_DATA6;
				break;
			case SL_DATA7:
				serialdevice.charlength = WIN_SL_DATA7;
				break;
			case SL_DATA8:
				serialdevice.charlength = WIN_SL_DATA8;
				break;
			default:
				Tango::Except::throw_exception(
					(const char *)"Serial. Setting SL_CHARLENGTH",
					(const char*) "bad number of data bits",
					(const char *)"Serial::dev_ser_set_parameter");
				
			}
			
			// Record new value
			DEBUG_STREAM << "dev_ser_set_parameter: new charlength: " << serialdevice.charlength;
			break;
				
		case SL_STOPBITS:
			// Minimum check on value passed
			switch((*argin)[i+1])
			{
			case SL_STOP1:
				serialdevice.stopbits = ONESTOPBIT;
				break;
			case SL_STOP15:
				serialdevice.stopbits = ONE5STOPBITS;
				break;
			case SL_STOP2:
				serialdevice.stopbits = TWOSTOPBITS;
				break;
			default:
				Tango::Except::throw_exception(
					(const char *)"Serial. Setting SL_STOPBITS",
					(const char *) "bad number of stop bits",
					(const char *)"Serial::dev_ser_set_parameter");
			}
			
			// Record new value
			sprintf(temp, "dev_ser_set_parameter: new stopbits: %d (%d=1bit %d=1.5bit %d=2bits)", 
				serialdevice.stopbits,
				ONESTOPBIT, ONE5STOPBITS, TWOSTOPBITS);
			DEBUG_STREAM << string(temp) <<  endl;
			break;
					
					
		case SL_BAUDRATE:
			// Minimum check on value passed
			switch((*argin)[i+1])
			{
			case 50:
			case 75:
			case 110:
			case 134:
			case 150:
			case 300:
			case 600:
			case 1200:
			case 1800:
			case 2400:
			case 4800:
			case 9600:
			case 19200:
			case 38400:
			case 57600:
			case 115200:
			case 230400:
			case 460800:
			case 500000:
			case 576000:
			case 921600:
			case 1000000:
			case 1152000:
			case 1500000:
			case 2000000:
			case 2500000:
			case 3000000:
			case 3500000:
			case 4000000:
				break;
			default:
				Tango::Except::throw_exception(
					(const char *)"Serial. Setting SL_BAUDRATE",
					(const char*) "invalid baudrate",
					(const char *)"Serial::dev_ser_set_parameter");
			}
			
			// Record new value
			serialdevice.baudrate = (*argin)[i+1];
			DEBUG_STREAM << "dev_ser_set_parameter: new baudrate= " <<   serialdevice.baudrate;
			break;
						
		
		case SL_NEWLINE:
			// Record new value
			serialdevice.newline = (short)((*argin)[i+1]);
			DEBUG_STREAM << "dev_ser_set_parameter: new newline= " <<   serialdevice.newline;
			break;
			
		default:
			DEBUG_STREAM << "non handled parameter !"<<endl ;
			break;
		} // end of switch()
	} // end of for()
  
	/*
	* Setup the serial line
	*/
	try
	{
		serial_setparameter( );
	}
	catch (Tango::DevFailed &  )
		
	{
		// Restore the last valid set of parameters

		ERROR_STREAM << "Serial::dev_ser_set_parameter_win32 : Error setting new values ==> Restore the last valid set of parameters" << endl;
		
		serialdevice.timeout    = oldserialline.timeout;
		serialdevice.parity     = oldserialline.parity;
		serialdevice.charlength = oldserialline.charlength;
		serialdevice.stopbits   = oldserialline.stopbits;
		serialdevice.baudrate   = oldserialline.baudrate;
		
	}

}



/*======================================================================
Function:      serial_setparameter()

Description:i  setup the serial line

Arg(s) In:     void

Arg(s) Out:	 void
=======================================================================*/
void Serial::serial_setparameter()
{
DCB		comm_prop;
  
	/*
	* Get properties of the serialline (communication device for Windows)
	*/
	if(GetCommState(this->serialdevice.hfile, &comm_prop) == false)
	{
	  ERROR_STREAM << "serial_setparameter:GetCommState : error getting serialline props" << endl;
	  Tango::Except::throw_exception(
		  (const char *)"Serial::GetCommState",
		  (const char *)"Error getting serialline props",
		  (const char *)"Serial::serial_setparameter");
	}
  
  
	/*
	* Set serial line configuration 
	*/
	comm_prop.BaudRate = serialdevice.baudrate;
	comm_prop.ByteSize = serialdevice.charlength;  // giving bits
	comm_prop.StopBits = serialdevice.stopbits;    // 0-2=1,1.5,2bit
	comm_prop.Parity   = serialdevice.parity;      // 0-4=no,odd,even,mark,space
	comm_prop.EofChar  = serialdevice.newline;     // signal the end of data
  

	/*
	* Set properties of the serialline (communication device for Windows)
	*/
	if(SetCommState(this->serialdevice.hfile, &comm_prop) == FALSE)
	{
		unsigned long ret = GetLastError();
	  ERROR_STREAM << "serial_setparameter: SetCommState : error # " << ret << endl;

	  ERROR_STREAM << "serial_setparameter: SetCommState : error setting serialline props" << endl;
	  Tango::Except::throw_exception(
		  (const char *)"Serial::SetCommState",
		  (const char*) "Error setting serialline props",
		  (const char *)"Serial::serial_setparameter");
	}

	INFO_STREAM << "Serial::serial_setparameter(): parameters well set" << endl;
  
	/*  Old TACO stuff : no more used since we use our own Timeout
	// ==> TO BE deleted in the future
	* Set timeout values (in milliseconds) for future serialline 
	* blocking read/write
	*/
	/*
COMMTIMEOUTS	comm_timeouts;
	comm_timeouts.ReadIntervalTimeout          = MAXDWORD;
	comm_timeouts.ReadTotalTimeoutMultiplier   = MAXDWORD;
	comm_timeouts.ReadTotalTimeoutConstant     = (unsigned long)((double) serialdevice.timeout);
	comm_timeouts.WriteTotalTimeoutMultiplier  = 0; // not used
	comm_timeouts.WriteTotalTimeoutConstant    = 0; // not used

	if (SetCommTimeouts(serialdevice.hfile, &comm_timeouts) == FALSE)
	{
	  ERROR_STREAM << "serial_open: error setting timeouts" << endl;
	  Tango::Except::throw_exception(
		  (const char *)"Serial::SetCommTimeouts",
		  (const char*) "Error setting timeouts",
		  (const char *)"Serial::serial_setparameter");
	}

	DEBUG_STREAM << "Serial::serial_setparameter(): timemouts well set" << endl;
  */
  
	return ;
}
	  
//+------------------------------------------------------------------
/**
*      method: Serial::open_desc
*
*      description:    Open the device desciptors and update member variable
*
*/
//+------------------------------------------------------------------
void Serial::open_desc()
{

	std::string port_to_open;

	//- Init the string port_to_open
	port_to_open.erase();
	port_to_open = "\\\\.\\";

//- CAUTION : 
//-----------
	/*	Using COM ports above COM9 : */
	//- COM ports above COM9 cannot be opened using the regular notation, 
	//-		but it requires a more cryptic syntax (that can also be used for the other COM-ports. 
	//-		The syntax used for these ports is \\.\COMxx (where xx specifies the port number). 
	//-		Open COM14 will look like this in code: serial.Open(_T("\\\\.\\COM14"),0,0,false);
	//- This is described in more detail in the Microsoft Knowledge Base in article Q115831 
	//- Check the following url for more advice : http://support.microsoft.com/kb/q115831/

	//- The following syntax permits to open more than 9 serial ports
	strcat((char*)port_to_open.c_str(), serialdevice.serialline);

	/*
	* Open the serialline (communication device for Windows)
	*/
	serialdevice.hfile = CreateFile(
		  (LPCWSTR)port_to_open.c_str(),
		  GENERIC_READ | GENERIC_WRITE,
		  0,                     // no sharing
		  NULL,                  // no security attrs
		  OPEN_EXISTING,
		  NULL, 
		  NULL);				// overlapped not used now	
  
	if (serialdevice.hfile == INVALID_HANDLE_VALUE)
	{
  
	  FATAL_STREAM << "	Serial::open_desc_win32 . serial line NOT opened = " << serialdevice.serialline << endl ;
	  Tango::Except::throw_exception(
		  (const char *) "Serial",
		  (const char *) "Error opening descriptor file",
		  (const char *) "Serial::open_desc_win32");
  
	}
	INFO_STREAM << "	Serial::open_desc_win32 . serial line opened = " << serialdevice.serialline << endl ;
  
}
	  
//+------------------------------------------------------------------
/**
*      method: Serial::close_handle_win32
*
*      description:    close the device desciptors 
*
*/
//+------------------------------------------------------------------
void Serial::close_handle_win32()
{
	INFO_STREAM << "Serial::close_handle_win32 . serial line closed" << endl ;
	CloseHandle( serialdevice.hfile );
}
	  
/*======================================================================
Function:    static long serial_writestring()

Description: write a string to the serialline device

Arg(s) In:   Serial ds - serial info structure
char *str - string to write

Arg(s) Out:  int *argout - number of characters written
long *error -  pointer to error code, in case routine fails
=======================================================================*/
long Serial::write_win32( char *str )
{
size_t		str_len;
int			bytes_written;
OVERLAPPED	osWrite = {0};
  
	/*
	* Write the chars but using overlapped code (i.e. processing in
	* background the write on the SL)
	* + 1 for the terminator
	*/
	str_len = strlen(str);
	if (WriteFile(serialdevice.hfile, str, str_len,( DWORD *)&bytes_written, &osWrite) == false)
	{
	  ERROR_STREAM << " String NOT written = " << str << endl;
	  return -1;
  
	}
	else
	{	
	  DEBUG_STREAM << " String written on serial port= " << str << endl;
	  return bytes_written;
	}
}
/*======================================================================
Function:    long Serial::write_win32_bin_char_array()
{
Description: write a binary char array

Argin:   Tango::DevVarCharArray dvca

Argout:  long :  number of characters written -1 if error
=======================================================================*/
long Serial::write_win32_bin_char_array( const Tango::DevVarCharArray *dvca )
{
size_t		str_len;
char *tmp=0;
int			bytes_written;
OVERLAPPED	osWrite = {0};
  
	/*
	* Write the chars but using overlapped code (i.e. processing in
	* background the write on the SL)
	* + 1 for the terminator
	*/
	str_len = dvca->length();
	tmp = new char[str_len+1];
	::memset(tmp,'\0',(str_len+1));

	for(int i=0;i<str_len;i++)
		tmp[i] = (*dvca)[i];

	if (WriteFile(serialdevice.hfile, tmp, str_len,(DWORD *)&bytes_written, &osWrite) == false)
	{
	  ERROR_STREAM << " DevVarCharArray NOT written " << endl;
	  if(tmp) delete tmp;
	  return -1;
  
	}
	else
	{	
	  DEBUG_STREAM << " DevVarCharArray written on serial port " << endl;
	  if(tmp) delete[] tmp;
	  return bytes_written;
	}
}

//+------------------------------------------------------------------
/**
*      method: Serial::retry_read_string
*
*      description:    
*	     read a string from the serialline device in mode raw,
*			 if first reading attempt successfull, retry to read "nretry" 
*      times; if no more data found exit on timeout without error.
*	     Useful in case of long strings with no fixed lenght ( > 64 bytes) 
*			 Very unlucky case!!!
*      The maximum number of characters that can be read is
*      SL_MAXSTRING.
*
*	@param	argin: number N of retries
* @return String read

*/
//+------------------------------------------------------------------
char *Serial::retry_read_string(long nretry)
{
	char	*argout;
	int		nchar=0;
	int		retrycnt;		// retry reading counter
	clock_t	starttime, finish;
	bool	TIMEOUT = false;
	
	//
	//first "empty" buffer by NULL terminating it
	//
	this->serialdevice.buffer[0] = 0;
	this->serialdevice.ncharread = 0;

	retrycnt = 0;	
	do
	{
/*		// Get the current number of bytes in the receiving buffer
		if(ClearCommError(serialdevice.hfile, &cur_error, &cur_stat) == FALSE)
		{
			ERROR_STREAM << "nchar_read_string: error reading serialline stats" << endl;
			
			Tango::Except::throw_exception(
				(const char *)"Serial::error_nretry",
				(const char*) "error reading serialline stats",
				(const char *)"Serial::retry_read_string");
			
		}
		memset
		// number of bytes available
		bytes_available = cur_stat.cbInQue<SL_MAXSTRING?cur_stat.cbInQue:SL_MAXSTRING;
		
		if(ReadFile(
			serialdevice.hfile, 
			this->serialdevice.buffer + this->serialdevice.ncharread, 
			bytes_to_read, 
			(DWORD *)&bytes_read, 
			&osRead) == FALSE)
		{
			ERROR_STREAM << "retry_read_string: error reading from serialline" << endl;
			Tango::Except::throw_exception(
				(const char *)"Serial::ReadFile",
				(const char*) "Error reading from serialline : retry_read_string",
				(const char *)"Serial::retry_read_string");
		}
		
		// if read succeed and if no bytes : 
		if (bytes_read == 0 && TIMEOUT)
			break;
		
		if (bytes_read < 0)
		{
			TangoSys_MemStream out_stream;
			out_stream << "error reading from device, errno=" << errno
				<< ends;
			ERROR_STREAM << out_stream.str() << endl;
			Tango::Except::throw_exception(
				(const char *)"Serial::error_read",
				out_stream.str(),
				(const char *)"Serial::retry_read_string");
		}
		this->serialdevice.ncharread += bytes_read;
*/
		
		starttime = clock();
		
		argout = raw_read_string();

		
		// store the last read
		if(this->serialdevice.ncharread > 0)
			::strcpy((argout+nchar), (const char *) this->serialdevice.buffer);



		nchar = this->serialdevice.ncharread;

		finish = clock();
		double duration = (double)(finish - starttime) / CLOCKS_PER_SEC;


		
		if(duration > (double)this->serialdevice.timeout)
		{
			if(retrycnt < nretry)
				TIMEOUT = true;
			// the receive buffer is empty but no error !
			if(!this->serialdevice.ncharread)
				break;
		}

		retrycnt++;	
		
	}
	while( retrycnt < nretry && !TIMEOUT);

	if(TIMEOUT)
	{
	  Tango::Except::throw_exception(
		  (const char *)"Serial::error_timeend",
		  (const char *) "timeout waiting for the ended character ",
		  (const char *)"Serial::retry_read_string");
	}

		DEBUG_STREAM << "**** \n\n ARGOUT NRETRY = " << argout << endl;
		
		
	return argout;		
		
}

	  
/*======================================================================
Function:    char * raw_read_string()

Description: read a string from the serialline device in mode raw (no end
of string expected, just empty the entire serialline
receiving buffer).

  Arg(s) In:   void
  
	Arg(s) Out:  char *argout - pointer to the string read updated (return
	a pointer to the internal static buffer)
=======================================================================*/
char *Serial::raw_read_string(void)
{
DWORD		cur_error;
COMSTAT		cur_stat;
int			bytes_to_read;
int			bytes_read;
int			i;
char		one_char;
char		*argout;
OVERLAPPED	osRead = {0};
  
	//
	//first "empty" buffer by null terminating it
	//
	this->serialdevice.buffer[0] = 0;

	// init of the buffer of com
	/*
	* Get the current number of bytes in the receiving buffer
	*/
	if(ClearCommError(
	  serialdevice.hfile, 
	  &cur_error,
	  &cur_stat) == FALSE)
	{
	  ERROR_STREAM << "raw_read_string: error reading serialline stats" << endl;
	  Tango::Except::throw_exception(
		  (const char *)"Serial::ClearCommError",
		  (const char*) "Error reading serialline stats : raw_read_string",
		  (const char *)"Serial::raw_read_string");
	}
  
	// cur_stat structure now contains the number of bytes available in the buffer
	/*
	* Empty the receiving buffer
	*/
	bytes_to_read = cur_stat.cbInQue<SL_MAXSTRING?cur_stat.cbInQue:SL_MAXSTRING;
	if(ReadFile(
	  serialdevice.hfile, 
	  this->serialdevice.buffer, 
	  bytes_to_read, 
	  (DWORD *)&bytes_read, 
	  &osRead) == FALSE)
	{
	  ERROR_STREAM << "raw_read_string: error reading from serialline" << endl;
	  Tango::Except::throw_exception(
		  (const char *)"Serial::ReadFile",
		  (const char*) "Error reading from serialline : raw_read_string",
		  (const char *)"Serial::raw_read_string");
	}

	// Update global resource
	this->serialdevice.ncharread = bytes_read;

	/*
	* Don't forget the string ending char
	*/
	this->serialdevice.buffer[this->serialdevice.ncharread] = 0;

	for(i=0; i < bytes_read;i++)
	{
	  one_char = this->serialdevice.buffer[i];
	  DEBUG_STREAM << "raw_read_string: char read: " << one_char << " " << (one_char>32?one_char:' ') << endl;
	}
  
	// Prepare return buffer (can not return "buffer" directly 
	// because TANGO desallocate the memory return)
	argout = new char[bytes_read + 1];
  
	if(argout == 0)
	{
	  TangoSys_MemStream out_stream;
	  out_stream << "unable to allocate memory for the return buffer, need "<< bytes_read << " bytes" << ends;
  
	  FATAL_STREAM << "Serial::raw_read_string(): ";
	  FATAL_STREAM << out_stream.str() << endl;
	  Tango::Except::throw_exception(
		  (const char *)"Serial::error_alloc",
		  out_stream.str(),
		  (const char *)"Serial::raw_read_string");
	}
  
	// Do not use strncpy() as raw_read_string() is used by xxx_read_char()
	for(i=0 ; i<this->serialdevice.ncharread ; i++)
		argout[i] = this->serialdevice.buffer[i];

	// Add string ending char, used only by ser_read_string()
	argout[i]=0;

	DEBUG_STREAM << "Serial::raw_read_string(): nchar=" << this->serialdevice.ncharread << " argout=" << argout << endl;

	return argout;
}
	  
/*======================================================================
Function:    char * line_read_string()

Description: read a string from the serialline device in mode line (up to
				and including the end of line specified)

Arg(s) In:   void

Arg(s) Out:  char *argout - pointer to the string read updated (return
				a pointer to the internal static buffer)
=======================================================================*/
char * Serial::line_read_string(void)
{
char		*argout;
char		one_char=' ';
int			one_byte_read;
char		eol_char;
int			bytes_to_read=1;
int			result=true;
  
//timeout
long		ellapsed;
DWORD		starttime;
long		timeout_ms;
bool		TIMEOUT = false;
  
OVERLAPPED	osRead = { 0 };
DWORD		cur_error;
COMSTAT		cur_stat;
  

	//
	//first "empty" buffer by null terminating it
	//
	this->serialdevice.buffer[0] = 0;
	this->serialdevice.ncharread = 0;


	/*
	* Get the End Of Line characters setup
	*/
	eol_char = (char)(serialdevice.newline);

	/*
	* Empty the receiving buffer one by one character looking for the 
	* expected end of line (I know it's not very smart but the Microsoft
	* SetCommMask(xxx.EV_RXFLAG) + WaitCommEvent() didn't work correctly
	*/
	timeout_ms = (unsigned long)((double)serialdevice.timeout);
	starttime = GetTickCount();
	int nb_char_available = 0;
	int printable_char;

	do
	{
		// first get status from comm port : Useful to get coherent Readfile  behaviour
		if( ClearCommError(serialdevice.hfile, &cur_error,&cur_stat) == FALSE)
		{
			ERROR_STREAM << "nchar_read_string: error reading serialline stats" << endl;
			
			Tango::Except::throw_exception(
				(const char *)"INTERNAL_ERROR",
				(const char*) "ClearCommError : error reading serialline stats",
				(const char *)"Serial::line_read_string");
			
		}
		nb_char_available= cur_stat.cbInQue<SL_MAXSTRING?cur_stat.cbInQue:SL_MAXSTRING; 
                
		//- sleep a little bit ...
		if (nb_char_available <= 0) Sleep(1);
		
		//- ... if no response -> throw
		if (nb_char_available <= 0) 
		{
			ERROR_STREAM << "nchar_read_string: error reading serialline stats : " << nb_char_available << " char(s)" << endl;
			Tango::Except::throw_exception(
				(const char *)"INTERNAL_ERROR",
				(const char*) "No data available on the serial input queue !",
				(const char *)"Serial::line_read_string");
		}
		/*
		* Read one char from the serialline with timeout watchdog 
		*/
		if (nb_char_available > 0)
		{
			result=ReadFile(serialdevice.hfile,&one_char,bytes_to_read, (DWORD *)&one_byte_read, &osRead) ;
			
			DEBUG_STREAM << "serial_linereadstring: ReadFile() returns :" << result << endl;
			DEBUG_STREAM << "serial_linereadstring: char read:" << one_char << " " << (one_char>32?one_char:'*') << endl;
			printable_char = (int) one_char;
			INFO_STREAM << "serial_linereadstring: printable char: " << std::fixed << one_char << endl;
			
			this->serialdevice.buffer[(this->serialdevice.ncharread)] = one_char;
			/*
			* VERY STRANGE - for Paragon motor I sometimes read the character 0 which then
			* terminates the string - andy.gotz@esrf.fr
			*/
			if (printable_char != 0) this->serialdevice.ncharread++;
		}
		ellapsed = GetTickCount() - starttime;
		
		if(ellapsed < 0)
			ellapsed += UINT_MAX;
		
		if (ellapsed > timeout_ms)  
		{
			ERROR_STREAM << "Sortie sur Timeout " << endl;
			TIMEOUT = true;
		}
		
	}
	while((one_char != eol_char) &&  !TIMEOUT);

	if(TIMEOUT)
	{
		Tango::Except::throw_exception(
			(const char *)"Serial::error_timeend",
			(const char *) "timeout waiting for the ended character ",
			(const char *)"Serial::line_read_string");
	}
	/*
	* Don't forget the string ending char
	*/
	this->serialdevice.buffer[this->serialdevice.ncharread] = 0;

	// Prepare return buffer (can not return "buffer" directly 
	// because TANGO desallocate the memory return)
	argout = new char[this->serialdevice.ncharread + 1];

	if(argout == 0)
	{
		TangoSys_MemStream out_stream;
		out_stream << "unable to allocate memory for the return buffer, need "<< this->serialdevice.ncharread << " bytes" << ends;
		
		FATAL_STREAM << "Serial::line_read_string(): ";
		FATAL_STREAM << out_stream.str() << endl;
		Tango::Except::throw_exception(
			(const char *)"Serial::error_alloc",
			out_stream.str(),
			(const char *)"Serial::line_read_string");
	}

	// Do not use strncpy() as raw_read_string() is used by xxx_read_char()
	int i;
	for(i=0 ; i< this->serialdevice.ncharread ; i++)
	argout[i] = this->serialdevice.buffer[i];

	// Add string ending char, used only by ser_read_string()
	argout[i]='\0';

	//A RET !
	DEBUG_STREAM << "Serial::line_read_string(): nchar=" << this->serialdevice.ncharread << " argout=" << argout << endl;

	return argout;
}
	 	 
//+------------------------------------------------------------------
/**
*	method:	Serial::nchar_read_string
*
*	description:	Read a string of N characters from the serial line if
*	there are no characters to be read return an empty string.
*
*	@param	argin	number N of characters to read
*	@return	string read
*
*/
//+------------------------------------------------------------------
char * Serial::nchar_read_string( long nchar )
{
 
char		*argout;
int			bytes_available;
long		ellapsed;
DWORD		starttime;
long		timeout_ms;
char		tab[]="Serial::nchar_read_string(): "; 
DWORD		cur_error;
COMSTAT		cur_stat; 
OVERLAPPED	osRead = {0};

	//
	//first "empty" buffer by NULL terminating it
	//
	this->serialdevice.buffer[0] = 0;
	this->serialdevice.ncharread = 0;

	//
	// Don't read more than we can store
	//
	if (nchar > SL_MAXSTRING)
	{
		TangoSys_MemStream out_stream;
		out_stream << "number of char requested " << nchar << " > " << SL_MAXSTRING
				  << ends;

		ERROR_STREAM << tab << out_stream.str() << endl;
		Tango::Except::throw_exception(
			(const char *)"Serial::error_nchar",
			out_stream.str(),
			(const char *)tab);
	}
	 
	 /*
	 * Wait until the receiving buffer contains the requested number of char
	 * Note: don't know how to replace this manual timeout by 
	 * WaitCommEvent() and all its stuff
	 */
	 DEBUG_STREAM << "nchar_read_string: starts waiting "<< nchar <<endl;
 
	 timeout_ms = (unsigned long)((double)serialdevice.timeout);
	 starttime = GetTickCount();
	 do
	 {
		 // Get the current number of bytes in the receiving buffer
		 if(ClearCommError(
			 serialdevice.hfile, 
			 &cur_error,
			 &cur_stat) == FALSE)
		 {
			 ERROR_STREAM << "nchar_read_string: error reading serialline stats" << endl;
			 
			 Tango::Except::throw_exception(
				 (const char *)"Serial::error_nchar",
				 (const char*) "error reading serialline stats",
				 (const char *)"Serial::nchar_read_string");
			 
		 }
		 bytes_available = cur_stat.cbInQue<SL_MAXSTRING?cur_stat.cbInQue:SL_MAXSTRING;
		 
		 // Take time to breath
		 Sleep(1); // unit is millisecond
		 
		 // Implement a timeout
		 ellapsed = GetTickCount() - starttime;
		 if(ellapsed < 0)
			 ellapsed += UINT_MAX;
		 
	 }
	 while((bytes_available < nchar) &&  (ellapsed < timeout_ms));
	 DEBUG_STREAM << " SerialWin32::nchar_read_string() " << bytes_available << "chars in the buffer " << endl;
	 
	 DEBUG_STREAM <<"serial_ncharreadstring: end of waiting loop"<<endl; 
	 
	 // Check if timeout occured
	 if(bytes_available < nchar)
	 {
		 ERROR_STREAM <<"serial_ncharreadstring:timeout waiting for char to be read"<<endl; 

		 Tango::Except::throw_exception(
			 (const char *)"Serial::error_timeend",
			 (const char *) "timeout waiting for char to be read (sched)",
			 (const char *)"Serial::nchar_read_string");
	 }
	 
	 /*
	 * Empty the receiving buffer
	 */
	 if(ReadFile(serialdevice.hfile, 
					this->serialdevice.buffer, 
					nchar, 
					(DWORD *)&(this->serialdevice.ncharread), 
					&osRead) == FALSE)
		 
	 {
		 ERROR_STREAM <<"serial_ncharreadstring:Error reading data from serial port"<<endl; 
		 
		 Tango::Except::throw_exception(
			 (const char *)"Serial::ReadFile",
			 (const char*) "Error reading data from serial port : ReadFile",
			 (const char *)"Serial::nchar_read_string");
	 }
	 
	 
	for (int i=0; i < nchar ; i++ )
		 DEBUG_STREAM<< "char=  "<< this->serialdevice.buffer[i] ;
	/*
	* Don't forget the string ending char
	*/
	this->serialdevice.buffer[this->serialdevice.ncharread] = 0;
	 
	// Prepare return buffer (can not return "buffer" directly 
	// because TANGO desallocate the memory return)
	argout = new char[this->serialdevice.ncharread + 1];
	 
	if(argout == 0)
	{
		TangoSys_MemStream out_stream;
		out_stream << "unable to allocate memory for the return buffer, need "<< this->serialdevice.ncharread << " bytes" << ends;
		 
		FATAL_STREAM << "Serial::nchar_read_string(): " << out_stream.str() << endl;
		Tango::Except::throw_exception(
			(const char *)"Serial::error_alloc",
			out_stream.str(),
			(const char *)"Serial::nchar_read_string");
	}
	 
	// Do not use strncpy() as raw_read_string() is used by xxx_read_char()
	int i;
	for(i=0 ; i<this->serialdevice.ncharread ; i++)
	argout[i] = this->serialdevice.buffer[i];

	// Add string ending char, used only by ser_read_string()
	argout[i]=0;
	 
	// A RET !
	DEBUG_STREAM << "Serial::nchar_read_string(): nchar=" << this->serialdevice.ncharread << " argout=" << argout << endl;
	 
	return argout;
}

/*============================================================================
Function:      static long dev_status()

Description:   return state of the serialline device as an ASCII string

Arg(s) In:     Serial  ds       - 
				DevVoid  *argin  - none

Arg(s) Out:    DevString *argout - contains string 
============================================================================*/
Tango::ConstDevString Serial::dev_status()
{
DCB				comm_prop;
COMMTIMEOUTS	comm_timeouts;
static  char	str[4096];
Tango::ConstDevString argout;
  
	INFO_STREAM << "dev_status: begin" << endl;
  
	/*
	* Get properties of the serialline (communication device for Windows)
	*/
	if(GetCommState(serialdevice.hfile, &comm_prop) == FALSE)
	{
		ERROR_STREAM <<"serial_ncharreadstring:Error getting serialline props"<<endl; 

	  Tango::Except::throw_exception(
		  (const char *)"Serial::GetCommState",
		  (const char*) "Error getting serialline props : GetCommState",
		  (const char *)"Serial::dev_status");
	}

	if (GetCommTimeouts(serialdevice.hfile, &comm_timeouts) == FALSE)
	{
		ERROR_STREAM <<"serial_ncharreadstring:Error getting timeouts : GetCommTimeouts"<<endl; 

		Tango::Except::throw_exception(
		  (const char *)"Serial::GetCommTimeouts",
		  (const char*) "Error getting timeouts : GetCommTimeouts",
		  (const char *)"Serial::dev_status");
	}
  
  
	strcpy(str,"Current parameters of the serial line:\n");
	sprintf(str, "%s   serialline       : %s\n", 
	  str, serialdevice.serialline);
	sprintf(str, "%s   baudrate         : %d\n", 
	  str,comm_prop.BaudRate);
	sprintf(str, "%s   byte size        : %d\n", 
	  str,comm_prop.ByteSize); 
	sprintf(str, "%s   stop bits        : %d (0-2=1,1.5,2bit)\n", 
	  str,comm_prop.StopBits);
	sprintf(str, "%s   parity           : %d (0-4=no,odd,even,mark,space)\n", 
	  str,comm_prop.Parity);
	sprintf(str, "%s   reading timeout  : %d (mS)\n", 
	  str,comm_timeouts.ReadTotalTimeoutConstant);

	sprintf(str, "%s   fOutxCtsFlow     : %d\n", 
	  str,comm_prop.fOutxCtsFlow);
	sprintf(str, "%s   fOutxDsrFlow     : %d\n", 
	  str,comm_prop.fOutxDsrFlow);
	sprintf(str, "%s   fDtrControl      : %d (%d=dis %d=ena %d=hand)\n", 
	  str,comm_prop.fDtrControl,
	  DTR_CONTROL_DISABLE,
	  DTR_CONTROL_ENABLE,
	  DTR_CONTROL_HANDSHAKE);
	sprintf(str, "%s   fDsrSensitivity  : %d\n", 
	  str,comm_prop.fDsrSensitivity);
	sprintf(str, "%s   fTXContinueOnXoff: %d\n", 
	  str,comm_prop.fTXContinueOnXoff);
	sprintf(str, "%s   fOutX            : %d\n", 
	  str,comm_prop.fOutX);
	sprintf(str, "%s   fInX             : %d\n", 
	  str,comm_prop.fInX);
	sprintf(str, "%s   fRtsControl      : %d (%d=dis %d=ena %d=hand)\n", 
	  str,comm_prop.fRtsControl,
	  RTS_CONTROL_DISABLE,
	  RTS_CONTROL_ENABLE,
	  RTS_CONTROL_HANDSHAKE);
  
  
	/*
	* Add internal parameter values
	*/
	sprintf(str,"%s\nCurrent parameters of the device server:\n", str);
	sprintf(str, "%s   serialline       : %s\n", str, serialdevice.serialline);
	sprintf(str, "%s   timeout          : %d \n", 
	  str, serialdevice.timeout);
	sprintf(str, "%s   parity           : %d (%d=none %d=odd %d=even)\n", 
	  str, serialdevice.parity, NOPARITY, ODDPARITY, EVENPARITY);
	sprintf(str, "%s   charlength       : %d\n", str, serialdevice.charlength);
	sprintf(str, "%s   stopbits         : %d (%d=1bit %d=1.5bits %d=2bits)\n", 
	  str, serialdevice.stopbits, SL_STOP1, SL_STOP15, SL_STOP2);
	sprintf(str, "%s   baudrate         : %d\n", str, serialdevice.baudrate);
	sprintf(str, "%s   newline          : %d\n", str, serialdevice.newline);
	/*
	* Return string
	*/
	argout = str;

	INFO_STREAM << "dev_status: end" << endl;

	return argout;
  
}
