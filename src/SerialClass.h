//=============================================================================
//
// file :         SerialClass.h
//
// description :  Include for the SerialClass root class.
//                This class is represents the singleton class for
//                the Serial device class.
//                It contains all properties and methods which the 
//                Serial requires only once e.g. the commands.
//			
// project :      TANGO Device Server
//
// $Author: xavela $
//
// $Revision: 1.3 $
//
// $Log: not supported by cvs2svn $
// Revision 1.2  2004/06/30 09:22:48  xavela
// xavier : ajout de la methode dev_ser_read_nretry()
// pour la partie win32
//
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifndef _SERIALCLASS_H
#define _SERIALCLASS_H

#include <tango.h>


namespace Serial
{
//
// Define classes for commands
//
class DevSerReadRetryCmd : public Tango::Command
{
public:
	DevSerReadRetryCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerReadRetryCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerReadRetryCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerSetNewlineCmd : public Tango::Command
{
public:
	DevSerSetNewlineCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerSetNewlineCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerSetNewlineCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerSetBaudrateCmd : public Tango::Command
{
public:
	DevSerSetBaudrateCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerSetBaudrateCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerSetBaudrateCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerSetStopbitCmd : public Tango::Command
{
public:
	DevSerSetStopbitCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerSetStopbitCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerSetStopbitCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerSetCharLengthCmd : public Tango::Command
{
public:
	DevSerSetCharLengthCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerSetCharLengthCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerSetCharLengthCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerSetParityCmd : public Tango::Command
{
public:
	DevSerSetParityCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerSetParityCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerSetParityCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerSetTimeoutCmd : public Tango::Command
{
public:
	DevSerSetTimeoutCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerSetTimeoutCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerSetTimeoutCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerSetParameterCmd : public Tango::Command
{
public:
	DevSerSetParameterCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerSetParameterCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerSetParameterCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerFlushCmd : public Tango::Command
{
public:
	DevSerFlushCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerFlushCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerFlushCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerReadLineCmd : public Tango::Command
{
public:
	DevSerReadLineCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerReadLineCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerReadLineCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerReadRawCmd : public Tango::Command
{
public:
	DevSerReadRawCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerReadRawCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerReadRawCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerReadNCharCmd : public Tango::Command
{
public:
	DevSerReadNCharCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerReadNCharCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerReadNCharCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerGetNCharCmd : public Tango::Command
{
public:
	DevSerGetNCharCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerGetNCharCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerGetNCharCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class WriteReadCmd : public Tango::Command
{
public:
	WriteReadCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	WriteReadCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~WriteReadCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerReadCharCmd : public Tango::Command
{
public:
	DevSerReadCharCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerReadCharCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerReadCharCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerReadStringCmd : public Tango::Command
{
public:
	DevSerReadStringCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerReadStringCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerReadStringCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerWriteCharCmd : public Tango::Command
{
public:
	DevSerWriteCharCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerWriteCharCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerWriteCharCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};


class DevSerWriteStringCmd : public Tango::Command
{
public:
	DevSerWriteStringCmd(const char *,Tango::CmdArgType, Tango::CmdArgType,const char *,const char *, Tango::DispLevel);
	DevSerWriteStringCmd(const char *,Tango::CmdArgType, Tango::CmdArgType);
	~DevSerWriteStringCmd() {};
	
	virtual bool is_allowed (Tango::DeviceImpl *, const CORBA::Any &);
	virtual CORBA::Any *execute (Tango::DeviceImpl *, const CORBA::Any &);
};



//
// The SerialClass singleton definition
//

class SerialClass : public Tango::DeviceClass
{
public:

//	add your own data members here
//------------------------------------

public:

//	Method prototypes
	static SerialClass *init(const char *);
	static SerialClass *instance();
	~SerialClass();
	
protected:
	SerialClass(string &);
	static SerialClass *_instance;
	void command_factory();
	void write_class_property();

private:
	void device_factory(const Tango::DevVarStringArray *);
};


}	//	namespace Serial

#endif // _SERIALCLASS_H
