
static const char *RcsId = "$Header: /users/chaize/newsvn/cvsroot/Communication/SerialLine/src/SerialClass.cpp,v 1.6 2005-05-12 08:24:49 xavela Exp $";

static const char *TagName = "$Name: not supported by cvs2svn $";

static const char *FileName= "$Source: /users/chaize/newsvn/cvsroot/Communication/SerialLine/src/SerialClass.cpp,v $"; 

static const char *HttpServer= "http://controle/DeviceServer/doc/";

static const char *RCSfile = "$RCSfile: SerialClass.cpp,v $"; 

//+=============================================================================
//
// file :        SerialClass.cpp
//
// description : C++ source for the SerialClass. A singleton
//               class derived from DeviceClass. It implements the
//               command list and all properties and methods required
//               by the Serial once per process.
//
// project :     TANGO Device Server
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
//
// copyleft :   European Synchrotron Radiation Facility
//              BP 220, Grenoble 38043
//              FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


#include <tango.h>

#include <Serial.h>
#include <SerialClass.h>


namespace Serial_ns
{
//+----------------------------------------------------------------------------
//
// method : 		DevSerReadRetryCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerReadRetryCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerReadRetryCmd::execute(): arrived" << endl;

	Tango::DevLong	argin;
	extract(in_any, argin);

	return insert((static_cast<Serial *>(device))->dev_ser_read_retry(argin));
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerSetNewlineCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerSetNewlineCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerSetNewlineCmd::execute(): arrived" << endl;

	Tango::DevShort	argin;
	extract(in_any, argin);

