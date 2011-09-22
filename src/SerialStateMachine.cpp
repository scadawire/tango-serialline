/*----- PROTECTED REGION ID(SerialStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id: SerialStateMachine.cpp,v 1.4 2011-09-22 06:11:43 pascal_verdier Exp $";
//=============================================================================
//
// file :        SerialStateMachine.cpp
//
// description : C++ source for the �name� and its alowed
//               methods for commands and attributes
//
// project :     TANGO Device Server.
//
// $Author: pascal_verdier $
//
// $Revision: 1.4 $
// $Date: 2011-09-22 06:11:43 $
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source: /users/chaize/newsvn/cvsroot/Communication/SerialLine/src/SerialStateMachine.cpp,v $
// $Log: not supported by cvs2svn $
// Revision 1.3  2010/12/07 09:08:49  pascal_verdier
// Moved to Pogo-7 code generator.
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================



#include <Serial.h>
#include <SerialClass.h>

/*----- PROTECTED REGION END -----*/


/*
 * Serial states description:
 *
 */

namespace Serial_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================


//=================================================
//	Dynamic Attributes Allowed Methods
//=================================================


	/*----- PROTECTED REGION ID(Serial::are_dynamic_attributes_allowed) ENABLED START -----*/

	//	Add your code to check if dynamic attributes are alowed

	/*----- PROTECTED REGION END -----*/	//	Serial::are_dynamic_attributes_allowed


//=================================================
//		Commands Allowed Methods
//=================================================


//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerWriteStringState_allowed()
 *	Description : Execution allowed for DevSerWriteString command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerWriteString_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerWriteString command.

	/*----- PROTECTED REGION ID(Serial::DevSerWriteStringStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerWriteStringStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerWriteCharState_allowed()
 *	Description : Execution allowed for DevSerWriteChar command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerWriteChar_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerWriteChar command.

	/*----- PROTECTED REGION ID(Serial::DevSerWriteCharStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerWriteCharStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerReadStringState_allowed()
 *	Description : Execution allowed for DevSerReadString command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerReadString_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerReadString command.

	/*----- PROTECTED REGION ID(Serial::DevSerReadStringStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerReadStringStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerReadCharState_allowed()
 *	Description : Execution allowed for DevSerReadChar command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerReadChar_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerReadChar command.

	/*----- PROTECTED REGION ID(Serial::DevSerReadCharStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerReadCharStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_WriteReadState_allowed()
 *	Description : Execution allowed for WriteRead command.
 */
//--------------------------------------------------------

bool Serial::is_WriteRead_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for WriteRead command.

	/*----- PROTECTED REGION ID(Serial::WriteReadStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::WriteReadStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerGetNCharState_allowed()
 *	Description : Execution allowed for DevSerGetNChar command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerGetNChar_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerGetNChar command.

	/*----- PROTECTED REGION ID(Serial::DevSerGetNCharStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerGetNCharStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerReadNCharState_allowed()
 *	Description : Execution allowed for DevSerReadNChar command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerReadNChar_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerReadNChar command.

	/*----- PROTECTED REGION ID(Serial::DevSerReadNCharStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerReadNCharStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerReadRawState_allowed()
 *	Description : Execution allowed for DevSerReadRaw command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerReadRaw_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerReadRaw command.

	/*----- PROTECTED REGION ID(Serial::DevSerReadRawStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerReadRawStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerReadLineState_allowed()
 *	Description : Execution allowed for DevSerReadLine command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerReadLine_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerReadLine command.

	/*----- PROTECTED REGION ID(Serial::DevSerReadLineStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerReadLineStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerFlushState_allowed()
 *	Description : Execution allowed for DevSerFlush command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerFlush_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerFlush command.

	/*----- PROTECTED REGION ID(Serial::DevSerFlushStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerFlushStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerSetParameterState_allowed()
 *	Description : Execution allowed for DevSerSetParameter command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerSetParameter_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerSetParameter command.

	/*----- PROTECTED REGION ID(Serial::DevSerSetParameterStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerSetParameterStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerSetTimeoutState_allowed()
 *	Description : Execution allowed for DevSerSetTimeout command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerSetTimeout_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerSetTimeout command.

	/*----- PROTECTED REGION ID(Serial::DevSerSetTimeoutStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerSetTimeoutStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerSetParityState_allowed()
 *	Description : Execution allowed for DevSerSetParity command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerSetParity_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerSetParity command.

	/*----- PROTECTED REGION ID(Serial::DevSerSetParityStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerSetParityStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerSetCharLengthState_allowed()
 *	Description : Execution allowed for DevSerSetCharLength command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerSetCharLength_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerSetCharLength command.

	/*----- PROTECTED REGION ID(Serial::DevSerSetCharLengthStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerSetCharLengthStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerSetStopbitState_allowed()
 *	Description : Execution allowed for DevSerSetStopbit command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerSetStopbit_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerSetStopbit command.

	/*----- PROTECTED REGION ID(Serial::DevSerSetStopbitStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerSetStopbitStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerSetBaudrateState_allowed()
 *	Description : Execution allowed for DevSerSetBaudrate command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerSetBaudrate_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerSetBaudrate command.

	/*----- PROTECTED REGION ID(Serial::DevSerSetBaudrateStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerSetBaudrateStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerSetNewlineState_allowed()
 *	Description : Execution allowed for DevSerSetNewline command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerSetNewline_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerSetNewline command.

	/*----- PROTECTED REGION ID(Serial::DevSerSetNewlineStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerSetNewlineStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerReadRetryState_allowed()
 *	Description : Execution allowed for DevSerReadRetry command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerReadRetry_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerReadRetry command.

	/*----- PROTECTED REGION ID(Serial::DevSerReadRetryStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerReadRetryStateAllowed

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Serial::is_DevSerReadNBinDataState_allowed()
 *	Description : Execution allowed for DevSerReadNBinData command.
 */
//--------------------------------------------------------

bool Serial::is_DevSerReadNBinData_allowed(const CORBA::Any &any)
{
	//	Not any excluded states for DevSerReadNBinData command.

	/*----- PROTECTED REGION ID(Serial::DevSerReadNBinDataStateAllowed) ENABLED START -----*/

	/*----- PROTECTED REGION END -----*/	//	Serial::DevSerReadNBinDataStateAllowed

	return true;
}


	/*----- PROTECTED REGION ID(Serial::are_dynamic_commands_allowed) ENABLED START -----*/

	//	Add your code to check if dynamic commands are alowed

	/*----- PROTECTED REGION END -----*/	//	Serial::are_dynamic_commands_allowed

}	// namespace Serial_ns