	((static_cast<Serial *>(device))->dev_ser_set_newline(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerSetBaudrateCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerSetBaudrateCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerSetBaudrateCmd::execute(): arrived" << endl;

	Tango::DevULong	argin;
	extract(in_any, argin);

	((static_cast<Serial *>(device))->dev_ser_set_baudrate(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerSetStopbitCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerSetStopbitCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerSetStopbitCmd::execute(): arrived" << endl;

	Tango::DevShort	argin;
	extract(in_any, argin);

	((static_cast<Serial *>(device))->dev_ser_set_stopbit(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerSetCharLengthCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerSetCharLengthCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerSetCharLengthCmd::execute(): arrived" << endl;

	Tango::DevShort	argin;
	extract(in_any, argin);

	((static_cast<Serial *>(device))->dev_ser_set_char_length(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerSetParityCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerSetParityCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerSetParityCmd::execute(): arrived" << endl;

	Tango::DevShort	argin;
	extract(in_any, argin);

	((static_cast<Serial *>(device))->dev_ser_set_parity(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerSetTimeoutCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerSetTimeoutCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerSetTimeoutCmd::execute(): arrived" << endl;

	Tango::DevShort	argin;
	extract(in_any, argin);

	((static_cast<Serial *>(device))->dev_ser_set_timeout(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerReadLineCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerReadLineCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerReadLineCmd::execute(): arrived" << endl;

	return insert((static_cast<Serial *>(device))->dev_ser_read_line());
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerReadRawCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerReadRawCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerReadRawCmd::execute(): arrived" << endl;

	return insert((static_cast<Serial *>(device))->dev_ser_read_raw());
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerReadNCharCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerReadNCharCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerReadNCharCmd::execute(): arrived" << endl;

	Tango::DevLong	argin;
	extract(in_any, argin);

	return insert((static_cast<Serial *>(device))->dev_ser_read_nchar(argin));
}

//+----------------------------------------------------------------------------
//
// method : 		WriteReadCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *WriteReadCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "WriteReadCmd::execute(): arrived" << endl;

	const Tango::DevVarLongStringArray	*argin;
	extract(in_any, argin);

	return insert((static_cast<Serial *>(device))->write_read(argin));
}



//+----------------------------------------------------------------------------
//
// method : 		DevSerWriteStringCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerWriteStringCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerWriteStringCmd::execute(): arrived" << endl;

	Tango::DevString	argin;
	extract(in_any, argin);

	return insert((static_cast<Serial *>(device))->dev_ser_write_string(argin));
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerWriteCharCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerWriteCharCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerWriteCharCmd::execute(): arrived" << endl;

	const Tango::DevVarCharArray	*argin;
	extract(in_any, argin);

	return insert((static_cast<Serial *>(device))->dev_ser_write_char(argin));
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerSetParameterCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerSetParameterCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerSetParameterCmd::execute(): arrived" << endl;

	const Tango::DevVarLongArray	*argin;
	extract(in_any, argin);

	((static_cast<Serial *>(device))->dev_ser_set_parameter(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerFlushCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerFlushCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerFlushCmd::execute(): arrived" << endl;

	Tango::DevLong	argin;
	extract(in_any, argin);

	((static_cast<Serial *>(device))->dev_ser_flush(argin));
	return new CORBA::Any();
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerReadStringCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerReadStringCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerReadStringCmd::execute(): arrived" << endl;

	Tango::DevLong	argin;
	extract(in_any, argin);

	return insert((static_cast<Serial *>(device))->dev_ser_read_string(argin));
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerReadCharCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerReadCharCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerReadCharCmd::execute(): arrived" << endl;

	Tango::DevLong	argin;
	extract(in_any, argin);

	return insert((static_cast<Serial *>(device))->dev_ser_read_char(argin));
}

//+----------------------------------------------------------------------------
//
// method : 		DevSerGetNCharCmd::execute()
// 
// description : 	method to trigger the execution of the command.
//                PLEASE DO NOT MODIFY this method core without pogo   
//
// in : - device : The device on which the command must be excuted
//		- in_any : The command input data
//
// returns : The command output data (packed in the Any object)
//
//-----------------------------------------------------------------------------
CORBA::Any *DevSerGetNCharCmd::execute(Tango::DeviceImpl *device,const CORBA::Any &in_any)
{

	cout2 << "DevSerGetNCharCmd::execute(): arrived" << endl;

	return insert((static_cast<Serial *>(device))->dev_ser_get_nchar());
}

//
//----------------------------------------------------------------
//	Initialize pointer for singleton pattern
//----------------------------------------------------------------
//
SerialClass *SerialClass::_instance = NULL;

//+----------------------------------------------------------------------------
//
// method : 		SerialClass::SerialClass(string &s)
// 
// description : 	constructor for the SerialClass
//
// in : - s : The class name
//
//-----------------------------------------------------------------------------
SerialClass::SerialClass(string &s):DeviceClass(s)
{

	cout2 << "Entering SerialClass constructor" << endl;
	write_class_property();
	
	cout2 << "Leaving SerialClass constructor" << endl;

}
//+----------------------------------------------------------------------------
//
// method : 		SerialClass::~SerialClass()
// 
// description : 	destructor for the SerialClass
//
//-----------------------------------------------------------------------------
SerialClass::~SerialClass()
{
	_instance = NULL;
}

//+----------------------------------------------------------------------------
//
// method : 		SerialClass::instance
// 
// description : 	Create the object if not already done. Otherwise, just
//			return a pointer to the object
//
// in : - name : The class name
//
//-----------------------------------------------------------------------------
SerialClass *SerialClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new SerialClass(s);
		}
		catch (bad_alloc)
		{
			throw;
		}		
	}		
	return _instance;
}

SerialClass *SerialClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}

//+----------------------------------------------------------------------------
//
// method : 		SerialClass::command_factory
// 
// description : 	Create the command object(s) and store them in the 
//			command list
//
//-----------------------------------------------------------------------------
void SerialClass::command_factory()
{
	command_list.push_back(new DevSerWriteStringCmd("DevSerWriteString",
		Tango::DEV_STRING, Tango::DEV_LONG,
		"String to write",
		"Number of characters written",
		Tango::OPERATOR));
	command_list.push_back(new DevSerWriteCharCmd("DevSerWriteChar",
		Tango::DEVVAR_CHARARRAY, Tango::DEV_LONG,
		"Characters to write",
		"Number of characters written",
		Tango::OPERATOR));
	command_list.push_back(new DevSerReadStringCmd("DevSerReadString",
		Tango::DEV_LONG, Tango::DEV_STRING,
		"type of read SL_RAW SL_NCHAR SL_LINE",
		"String read",
		Tango::OPERATOR));
	command_list.push_back(new DevSerReadCharCmd("DevSerReadChar",
		Tango::DEV_LONG, Tango::DEVVAR_CHARARRAY,
		"type of read SL_RAW SL_NCHAR SL_LINE",
		"Array of characters read",
		Tango::OPERATOR));
	command_list.push_back(new WriteReadCmd("WriteRead",
		Tango::DEVVAR_LONGSTRINGARRAY, Tango::DEV_STRING,
		"type of reading strategy(RAW,NCHAR..),command to write on the port com",
		"response of the device behind the serial line",
		Tango::OPERATOR));
	command_list.push_back(new DevSerGetNCharCmd("DevSerGetNChar",
		Tango::DEV_VOID, Tango::DEV_LONG,
		"no argin",
		"number of char available in receiving buffer",
		Tango::OPERATOR));
	command_list.push_back(new DevSerReadNCharCmd("DevSerReadNChar",
		Tango::DEV_LONG, Tango::DEV_STRING,
		"number of the caracters to read on the serial line",
		"pointer to the string read updated",
		Tango::OPERATOR));
	command_list.push_back(new DevSerReadRawCmd("DevSerReadRaw",
		Tango::DEV_VOID, Tango::DEV_STRING,
		"no argin",
		"pointer to the string read updated",
		Tango::OPERATOR));
	command_list.push_back(new DevSerReadLineCmd("DevSerReadLine",
		Tango::DEV_VOID, Tango::DEV_STRING,
		"no argin",
		"pointer to the string read updated",
		Tango::OPERATOR));
	command_list.push_back(new DevSerFlushCmd("DevSerFlush",
		Tango::DEV_LONG, Tango::DEV_VOID,
		"flush to do 0=input 1=output 2=both",
		"no argout",
		Tango::OPERATOR));
	command_list.push_back(new DevSerSetParameterCmd("DevSerSetParameter",
		Tango::DEVVAR_LONGARRAY, Tango::DEV_VOID,
		"device parameters in pair",
		"no argout",
		Tango::OPERATOR));
	command_list.push_back(new DevSerSetTimeoutCmd("DevSerSetTimeout",
		Tango::DEV_SHORT, Tango::DEV_VOID,
		"Value of the timeout to set",
		"no argout",
		Tango::OPERATOR));
	command_list.push_back(new DevSerSetParityCmd("DevSerSetParity",
		Tango::DEV_SHORT, Tango::DEV_VOID,
		"The new parity to set.",
		"no argout",
		Tango::OPERATOR));
	command_list.push_back(new DevSerSetCharLengthCmd("DevSerSetCharLength",
		Tango::DEV_SHORT, Tango::DEV_VOID,
		"The new charlength to set",
		"no argout",
		Tango::OPERATOR));
	command_list.push_back(new DevSerSetStopbitCmd("DevSerSetStopbit",
		Tango::DEV_SHORT, Tango::DEV_VOID,
		"The new stopbit to set",
		"no argout",
		Tango::OPERATOR));
	command_list.push_back(new DevSerSetBaudrateCmd("DevSerSetBaudrate",
		Tango::DEV_ULONG, Tango::DEV_VOID,
		"The new baudrate to set",
		"no argout",
		Tango::OPERATOR));
	command_list.push_back(new DevSerSetNewlineCmd("DevSerSetNewline",
		Tango::DEV_SHORT, Tango::DEV_VOID,
		"The new line character to set",
		"no argout",
		Tango::OPERATOR));
	command_list.push_back(new DevSerReadRetryCmd("DevSerReadRetry",
		Tango::DEV_LONG, Tango::DEV_STRING,
		"number of reading retries",
		"pointer to the string read updated",
		Tango::OPERATOR));

	//	add polling if any
	for (unsigned int i=0 ; i<command_list.size(); i++)
	{
	}
}

//+----------------------------------------------------------------------------
//
// method : 		SerialClass::get_class_property
// 
// description : 	Get the class property for specified name.
//
// in :		string	name : The property name
//
//+----------------------------------------------------------------------------
Tango::DbDatum SerialClass::get_class_property(string &name)
{
	for (int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == name)
			return cl_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(name);
}
//+----------------------------------------------------------------------------
//
// method : 		SerialClass::device_factory
// 
// description : 	Create the device object(s) and store them in the 
//			device list
//
// in :		Tango::DevVarStringArray *devlist_ptr : The device name list
//
//-----------------------------------------------------------------------------
void SerialClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{

	//	Create all devices.(Automatic code generation)
	//-------------------------------------------------------------
	for (unsigned long i=0 ; i < devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
						
		// Create devices and add it into the device list
		//----------------------------------------------------
		device_list.push_back(new Serial(this, (*devlist_ptr)[i]));							 

		// Export device to the outside world
		// Check before if database used.
		//---------------------------------------------
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(device_list.back());
		else
			export_device(device_list.back(), (*devlist_ptr)[i]);
	}
	//	End of Automatic code generation
	//-------------------------------------------------------------

}
//+----------------------------------------------------------------------------
//
// method : 		SerialClass::write_class_property
// 
// description : 	Set class description as property in database
//
//-----------------------------------------------------------------------------
void SerialClass::write_class_property()
{
	//	First time, check if database used
	//--------------------------------------------
	if (Tango::Util::_UseDb == false)
		return;

	//	Prepeare DbDatum
	//--------------------------------------------
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("TANGO Device Server");
	title << str_title;

	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("C++ source for the SerialClass");
	description << str_desc;
	
		// Use the doc_url field to store all information 
		// on the server version and CVS 
		string::size_type pos, len; 
		
		// 1) Manage module name  
		//  get rid of the $RCSfile:  prefix and of Class.cpp suffix 
		string classname = RCSfile;
		
		pos = classname.find("$RCSfile: ");
		len = classname.length();
		
		if (pos != string::npos) 
			classname= classname.substr(pos+10, len- pos-10); 

		pos = classname.find ("Class.cpp",0);
		if (pos != string::npos) 
			classname=classname.substr(0,pos);
		
		// 2)  Manage version number with SOLEIL CVS rules 
		// tag name is in the form : release_1_0 ==> transform it to 1.0
		// 
		string version ; 
		string str_TagName=string(TagName); 
		
		pos = str_TagName.find_first_of("_",0); 
		if (pos != string::npos) 
			version= str_TagName.substr(pos+1, 3);

		pos = version.find_first_of("_",0); 
		if (pos != string::npos) 
			version[pos] = '.';

		
	//  Store all info in the str_url property		
		
		string	str_url=  "Documentation URL = " + string(HttpServer) + classname +"-" + version + "/index.html" + "\n";
		str_url= str_url + " Version CVS Tag = " + string(TagName)+ "\n"; 
		str_url= str_url + " CVS location = " + string(FileName)+ "\n"; 
		
		Tango::DbDatum	doc_url("doc_url");
		
		doc_url << str_url;

		// Push everything in DataBase

		Tango::DbData	data;
		data.push_back(title);
		data.push_back(description);
		data.push_back(doc_url);
		//	Call database and and values
		//--------------------------------------------
		get_db_class()->put_property(data);
}

}	// namespace
